#ifndef FSC_WHILE_HPP
#define FSC_WHILE_HPP

#include "ast/basic_node.hpp"

namespace fsc::ast
{
    class While : public NodeWrapper<NodeType::WHILE, SemicolonNeed::DO_NOT_NEED>
    {
    private:
        NodePtr condition;
        NodePtr body;

    public:
        While(NodePtr while_condition, NodePtr while_body);

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;
    };
}

#endif /* FSC_WHILE_HPP */
