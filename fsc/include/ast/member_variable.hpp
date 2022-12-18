#ifndef FSC_MEMBER_ACCESS_HPP
#define FSC_MEMBER_ACCESS_HPP

#include "ast/basic_node.hpp"

namespace fsc::ast
{
    class MemberVariable : public NodeWrapper<NodeType::MEMBER_VARIABLE, SemicolonNeed::NEED>
    {
    private:
        NodePtr node;
        std::string name;

    public:
        MemberVariable(NodePtr node_to_access, std::string variable_name);

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

    private:
        auto canAccessMember() const noexcept -> bool;
        auto getTypeOfNode() const noexcept -> ccl::Optional<ccl::Id>;
    };
}// namespace fsc::ast

#endif /* FSC_MEMBER_ACCESS_HPP */
