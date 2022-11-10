#ifndef FSC_BINARY_OPERATOR_HPP
#define FSC_BINARY_OPERATOR_HPP

#include "ast/basic_node.hpp"
#include "function/function.hpp"
#include "function/functions_holder.hpp"

namespace fsc::ast {
    CCL_ENUM(BinaryOperationType, size_t, ADD, SUB, MUL, DIV, MOD);

    class BinaryOperation : public Node {
        static const inline ccl::UnorderedMap<std::string, std::string> operatorToFunctionName = {
                {"+", "__add__"}, {"-", "__sub__"}, {"*", "__mul__"},
                {"/", "__div__"}, {"%", "__mod__"}, {"&&", "__logical_and__"}};

        ccl::SharedPtr<Node> lhs;
        ccl::SharedPtr<Node> rhs;
        std::string operationType;

    public:
        BinaryOperation(const std::string &operation_type_, ccl::SharedPtr<Node> lhs_,
                        ccl::SharedPtr<Node> rhs_)
            : Node(classof()), lhs(std::move(lhs_)), rhs(std::move(rhs_)),
              operationType(operation_type_)
        {}

        [[nodiscard]] auto getValueType() const noexcept -> TypeId final;
        auto codeGen(gen::CodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] constexpr static auto classof() noexcept -> NodeType
        {
            return NodeType::BINARY_OPERATOR;
        }
    };
}// namespace fsc::ast

#endif /* FSC_BINARY_OPERATOR_HPP */
