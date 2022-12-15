#include "ast/function_call.hpp"
#include <ranges>

using namespace std::string_view_literals;

namespace fsc::ast
{
    FunctionCall::FunctionCall(
        ccl::SharedPtr<Function>
            function_to_call,
        const ccl::SmallVector<NodePtr> &function_arguments)
      : arguments{function_arguments}
      , function{std::move(function_to_call)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::FUNCTION_CALL);
    }

    auto FunctionCall::getValueType() const noexcept -> ccl::Id
    {
        return function->getReturnType();
    }

    auto FunctionCall::codeGen(gen::CodeGenerator &output) const -> void
    {
        output.write(function->getName());
        output.write('(');

        for (const auto &argument : arguments | ccl::views::dropBack(arguments)) {
            argument->codeGen(output);
            output.write(", "sv);
        }

        if (!arguments.empty()) {
            arguments.back()->codeGen(output);
        }

        output.write(')');
    }

    auto FunctionCall::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, false);
        fmt::print("{}Call {}\n", getPrintingPrefix(prefix, is_left), function->getName());

        for (auto &arg : arguments | ccl::views::dropBack(arguments)) {
            arg->print(expanded_prefix, true);
        }

        if (!arguments.empty()) {
            auto &node = arguments.back();
            node->print(expanded_prefix, false);
        }
    }
}// namespace fsc::ast
