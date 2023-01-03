#include "ast/statement/while.hpp"

namespace fsc::ast
{
    While::While(NodePtr while_condition, NodePtr while_body)
      : condition{std::move(while_condition)}
      , body{std::move(while_body)}
    {}

    auto While::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        using namespace ccl::codegen;

        output << "while ";

        if (condition->is(NodeType::PARENTHESIZED)) {
            output << *condition;
        } else {
            output << '(' << *condition << ')';
        }

        output << endl << *body;
    }

    auto While::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);
        fmt::print("{}While loop\n", getPrintingPrefix(prefix, is_left));

        condition->print(expanded_prefix, true);
        body->print(expanded_prefix, true);
    }
}// namespace fsc::ast
