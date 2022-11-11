#ifndef FSC_BINARY_OPERATOR_HPP
#define FSC_BINARY_OPERATOR_HPP

#include "ast/basic_node.hpp"
#include "function/functions_holder.hpp"
#include <ccl/flatmap.hpp>

namespace fsc::ast {
    CCL_ENUM(BinaryOperationType, size_t, ADD, SUB, MUL, DIV, MOD);

    class BinaryOperation : public Node {
        constexpr static ccl::StaticFlatmap<std::string_view, std::string_view, 6>
                operatorToFunctionName = {{"+", "__add__"}, {"-", "__sub__"},
                                          {"*", "__mul__"}, {"/", "__div__"},
                                          {"%", "__mod__"}, {"&&", "__logical_and__"}};

        NodePtr lhs;
        NodePtr rhs;
        std::string operationType;

    public:
        BinaryOperation(const std::string &operation_type_, NodePtr lhs_, NodePtr rhs_)
            : Node{classof()}, lhs{std::move(lhs_)}, rhs{std::move(rhs_)},
              operationType{operation_type_}
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
