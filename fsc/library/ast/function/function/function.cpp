#include "ast/function/function.hpp"
#include "ast/value/variable.hpp"
#include "function/argument.hpp"
#include "type/builtin_types.hpp"
#include "visibility.hpp"
#include <ccl/join.hpp>
#include <Parser.h>

using namespace ccl;
using namespace std::string_view_literals;

namespace fsc::ast
{
    static auto argumentToPrettyString(const Argument &arg) -> std::string
    {
        return fmt::format("{} {} {}", arg.getCategory(), arg.getType(), arg.getName());
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
            throw FscException{fmt::format("function arguments do not match")};
        }
    }

    auto Function::getReportOfUserDefinedFunction() -> AnalysisReport
    {
        if (magicType == MagicFunctionType::INIT) {
            return analyzeClassAfterConstruction();
        }

        return analyzeFunctionAfterTemplatesRemap();
    }

    auto Function::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Function: {}; ", getPrintingPrefix(prefix, is_left), name);

        if (!arguments.empty()) {
            fmt::print("arguments: {}; ", ccl::join(arguments, argumentToPrettyString, ", "));
        }

        fmt::print("noexcept: {}; constexpr: {}\n", functionInfo.NOEXCEPT, functionInfo.CONSTEXPR);

        if (functionBody != nullptr) {
            functionBody->print(expandPrefix(prefix, is_left));
        }
    }

    auto Function::argumentToString(const Argument &arg) const -> std::string
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
