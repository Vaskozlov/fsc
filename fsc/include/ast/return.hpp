#ifndef FSC_RETURN_HPP
#define FSC_RETURN_HPP

#include "ast/basic_node.hpp"
#include "visitor.hpp"

namespace fsc::ast
{
    class Return : public NodeWrapper<NodeType::RETURN, SemicolonNeed::NEED>
    {
        NodePtr value;

    public:
        explicit Return(Visitor &visitor, NodePtr value_to_return);

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        [[nodiscard]] auto getValueType() const -> ccl::Id final;
    };
}// namespace fsc::ast

#endif /* FSC_RETURN_HPP */
