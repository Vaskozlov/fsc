#ifndef FSC_RETURN_HPP
#define FSC_RETURN_HPP

#include "ast/basic_node.hpp"
#include "visitor.hpp"

namespace fsc::ast
{
    class Return final : public NodeWrapper<NodeType::RETURN, SemicolonNeed::NEED>
    {
        NodePtr value;

    public:
        explicit Return(NodePtr value_to_return, BasicContextPtr node_context);

        auto analyze() -> void final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        [[nodiscard]] auto getValueType() -> FscType final;
    };
}// namespace fsc::ast

#endif /* FSC_RETURN_HPP */
