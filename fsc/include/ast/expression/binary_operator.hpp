#ifndef FSC_BINARY_OPERATOR_HPP
#define FSC_BINARY_OPERATOR_HPP

#include "ast/basic_node.hpp"
#include "ast/function/function.hpp"
#include "function/functions_holder.hpp"
#include <FscParser.h>
#include <type/antlr-types.hpp>

namespace fsc::ast
{
    class BinaryOperation final : public NodeWrapper<NodeType::BINARY_OPERATOR, SemicolonNeed::NEED>
    {
        NodePtr lhs;
        NodePtr rhs;
        std::string operationType;

    public:
        BinaryOperation(
            ExpressionContext *ctx, std::string operation_type, NodePtr left_node,
            NodePtr right_node);

        [[nodiscard]] auto getValueType() -> FscType final;

        auto analyze() -> AnalysisReport final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;

        auto optimize(OptimizationLevel level) -> void final;

        auto eval() -> ccl::Optional<NodePtr> final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

    private:
        [[nodiscard]] auto getFunction() const -> ccl::SharedPtr<ast::Function>;
    };
}// namespace fsc::ast

#endif /* FSC_BINARY_OPERATOR_HPP */
