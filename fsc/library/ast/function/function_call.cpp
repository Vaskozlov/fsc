#include "ast/function/function_call.hpp"
#include "function/functions_holder.hpp"
#include <ranges>

using namespace ccl;
using namespace std::string_view_literals;

namespace fsc::ast
{
    FunctionCall::FunctionCall(
        std::string function_name, const ccl::SmallVector<Argument> &typed_arguments,
        FscType class_id, const SmallVector<NodePtr> &function_arguments,
        const ccl::SmallVector<FscType> &templates)
      : arguments{function_arguments}
      , functionCallTemplates{templates}
      , functionName{std::move(function_name)}
      , typedArguments{typed_arguments}
      , classId{class_id}
    {}

    auto FunctionCall::getFunction() const -> ccl::SharedPtr<Function>
    {
        // TODO: change way how template classes are stored
        try {
            return func::Functions.get({functionName, typedArguments, classId});
        } catch (const std::exception &) {
            if (functionCallTemplates.empty()) {
                throw;
            }

            auto full_name = fmt::format("{}<", functionName);

            for (auto function_template :
                 functionCallTemplates | ccl::views::dropBack(functionCallTemplates)) {
                full_name.append(fmt::format("{}, ", function_template.getName()));
            }

            full_name.append(functionCallTemplates.back().getName() + ">");
            return func::Functions.get({full_name, typedArguments, classId});
        }
    }

    auto FunctionCall::defaultPrint(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, false);
        fmt::print("{}Call {}\n", getPrintingPrefix(prefix, is_left), functionName);

        for (const auto &arg : arguments | ccl::views::dropBack(arguments)) {
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

        output << '(';

        for (const auto &argument : arguments | ccl::views::dropBack(arguments)) {
            output << *argument << ", ";
        }

        if (!arguments.empty()) {
            output << *arguments.back();
        }

        output << ')';
    }

    auto FunctionCall::analyze() -> void
    {
        auto fn = getFunction();
        returnedType = fn->analyzeOnCall(arguments);
    }

    auto FunctionCall::getValueType() -> FscType
    {
        auto fn = getFunction();
        returnedType = fn->analyzeOnCall(arguments);

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
