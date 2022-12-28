#include "ast/expression/binary_operator.hpp"
#include "function/argument.hpp"
#include "function/functions_holder.hpp"
#include <ccl/flatmap.hpp>
#include <ranges>
#include <utility>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    constexpr static ccl::StaticFlatmap<std::string_view, std::string_view, 13>
        OperatorToFunctionName = {
            {"+", "__add__"},          {"-", "__sub__"},         {"*", "__mul__"},
            {"/", "__div__"},          {"%", "__mod__"},         {"<", "__less__"},
            {">", "__greater__"},      {"<=", "__less_equal__"}, {">", "__greater_equal__"},
            {"&&", "__logical_and__"}, {"==", "__equal__"},      {"!=", "__not_equal__"},
            {"=", "__copy__"}};

    BinaryOperation::BinaryOperation(
        std::string operation_type,
        NodePtr left_node,
        NodePtr right_node)
      : lhs{std::move(left_node)}
      , rhs{std::move(right_node)}
      , operationType{std::move(operation_type)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::BINARY_OPERATOR);
    }

    auto BinaryOperation::getValueType() const -> ccl::Id
    {
        const auto left_argument_type = Argument{lhs.get()};
        const auto right_argument_type = Argument{rhs.get()};
        const auto function_name = OperatorToFunctionName.at(operationType);

        return func::Functions.visitFunction(
            {std::string{function_name}, {left_argument_type, right_argument_type}},
            std::mem_fn(&Function::getReturnType));
    }

    auto BinaryOperation::codeGen(gen::CodeGenerator &output) const -> void
    {
        output << *lhs << " " << operationType << " " << *rhs;
    }

    auto BinaryOperation::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), operationType);

        lhs->print(expanded_prefix, true);
        rhs->print(expanded_prefix, false);
    }
}// namespace fsc::ast
