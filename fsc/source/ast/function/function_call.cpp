#include "ast/function/function_call.hpp"
#include <ranges>

using namespace std::string_view_literals;

namespace fsc::ast
{
    FunctionCall::FunctionCall(
        ccl::WeakPtr<Function>
            function_to_call,
        const ccl::SmallVector<NodePtr> &function_arguments)
      : arguments{function_arguments}
      , function{std::move(function_to_call)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::FUNCTION_CALL);
    }

    auto FunctionCall::defaultFunctionCallPrint(const std::string &prefix, bool is_left) const
        -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, false);
        fmt::print("{}Call {}\n", getPrintingPrefix(prefix, is_left), function.lock()->getName());

        for (auto &arg : arguments | ccl::views::dropBack(arguments)) {
            arg->print(expanded_prefix, true);
        }

        if (!arguments.empty()) {
            auto &node = arguments.back();
            node->print(expanded_prefix, false);
        }
    }

    auto FunctionCall::defaultFunctionCallCodeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        output << function.lock()->getName() << '(';

        for (const auto &argument : arguments | ccl::views::dropBack(arguments)) {
            output << *argument << ", ";
        }

        if (!arguments.empty()) {
            output << *arguments.back();
        }

        output << ')';
    }

    auto FunctionCall::getValueType() const -> ccl::Id
    {
        return function.lock()->getReturnType();
    }

    auto FunctionCall::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        defaultFunctionCallCodeGen(output);
    }

    auto FunctionCall::print(const std::string &prefix, bool is_left) const -> void
    {
        defaultFunctionCallPrint(prefix, is_left);
    }
}// namespace fsc::ast
