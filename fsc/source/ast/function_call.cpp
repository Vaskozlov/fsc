#include "ast/function_call.hpp"
#include <ranges>

using namespace std::string_view_literals;

namespace fsc::ast {
    auto FunctionCall::codeGen(gen::CodeGenerator &output) const -> void
    {
        output.add(function.getName());
        output.add('(');

        for (const auto &argument : arguments | std::views::take(arguments.size() - 1)) {
            argument->codeGen(output);
            output.add(", "sv);
        }

        arguments.back()->codeGen(output);
        output.add(')');
    }

    auto FunctionCall::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}Call {}\n", getPrintingPrefix(prefix, is_left), function.getName());

        for (auto &arg : arguments | std::views::take(arguments.size() - 1)) {
            arg->print(expandPrefix(prefix, false), true);
        }

        if (!arguments.empty()) {
            auto &node = arguments.back();
            node->print(expandPrefix(prefix, false), false);
        }
    }
}// namespace fsc::ast
