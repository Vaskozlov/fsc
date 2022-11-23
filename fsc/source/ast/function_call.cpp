#include "ast/function_call.hpp"
#include <ranges>

using namespace std::string_view_literals;

namespace fsc::ast {
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

    auto FunctionCall::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}Call {}\n", getPrintingPrefix(prefix, is_left), function->getName());

        for (auto &arg : arguments | ccl::views::dropBack(arguments)) {
            arg->print(expandPrefix(prefix, false), true);
        }

        if (!arguments.empty()) {
            auto &node = arguments.back();
            node->print(expandPrefix(prefix, false), false);
        }
    }
}// namespace fsc::ast
