#ifndef FSC_BINARY_HPP
#define FSC_BINARY_HPP

#include "ast/function/magic_methods_table.hpp"
#include "ast/value/value.hpp"
#include "function/from_stack_getter.hpp"
#include "type/builtin_types_impl.hpp"
#include <ccl/const_string.hpp>
#include <ccl/flatmap.hpp>

namespace fsc::builtin
{
    constexpr inline auto CategoryForLhsArgument =
        ccl::StaticFlatmap<ast::MagicFunctionType, ArgumentCategory, 19>{
            {ast::MagicFunctionType::ADD, ArgumentCategory::IN},
            {ast::MagicFunctionType::SUB, ArgumentCategory::IN},
            {ast::MagicFunctionType::MUL, ArgumentCategory::IN},
            {ast::MagicFunctionType::MOD, ArgumentCategory::IN},
            {ast::MagicFunctionType::DIV, ArgumentCategory::IN},
            {ast::MagicFunctionType::EQUAL, ArgumentCategory::IN},
            {ast::MagicFunctionType::NOT_EQUAL, ArgumentCategory::IN},
            {ast::MagicFunctionType::LESS, ArgumentCategory::IN},
            {ast::MagicFunctionType::GREATER, ArgumentCategory::IN},
            {ast::MagicFunctionType::LESS_EQ, ArgumentCategory::IN},
            {ast::MagicFunctionType::GREATER_EQ, ArgumentCategory::IN},
            {ast::MagicFunctionType::INVERT, ArgumentCategory::IN},
            {ast::MagicFunctionType::LOGICAL_NOT, ArgumentCategory::IN},
            {ast::MagicFunctionType::COPY_ASSIGN, ArgumentCategory::OUT},
            {ast::MagicFunctionType::IADD, ArgumentCategory::OUT},
            {ast::MagicFunctionType::ISUB, ArgumentCategory::OUT},
            {ast::MagicFunctionType::IMUL, ArgumentCategory::OUT},
            {ast::MagicFunctionType::IDIV, ArgumentCategory::OUT},
            {ast::MagicFunctionType::IMOD, ArgumentCategory::OUT},
        };

    template<FscIntegral T1, FscIntegral T2, typename BuiltinFunction>
    auto builtinBinaryFunction() -> ccl::Optional<ast::NodePtr>
    {
        auto lhs = stack::getVariable<T1>("lhs");
        auto rhs = stack::getVariable<T2>("rhs");

        if (!(lhs.has_value() && rhs.has_value())) {
            return std::nullopt;
        }

        auto [lhs_argument, lhs_ctx] = *lhs;
        auto [rhs_argument, rhs_ctx] = *rhs;

        auto lhs_value = lhs_argument.value;
        auto rhs_value = rhs_argument.value;

        auto evaluated = BuiltinFunction{}(lhs_value, rhs_value);
        auto constructed_value = ccl::makeUnique<FscBuiltinType<T1>>(evaluated);

        return ccl::makeShared<ast::Value>(std::move(constructed_value), lhs_ctx);
    }

    template<FscFloatingPoint T1, FscFloatingPoint T2, typename BuiltinFunction>
    auto builtinBinaryFunction() -> ccl::Optional<ast::NodePtr>
    {
        using Float1 = std::conditional_t<std::is_same_v<T1, FscFloat32>, ccl::f32, ccl::f64>;
        using Float2 = std::conditional_t<std::is_same_v<T2, FscFloat32>, ccl::f32, ccl::f64>;

        auto lhs = stack::getVariable<ReprOrValue<Float1>>("lhs");
        auto rhs = stack::getVariable<ReprOrValue<Float2>>("rhs");

        if (!(lhs.has_value() && rhs.has_value())) {
            return std::nullopt;
        }

        auto [lhs_argument, lhs_ctx] = *lhs;
        auto [rhs_argument, rhs_ctx] = *rhs;

        auto lhs_value = convertToFloatingPoint(lhs_argument);
        auto rhs_value = convertToFloatingPoint(rhs_argument);

        auto evaluated = BuiltinFunction{}(lhs_value, rhs_value);
        auto constructed_value = ccl::makeUnique<FscBuiltinType<ReprOrValue<Float1>>>(evaluated);

        return ccl::makeShared<ast::Value>(std::move(constructed_value), lhs_ctx);
    }

    template<typename T, typename BuiltinFunction>
    auto builtinBinaryFunction() -> ccl::Optional<ast::NodePtr>
    {
        return builtinBinaryFunction<T, T, BuiltinFunction>();
    }
}// namespace fsc::builtin

#endif /* FSC_BINARY_HPP */
