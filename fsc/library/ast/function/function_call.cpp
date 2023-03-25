#include "ast/function/function_call.hpp"
#include "function/functions_holder.hpp"
#include "visitor.hpp"
#include <ccl/join.hpp>

using namespace ccl;
using namespace std::string_view_literals;

namespace fsc::ast
{
    FunctionCall::FunctionCall(
        std::string function_name, const ccl::Vector<Argument> &typed_arguments, FscType class_id,
        const Vector<NodePtr> &function_arguments, const ccl::Vector<FscType> &templates,
        BasicContextPtr node_context)
      : NodeWrapper{node_context}
      , arguments{function_arguments}
      , functionCallTemplates{templates}
      , functionName{std::move(function_name)}
      , typedArguments{typed_arguments}
      , classId{class_id}
    {}

    auto FunctionCall::getFunction() const -> ccl::SharedPtr<Function>
    {
        return func::Functions.get(
            {functionName, typedArguments,
             TypeManager::getBaseTypeOfInstantiatedTemplate(classId)});
    }

    auto FunctionCall::generateIndexOperator(ccl::codegen::BasicCodeGenerator &output) -> void
    {
        output << argumentToString();
    }

    auto FunctionCall::generateFunctionName(ccl::codegen::BasicCodeGenerator &output) -> void
    {
        try {
            auto function_to_gen = getFunction();
            const auto &codegen_name = function_to_gen->getCodegenName();
            output << codegen_name;
        } catch (const FscException & /* unused */) {
            // sometimes function can not be found, because it's templates constructor
            output << functionName;
        }
    }

    auto FunctionCall::analyze() -> AnalysisReport
    {
        return preparerToCatchError(
            [this]() {
                return attemptToAnalyze();
            },
            *this);
    }

    auto FunctionCall::attemptToAnalyze() -> AnalysisReport
    {
        auto report = AnalysisReport{};
        auto function_to_call = getFunction();
        const auto &function_arguments = function_to_call->getArguments();

        for (auto i = 0ZU; i != arguments.size(); ++i) {
            report.merge(arguments[i]->analyze());

            if (i >= function_arguments.size()) {
                report.addToRead(arguments[i]);
                continue;
            }

            switch (function_arguments[i].getCategory()) {
            case ArgumentCategory::IN:
            case ArgumentCategory::COPY:
                report.addToRead(arguments[i]);
                break;

            case ArgumentCategory::INOUT:
            case ArgumentCategory::OUT:
                report.addToModified(arguments[i]);
                break;

            default:
                std::unreachable();
            }
        }

        auto [type, function_call_report] =
            function_to_call->analyzeOnCall(arguments, functionCallTemplates);

        report.merge(std::move(function_call_report));

        return report;
    }

    auto FunctionCall::getValueType() -> FscType
    {
        auto [type, analysis_report] =
            getFunction()->analyzeOnCall(arguments, functionCallTemplates);

        return type;
    }

    auto FunctionCall::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        generateFunctionName(output);

        if (!functionCallTemplates.empty()) {
            fmt::format_to(
                output.getBackInserter(), "<{}>", fmt::join(functionCallTemplates, ", "));
        }

        const auto is_constructor = TypeManager::exists(functionName);
        const auto open_bracket = is_constructor ? '{' : '(';
        const auto close_bracket = is_constructor ? '}' : ')';

        output << open_bracket << argumentToString() << close_bracket;
    }

    auto FunctionCall::optimize(OptimizationLevel level) -> void
    {
        for (auto &argument : arguments) {
            argument->optimize(level);

            if (auto evaluated_argument = evaluateArgument(argument.get());
                evaluated_argument.has_value()) {
                argument = *evaluated_argument;
            }
        }

        getFunction()->optimize(level);
    }

    auto FunctionCall::eval() -> Optional<NodePtr>
    {
        return getFunction()->evalCall(arguments);
    }

    auto FunctionCall::evaluateArgument(Node *argument) const -> ccl::Optional<NodePtr>
    {
        if (functionCallTemplates.empty()) {
            return argument->eval();
        }

        return std::nullopt;
    }

    auto FunctionCall::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);
        fmt::print("{}Call {}\n", getPrintingPrefix(prefix, is_left), functionName);

        for (const auto &arg : arguments | ccl::views::dropBack(arguments, 1)) {
            arg->print(expanded_prefix, true);
        }

        if (!arguments.empty()) {
            const auto &node = arguments.back();
            node->print(expanded_prefix, false);
        }
    }

    auto FunctionCall::argumentToString() const -> std::string
    {
        return ccl::join(
            arguments,
            [](const SharedPtr<Node> &argument) {
                return argument->toString();
            },
            ", ");
    }
}// namespace fsc::ast
