#include "ast/binary_operator.hpp"
#include <ast/basic_node.hpp>
#include <function/argument.hpp>
#include <function/functions_holder.hpp>
#include <ranges>
#include <utility>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    BinaryOperation::BinaryOperation(
        std::string operation_type,
        NodePtr left_node,
        NodePtr right_node)
      : lhs{std::move(left_node)}
      , rhs{std::move(right_node)}
      , operationType{std::move(operation_type)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::BINARY_OPERATOR);
        getValueType();
    }

    auto BinaryOperation::getValueType() const -> ccl::Id
    {
        const auto left_argument_type = Argument{lhs.get()};
        const auto right_argument_type = Argument{rhs.get()};
        const auto function_name = operatorToFunctionName.at(operationType);
        const auto signature =
            Signature{std::string{function_name}, {left_argument_type, right_argument_type}};

        return func::Functions.visitFunction(
            signature,
            [](const Function *function) { return function->getReturnType(); },
            CallRequirements::IMPLICIT);
    }

    auto BinaryOperation::codeGen(gen::CodeGenerator &output) const -> void
    {
        output << *lhs << " "sv << operationType << " "sv << *rhs;
    }

    auto BinaryOperation::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), operationType);

        lhs->print(expanded_prefix, true);
        rhs->print(expanded_prefix, false);
    }
}// namespace fsc::ast
