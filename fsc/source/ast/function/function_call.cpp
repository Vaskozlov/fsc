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
      , classId{std::move(class_id)}
    {}

    auto FunctionCall::getFunction() const -> ccl::SharedPtr<Function>
    {
        return func::Functions.get({functionName, typedArguments, classId});
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

    auto FunctionCall::defaultCodegen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        output << functionName;

        if (!functionCallTemplates.empty()) {
            output << "<";
            fmt::format_to(output.getBackInserter(), "{}", fmt::join(functionCallTemplates, ", "));
            output << ">";
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

    auto FunctionCall::analyze() const -> void
    {
        auto fn = getFunction();
        fn->analyzeOnCall(arguments);
    }

    auto FunctionCall::getValueType() const -> FscType
    {
        return getFunction()->getReturnType();
    }

    auto FunctionCall::codeGen(codegen::BasicCodeGenerator &output) const -> void
    {
        defaultCodegen(output);
    }

    auto FunctionCall::print(const std::string &prefix, bool is_left) const -> void
    {
        defaultPrint(prefix, is_left);
    }
}// namespace fsc::ast
