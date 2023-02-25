#include "ast/function/function_call.hpp"
#include "function/functions_holder.hpp"
#include <ccl/join.hpp>
#include <ranges>

using namespace ccl;
using namespace std::string_view_literals;

namespace fsc::ast
{
    FunctionCall::FunctionCall(
        std::string function_name, const ccl::SmallVector<Argument> &typed_arguments,
        FscType class_id, const SmallVector<NodePtr> &function_arguments,
        const ccl::SmallVector<FscType> &templates, BasicContextPtr node_context)
      : NodeWrapper{node_context}
      , arguments{function_arguments}
      , functionCallTemplates{templates}
      , functionName{std::move(function_name)}
      , typedArguments{typed_arguments}
      , classId{class_id}
    {}

    auto FunctionCall::getFunction() const -> ccl::SharedPtr<Function>
    {
        return func::Functions.get({functionName, typedArguments, classId});
    }

    auto FunctionCall::defaultPrint(const std::string &prefix, bool is_left) const -> void
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

    auto FunctionCall::defaultCodegen(ccl::codegen::BasicCodeGenerator &output) -> void
    {
        output << functionName;

        if (!functionCallTemplates.empty()) {
            fmt::format_to(
                output.getBackInserter(), "<{}>", fmt::join(functionCallTemplates, ", "));
        }

        const auto is_constructor = TypeManager::exists(functionName);
        const auto open_bracket = is_constructor ? '{' : '(';
        const auto close_bracket = is_constructor ? '}' : ')';

        output << open_bracket
               << ccl::join(
                      arguments,
                      [](const SharedPtr<Node> &argument) {
                          return argument->toString();
                      },
                      ", ")
               << close_bracket;
    }

    auto FunctionCall::analyze() -> AnalysisReport
    {
        try {
            return attemptToAnalyze();
        } catch (const FscException &e) {
            GlobalVisitor->throwError(getContext().value(), e.what());
        }
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
        returnedType = type;
        return returnedType;
    }

    auto FunctionCall::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        defaultCodegen(output);
    }

    auto FunctionCall::print(const std::string &prefix, bool is_left) const -> void
    {
        defaultPrint(prefix, is_left);
    }
}// namespace fsc::ast
