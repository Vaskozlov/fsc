#include "ast/expression/binary_operator.hpp"
#include "ast/value/value.hpp"
#include "function/argument.hpp"
#include "function/functions_holder.hpp"
#include <ccl/flatmap.hpp>
#include <ranges>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    constexpr static ccl::StaticFlatmap<std::string_view, std::string_view, 18>
        OperatorToFunctionName = {
            {"+", "__add__"},         {"-", "__sub__"},           {"*", "__mul__"},
            {"/", "__div__"},         {"%", "__mod__"},           {"+=", "__iadd__"},
            {"-=", "__isub__"},       {"*=", "__imul__"},         {"/=", "__idiv__"},
            {"%=", "__imod__"},       {"<", "__less__"},          {">", "__greater__"},
            {"<=", "__less_equal__"}, {">", "__greater_equal__"}, {"&&", "__logical_and__"},
            {"==", "__equal__"},      {"!=", "__not_equal__"},    {"=", "__copy__"}};

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
        return getFunction()->getReturnType();
    }

    auto BinaryOperation::getFunction() const -> ccl::SharedPtr<ast::Function>
    {
        const auto function_name = OperatorToFunctionName.at(operationType);

        return preparerToCatchError(
            [this, &function_name]() {
                return func::Functions.get(
                    {std::string{function_name}, {Argument{lhs.get()}, Argument{rhs.get()}}, Void});
            },
            *this);
    }

    auto BinaryOperation::analyze() -> AnalysisReport
    {
        return preparerToCatchError(
            [this]() {
                auto function = getFunction();
                const auto &function_arguments = function->getArguments();
                auto [return_type, report] = function->analyzeOnCall({lhs, rhs}, {});

                switch (function_arguments.at(0).getCategory()) {
                case ArgumentCategory::IN:
                    report.addToRead(lhs);
                    break;

                case ArgumentCategory::OUT:
                case ArgumentCategory::INOUT:
                    report.addToModified(lhs);
                    break;

                default:
                    ccl::unreachable();
                }

                switch (function_arguments.at(1).getCategory()) {
                case ArgumentCategory::IN:
                    report.addToRead(rhs);
                    break;

                case ArgumentCategory::OUT:
                case ArgumentCategory::INOUT:
                    report.addToModified(rhs);
                    break;

                default:
                    ccl::unreachable();
                }

                return report;
            },
            *this);
    }

    auto BinaryOperation::codeGen(ccl::codegen::BasicCodeGenerator &output) -> void
    {
        output << *lhs << " " << operationType << " " << *rhs;
    }

    auto BinaryOperation::optimize(OptimizationLevel level) -> void
    {
        lhs->optimize(level);

        if (auto lhs_eval_result = lhs->eval(); lhs_eval_result.has_value()) {
            lhs = *lhs_eval_result;
        }

        rhs->optimize(level);

        if (auto rhs_eval_result = rhs->eval(); rhs_eval_result) {
            rhs = *rhs_eval_result;
        }
    }

    auto BinaryOperation::eval() -> ccl::Optional<NodePtr>
    {
        if (lhs->is(NodeType::VALUE) && rhs->is(NodeType::VALUE)) {
            return getFunction()->evalCall({lhs, rhs});
        }

        return std::nullopt;
    }

    auto BinaryOperation::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);
        fmt::print(
            "{} {} ( {} )\n",
            getPrintingPrefix(prefix, is_left),
            operationType,
            OperatorToFunctionName.at(operationType));

        lhs->print(expanded_prefix, true);
        rhs->print(expanded_prefix, false);
    }
}// namespace fsc::ast
