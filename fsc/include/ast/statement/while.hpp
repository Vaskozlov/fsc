#ifndef FSC_WHILE_HPP
#define FSC_WHILE_HPP

#include "ast/basic_node.hpp"

namespace fsc::ast
{
    class While final : public NodeWrapper<NodeType::WHILE, SemicolonNeed::DO_NOT_NEED>
    {
    private:
        NodePtr condition;
        NodePtr body;

    public:
        While(NodePtr while_condition, NodePtr while_body);

        auto analyze() const -> void final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_WHILE_HPP */
