#include "ast/function/function_call.hpp"
#include <ranges>

using namespace ccl;
using namespace std::string_view_literals;

namespace fsc::ast
{
    FunctionCall::FunctionCall(
        WeakPtr<Function> function_to_call, const SmallVector<NodePtr> &function_arguments,
        const ccl::SmallVector<FscType> &templates)
      : arguments{function_arguments}
      , functionCallTemplates{templates}
      , function{std::move(function_to_call)}
    {}

    auto FunctionCall::defaultPrint(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, false);
        fmt::print("{}Call {}\n", getPrintingPrefix(prefix, is_left), function.lock()->getName());

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
        output << function.lock()->getName();

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
        auto fn = function.lock();
        fn->analyzeOnCall(arguments);
    }

    auto FunctionCall::getValueType() const -> FscType
    {
        return function.lock()->getReturnType();
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
