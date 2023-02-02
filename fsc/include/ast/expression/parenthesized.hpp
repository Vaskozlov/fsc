#ifndef FSC_PARENTHESIZED_HPP
#define FSC_PARENTHESIZED_HPP

#include "ast/basic_node.hpp"
#include <ccl/codegen/basic_codegen.hpp>

namespace fsc::ast
{
    class Parenthesized final : public NodeWrapper<NodeType::PARENTHESIZED, SemicolonNeed::NEED>
    {
        NodePtr node;

    public:
        explicit Parenthesized(NodePtr node_to_parenthesize);

        [[nodiscard]] auto getValueType() const -> FscType final;

        auto analyze() const -> void final;

        auto optimize(OptimizationLevel optimization) -> void final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_PARENTHESIZED_HPP */
