#ifndef FSC_IF_STMT_HPP
#define FSC_IF_STMT_HPP

#include "ast/basic_node.hpp"
#include "ccl/core/types.hpp"

namespace fsc::ast
{
    class IfStatement : NodeWrapper<NodeType::IF_STATEMENT>
    {
        NodePtr condition;
        NodePtr body;

    public:
        IfStatement(NodePtr if_condition, NodePtr if_body) noexcept;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_IF_STMT_HPP */
