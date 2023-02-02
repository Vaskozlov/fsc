#include "ast/expression/parenthesized.hpp"
#include "type/type.hpp"

namespace fsc::ast
{
    Parenthesized::Parenthesized(NodePtr node_to_parenthesize)
      : node{std::move(node_to_parenthesize)}
    {}

    auto Parenthesized::getValueType() const -> FscType
    {
        return node->getValueType();
    }

    auto Parenthesized::analyze() const -> void
    {
        node->analyze();
    }

    auto Parenthesized::optimize(OptimizationLevel optimization_level) -> void
    {
        if (node->is(NodeType::PARENTHESIZED)) {
            node = std::move(node->as<Parenthesized>().node);
        }

        node->optimize(optimization_level);
    }

    auto Parenthesized::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        output << '(' << *node << ')';
    }

    auto Parenthesized::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Parenthesized\n", getPrintingPrefix(prefix, is_left));

        node->print(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
