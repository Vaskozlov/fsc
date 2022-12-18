#include "ast/parenthesized.hpp"
#include <ast/basic_node.hpp>

namespace fsc::ast
{
    Parenthesized::Parenthesized(NodePtr node_to_parenthesize)
      : node{std::move(node_to_parenthesize)}
    {}

    auto Parenthesized::getValueType() const -> ccl::Id
    {
        return node->getValueType();
    }

    auto Parenthesized::codeGen(gen::CodeGenerator &output) const -> void
    {
        if (node->is(NodeType::PARENTHESIZED)) {
            output << *node;
        } else {
            output << '(' << *node << ')';
        }
    }

    auto Parenthesized::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Parenthesized\n", getPrintingPrefix(prefix, is_left));

        node->print(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
