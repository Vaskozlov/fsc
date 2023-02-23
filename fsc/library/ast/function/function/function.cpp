#include "ast/function/function.hpp"
#include "ast/container/class.hpp"
#include "ast/value/variable.hpp"
#include "function/argument.hpp"
#include "type/builtin_types.hpp"
#include "type/type.hpp"
#include "visibility.hpp"
#include <fmt/ranges.h>
#include <functional>
#include <Parser.h>
#include <ranges>

using namespace ccl;
using namespace std::string_view_literals;

namespace fsc::ast
{
    auto Function::operator==(SignatureView other) const noexcept -> bool
    {
        if (arguments.size() > std::size(other.arguments)) {
            return false;
        }

        const auto is_constructor =
            (other.classType == Void && getMagicType() == MagicFunctionType::INIT);

        const auto argument_before_parameter_pack_equal = std::ranges::equal(
            arguments.cbegin(), arguments.cend(), other.arguments.cbegin(),
            other.arguments.cbegin() + ccl::as<std::ptrdiff_t>(arguments.size()));

        if (!argument_before_parameter_pack_equal) {
            return false;
        }

        auto arguments_equal = argument_before_parameter_pack_equal;

        if (std::size(other.arguments) > arguments.size()) {
            arguments_equal = functionInfo.HAVE_PARAMETER_PACK;
        }

        if (!arguments_equal) {
            return false;
        }

        const auto have_similar_names = name == other.name;
        const auto have_similar_class_id = classType == other.classType;

        return have_similar_names && (have_similar_class_id || is_constructor);
    }

    auto Function::analyze() -> void
    {
        Function::defaultAnalyze();
    }

    auto Function::defaultAnalyze() const -> void
    {
        if (templates.empty()) {
            functionBody->analyze();
        }
    }

    auto Function::analyzeOnCall(
        const SmallVector<NodePtr> &function_arguments,
        const ccl::SmallVector<FscType> &on_call_templates) -> FscType
    {
        auto remap_types_names = SmallVector<std::string>{};
        auto remap_types_lock = SmallVector<AcquireTypeMapType>{};

        mapExplicitTemplates(remap_types_names, remap_types_lock, on_call_templates);
        mapImplicitTemplates(remap_types_names, remap_types_lock, function_arguments);
        checkFunctionArgumentAfterDeductionMatch(
            function_arguments);// TODO: check this before finding function

        if (magicType == MagicFunctionType::INIT && !functionInfo.BUILTIN_FUNCTION) {
            analyzeClassAfterConstruction();
        } else if (!functionInfo.BUILTIN_FUNCTION) {
            analyzeFunctionAfterTemplatesRemap();
        }

        return deduceReturnType(remap_types_names);
    }

    auto Function::mapExplicitTemplates(
        SmallVector<std::string> &remap_types_names,
        SmallVector<AcquireTypeMapType> &remap_types_lock,
        const ccl::SmallVector<FscType> &on_call_templates) -> void
    {
        auto explicit_templates_to_remap = std::min(templates.size(), on_call_templates.size());

        for (auto i = 0ZU; i != explicit_templates_to_remap; ++i) {
            remap_types_lock.emplace_back(
                TypeManager::acquireTypeMap(templates[i], on_call_templates[i]));
            remap_types_names.emplace_back(TypeManager::getTypename(templates[i]));
        }
    }

    auto Function::mapImplicitTemplates(
        ccl::SmallVector<std::string> &remap_types_names,
        ccl::SmallVector<AcquireTypeMapType> &remap_types_lock,
        const SmallVector<NodePtr> &function_arguments) -> void
    {
        for (auto i = 0ZU; i != arguments.size(); ++i) {
            const auto argument_type = arguments.at(i).getType();

            if (argument_type.isTemplate() && !argument_type.isRemapTemplate()) {
                remap_types_lock.emplace_back(TypeManager::acquireTypeMap(
                    argument_type, function_arguments.at(i)->getValueType()));
                remap_types_names.emplace_back(TypeManager::getTypename(argument_type));
            }
        }
    }

    auto Function::checkFunctionArgumentAfterDeductionMatch(
        const SmallVector<NodePtr> &function_arguments) const noexcept(false) -> void
    {
        if (!std::ranges::equal(
                arguments.begin(), arguments.end(), function_arguments.begin(),
                function_arguments.begin() + ccl::as<long>(arguments.size()),
                [](auto lhs, auto rhs) {
                    return lhs == rhs->getValueType();
                })) {
            throw FscException{fmt::format("function argument do not match")};
        }
    }

    auto Function::analyzeClassAfterConstruction() -> void
    {
        const auto &class_node = classType.getClass();
        const auto &fsc_class = class_node->as<ast::Class>();
        fsc_class.analyzeOnConstruction();
    }

    auto Function::analyzeFunctionAfterTemplatesRemap() -> void
    {
        if (!templates.empty()) {
            completeBody(*visitorPtr);
        }

        functionBody->analyze();
    }

    auto Function::deduceReturnType(const SmallVector<std::string> &remap_types_names) const
        -> FscType
    {
        auto returned_type = getReturnType();

        if (magicType == MagicFunctionType::INIT && !remap_types_names.empty()) {
            returned_type =
                FscType{fmt::format("{}<{}>", name, fmt::join(remap_types_names, ", "))};
        }

        return returned_type;
    }

    auto Function::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Function: {}\n", getPrintingPrefix(prefix, is_left), name);

        if (functionBody != nullptr) {
            functionBody->print(expandPrefix(prefix, is_left));
        }
    }

    auto Function::argumentToString(Argument &arg) const -> std::string
    {
        auto tmp_codegen = codegen::BasicCodeGenerator{};
        const auto &argument_name = arg.getName();
        tmp_codegen << arg;

        if (defaultArguments.contains(argument_name)) {
            tmp_codegen << " = " << *defaultArguments.at(argument_name);
        }

        return tmp_codegen.getCode();
    }

    auto Function::setReturnType(const std::vector<antlr4::tree::ParseTree *> &nodes) -> void
    {
        auto length = nodes.size();

        if (nodes.at(length - 4)->getText() == "->") {
            const auto type_name = nodes[length - 3]->getText();

            TypeManager::ensureTypeExists(type_name);
            returnType = FscType{type_name};
        } else {
            returnType = Auto;
        }
    }

    auto Function::processAttributes(FunctionAttributeContext *ctx) -> void
    {
        if (ctx->visibility() != nullptr) {
            functionInfo.VISIBILITY = VisibilityByStr.at(ctx->visibility()->getText());
        }
    }

    auto Function::defineArgument(const FscParser::Argument_definitionContext *argument_definition)
        -> Argument
    {
        const auto &children = argument_definition->children;

        const auto category = children.at(0)->getText();
        const auto type_name = children.at(1)->getText();
        const auto arg_name = children.at(2)->getText();

        TypeManager::ensureTypeExists(type_name);

        return {arg_name, FscType{type_name}, ArgumentCategories.at(category)};
    }

    auto Function::getReturnType() const -> FscType
    {
        if (magicType == MagicFunctionType::INIT && !templates.empty()) {
            return FscType{fmt::format("{}<{}>", name, fmt::join(templates, ", "))};
        }

        return returnType;
    }
}// namespace fsc::ast
