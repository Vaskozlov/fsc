#include "ast/expression/binary_operator.hpp"
#include "function/argument.hpp"
#include "function/functions_holder.hpp"
#include <ccl/flatmap.hpp>
#include <exception>
#include <ranges>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    constexpr static ccl::StaticFlatmap<std::string_view, std::string_view, 13>
        OperatorToFunctionName = {
            {"+", "__add__"},          {"-", "__sub__"},         {"*", "__mul__"},
            {"/", "__div__"},          {"%", "__mod__"},         {"<", "__less__"},
            {">", "__greater__"},      {"<=", "__less_equal__"}, {">", "__greater_equal__"},
            {"&&", "__logical_and__"}, {"==", "__equal__"},      {"!=", "__not_equal__"},
            {"=", "__copy__"}};

    BinaryOperation::BinaryOperation(
        FscParser::ExprContext *ctx,
        std::string operation_type,
        NodePtr left_node,
        NodePtr right_node)
      : NodeWrapper{ccl::as<BasicContextPtr>(ctx)}
      , lhs{std::move(left_node)}
      , rhs{std::move(right_node)}
      , operationType{std::move(operation_type)}
    {
        setStart(ctx->start);
        setStop(ctx->stop);
    }

    auto BinaryOperation::getValueType() -> FscType
    {
        const auto function_name = OperatorToFunctionName.at(operationType);

        return func::Functions.visitFunction(
            {std::string{function_name}, {Argument{lhs.get()}, Argument{rhs.get()}}, Void},
            std::mem_fn(&Function::getReturnType));
    }

    auto BinaryOperation::analyze() -> void
    {
        try {
            [[maybe_unused]] auto make_sure_that_binary_function_exists = getValueType();
        } catch (const FscException &exception) {
            reportAboutError(exception);
        }
    }

    auto BinaryOperation::codeGen(ccl::codegen::BasicCodeGenerator &output) -> void
    {
        output << *lhs << " " << operationType << " " << *rhs;
    }

    auto BinaryOperation::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), operationType);

        lhs->print(expanded_prefix, true);
        rhs->print(expanded_prefix, false);
    }
}// namespace fsc::ast
