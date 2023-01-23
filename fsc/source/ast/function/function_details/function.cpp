#include "ast/function/function.hpp"
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
            (other.classId == 0 && getMagicType() == MagicFunctionType::INIT);

        const auto first_arguments_equal = std::ranges::equal(
            arguments.cbegin(), arguments.cend(), other.arguments.cbegin(),
            other.arguments.cbegin() + ccl::as<std::ptrdiff_t>(arguments.size()));

        if (!first_arguments_equal) {
            return false;
        }

        auto arguments_equal = first_arguments_equal;

        if (std::size(other.arguments) > arguments.size()) {
            arguments_equal = endsWithParameterPack;
        }

        const auto have_similar_names = name == other.name;
        const auto have_similar_class_id = classId == other.classId;

        return arguments_equal && have_similar_names && (have_similar_class_id || is_constructor);
    }

    auto Function::analyze() const -> void
    {
        defaultAnalyze();
    }

    auto Function::defaultAnalyze() const -> void
    {
        if (templates.empty()) {
            functionBody->analyze();
        }
    }

    auto Function::analyzeOnCall(const SmallVector<NodePtr> &function_arguments) const -> void
    {
        auto remap_types = SmallVector<Id>{};

        for (size_t i = 0; i != arguments.size(); ++i) {
            const auto argument_type = arguments[i].getType();

            if (FscType::isTemplate(argument_type)) {
                remap_types.emplace_back(argument_type);
                FscType::remapType(argument_type, function_arguments[i]->getValueType());
            }
        }

        functionBody->analyze();

        for (const auto remap_type : remap_types) {
            FscType::removeRemap(remap_type);
        }
    }

    auto Function::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Function: {}\n", getPrintingPrefix(prefix, is_left), name);
        functionBody->print(expandPrefix(prefix, is_left));
    }

    auto Function::argumentToString(codegen::BasicCodeGenerator &output, const Argument &arg) const
        -> void
    {
        const auto &argument_name = arg.getName();
        output << arg;

        if (defaultArguments.contains(argument_name)) {
            output << " = " << *defaultArguments.at(argument_name);
        }
    }

    auto Function::setReturnType(const std::vector<antlr4::tree::ParseTree *> &nodes) -> void
    {
        auto length = nodes.size();

        if (nodes.at(length - 4)->getText() == "->") {
            const auto type_name = nodes[length - 3]->getText();

            FscType::ensureTypeExists(type_name);
            returnType = FscType::getTypeId(type_name);
        } else {
            returnType = Auto::typeId;
        }
    }

    auto Function::processAttributes(FunctionAttributeContext *ctx) -> void
    {
        if (ctx->visibility() != nullptr) {
            visibility = VisibilityByStr.at(ctx->visibility()->getText());
        }
    }

    auto Function::defineArgument(const FscParser::Argument_definitionContext *argument_definition)
        -> Argument
    {
        const auto &children = argument_definition->children;

        const auto category = children.at(0)->getText();
        const auto type_name = children.at(1)->getText();
        const auto arg_name = children.at(2)->getText();

        FscType::ensureTypeExists(type_name);

        return {arg_name, FscType::getTypeId(type_name), ArgumentCategories.at(category)};
    }

    auto Function::getReturnTypeAsString() const -> std::string
    {
        if (returnType.index() == 0) {
            return FscType::getTypeName(std::get<0>(returnType));
        }

        return std::get<1>(returnType);
    }

    auto Function::getReturnType() const -> ccl::Id
    {
        if (returnType.index() == 0) {
            return std::get<0>(returnType);
        }

        const auto &type_name = std::get<1>(returnType);

        if (!FscType::exists(type_name)) {
            throw std::runtime_error("Return type of the template function is not known yet.");
        }

        return FscType::getTypeId(type_name);
    }
}// namespace fsc::ast
