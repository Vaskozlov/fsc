#include "ast/expression/unary_operator.hpp"
#include "function/argument.hpp"
#include "function/functions_holder.hpp"
#include <ccl/flatmap.hpp>
#include <exception>
#include <ranges>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    constexpr static ccl::StaticFlatmap<std::string_view, std::string_view, 18>
        OperatorToFunctionName = {{"~", "__invert__"}, {"!", "__logical_not__"}};

    UnaryOperation::UnaryOperation(
        FscParser::ExprContext *ctx,
        std::string operation_type,
        NodePtr value_node)
      : NodeWrapper{ccl::as<BasicContextPtr>(ctx)}
      , value{std::move(value_node)}
      , operationType{std::move(operation_type)}
    {
        setStart(ctx->start);
        setStop(ctx->stop);
    }

    auto UnaryOperation::getValueType() -> FscType
    {
        return getFunction()->getReturnType();
    }

    auto UnaryOperation::getFunction() const -> ccl::SharedPtr<ast::Function>
    {
        const auto function_name = OperatorToFunctionName.at(operationType);

        return preparerToCatchError(
            [this, &function_name]() {
                return func::Functions.get(
                    {std::string{function_name}, {Argument{value.get()}}, Void});
            },
            *this);
    }

    auto UnaryOperation::analyze() -> AnalysisReport
    {
        return preparerToCatchError(
            [this]() {
                auto function = getFunction();
                const auto &function_arguments = function->getArguments();
                auto [return_type, report] = function->analyzeOnCall({value}, {});

                switch (function_arguments.at(0).getCategory()) {
                case ArgumentCategory::IN:
                    report.addToRead(value);
                    break;

                case ArgumentCategory::OUT:
                case ArgumentCategory::INOUT:
                    report.addToModified(value);
                    break;

                default:
                    ccl::unreachable();
                }

                return report;
            },
            *this);
    }

    auto UnaryOperation::codeGen(ccl::codegen::BasicCodeGenerator &output) -> void
    {
        output << operationType << *value;
    }

    auto UnaryOperation::optimize(OptimizationLevel level) -> void
    {
        value->optimize(level);
    }

    auto UnaryOperation::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);
        fmt::print(
            "{} {} ( {} )\n",
            getPrintingPrefix(prefix, is_left),
            operationType,
            OperatorToFunctionName.at(operationType));

        value->print(expanded_prefix, false);
    }
}// namespace fsc::ast
