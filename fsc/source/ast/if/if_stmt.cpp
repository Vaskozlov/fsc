#include "ast/if/if_stmt.hpp"

namespace fsc::ast
{
    using namespace std::string_view_literals;

    IfStatement::IfStatement(NodePtr if_condition, NodePtr if_body) noexcept
      : condition{std::move(if_condition)}
      , body{std::move(if_body)}
    {}

    auto IfStatement::codeGen(gen::CodeGenerator &output) const -> void
    {
        output.write("if ("sv);
        condition->codeGen(output);
        output.write(')');
        output.newLine();
        body->codeGen(output);
    }

    auto IfStatement::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);

        fmt::print("{}If\n", getPrintingPrefix(prefix, is_left));

        condition->print(expanded_prefix, true);
        body->print(expanded_prefix, false);
    }
}// namespace fsc::ast
