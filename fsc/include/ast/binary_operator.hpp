#ifndef FSC_BINARY_OPERATOR_HPP
#define FSC_BINARY_OPERATOR_HPP

#include "ast/basic_node.hpp"
#include "function/functions_holder.hpp"
#include <ccl/flatmap.hpp>

namespace fsc::ast
{
    class BinaryOperation : public NodeWrapper<NodeType::BINARY_OPERATOR>
    {
        constexpr static ccl::StaticFlatmap<std::string_view, std::string_view, 6>
            operatorToFunctionName = {{"+", "__add__"}, {"-", "__sub__"},
                                      {"*", "__mul__"}, {"/", "__div__"},
                                      {"%", "__mod__"}, {"&&", "__logical_and__"}};

        NodePtr lhs;
        NodePtr rhs;
        std::string operationType;

    public:
        BinaryOperation(const std::string &operation_type_, NodePtr lhs_, NodePtr rhs_)
          : lhs{std::move(lhs_)}
          , rhs{std::move(rhs_)}
          , operationType{operation_type_}
        {
            CCL_ASSERT(this->getNodeType() == NodeType::BINARY_OPERATOR);
        }

        [[nodiscard]] auto getValueType() const noexcept -> ccl::Id final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_BINARY_OPERATOR_HPP */
