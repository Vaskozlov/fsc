#ifndef FSC_IMPLEMENT_OPERATORS_HPP
#define FSC_IMPLEMENT_OPERATORS_HPP

#include "ast/function/function.hpp"
#include "ast/function/magic_methods_table.hpp"
#include "function/builtin/binary.hpp"
#include "function/builtin/unary.hpp"
#include "function/default_function_info.hpp"

namespace fsc::builtin
{
    template<ast::MagicFunctionType FunctionMagic>
    auto implementBinaryOperator(FscType return_type, FscType lhs, FscType rhs) -> ast::Function
    {
        const auto left_argument = Argument{"lhs", lhs, CategoryForLhsArgument.at(FunctionMagic)};
        const auto right_argument = Argument{"rhs", rhs, ArgumentCategory::IN};

        return {Void,
                ast::magic::MagicToFscName[FunctionMagic],
                "",
                return_type,
                {left_argument, right_argument},
                info::NoexceptReturningFunction};
    }

    template<
        ast::MagicFunctionType FunctionMagic, typename T1, typename T2, typename BuiltinFunction>
    auto implementBinaryOperator(FscType return_type, FscType lhs, FscType rhs) -> ast::Function
    {
        const auto left_argument = Argument{"lhs", lhs, CategoryForLhsArgument.at(FunctionMagic)};
        const auto right_argument = Argument{"rhs", rhs, ArgumentCategory::IN};

        return ast::Function{
            Void,
            ast::magic::MagicToFscName[FunctionMagic],
            "",
            return_type,
            {left_argument, right_argument},
            info::NoexceptReturningFunction,
            {},
            ast::MagicFunctionType::NONE,
            builtinBinaryFunction<T1, T2, BuiltinFunction>};
    }

    template<ast::MagicFunctionType FunctionMagic>
    auto implementUnaryOperator(FscType return_type, FscType lhs) -> ast::Function
    {
        const auto argument = Argument{"value", lhs, CategoryForLhsArgument.at(FunctionMagic)};

        return ast::Function{Void,       ast::magic::MagicToFscName[FunctionMagic],
                             "",         return_type,
                             {argument}, info::NoexceptReturningFunction};
    }

    template<ast::MagicFunctionType FunctionMagic, FscIntegral T1, typename BuiltinFunction>
    auto implementUnaryOperator(FscType return_type, FscType lhs) -> ast::Function
    {
        const auto argument = Argument{"value", lhs, CategoryForLhsArgument.at(FunctionMagic)};

        return ast::Function{Void,       ast::magic::MagicToFscName[FunctionMagic],
                             "",         return_type,
                             {argument}, info::NoexceptReturningFunction};
    }

    template<typename T1, typename T2>
    auto implementOperators(FscType lhs, FscType rhs) -> ccl::Vector<ast::Function>
    {
        using namespace ast;

        auto operators = ccl::Vector<ast::Function>{
            implementBinaryOperator<MagicFunctionType::ADD, T1, T2, std::plus<>>(lhs, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::SUB, T1, T2, std::minus<>>(lhs, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::MUL, T1, T2, std::multiplies<>>(
                lhs, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::DIV, T1, T2, std::divides<>>(lhs, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::IADD>(lhs, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::ISUB>(lhs, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::IMUL>(lhs, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::IDIV>(lhs, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::LESS, T1, T2, std::less<>>(Bool, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::LESS_EQ, T1, T2, std::less_equal<>>(
                Bool, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::GREATER, T1, T2, std::greater<>>(
                Bool, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::GREATER_EQ, T1, T2, std::greater_equal<>>(
                Bool, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::EQUAL, T1, T2, std::equal_to<>>(
                Bool, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::NOT_EQUAL, T1, T2, std::not_equal_to<>>(
                Bool, lhs, rhs),
            implementBinaryOperator<MagicFunctionType::COPY_ASSIGN>(lhs, lhs, rhs)};

        if constexpr (FscIntegral<T1>) {
            operators.emplace_back(
                implementBinaryOperator<MagicFunctionType::MOD, T1, T2, std::modulus<>>(
                    lhs, lhs, rhs));
            operators.emplace_back(implementBinaryOperator<MagicFunctionType::IMOD>(lhs, lhs, rhs));
            operators.emplace_back(
                implementUnaryOperator<MagicFunctionType::INVERT, T1, std::bit_not<>>(lhs, lhs));
        }

        return operators;
    }

    auto implementConstructors(FscType type, ccl::InitializerList<FscType> extra_types)
        -> ccl::Vector<ast::Function>
    {
        using namespace ast;

        auto empty_constructor = Function{type, type.getName(),       "", type,
                                          {},   info::NoexceptMethod, {}, MagicFunctionType::INIT};

        auto copy_constructor = Function{
            type,
            type.getName(),
            "",
            type,
            {Argument{"value", type, ArgumentCategory::IN}},
            info::NoexceptMethod,
            {},
            MagicFunctionType::INIT};

        auto result =
            ccl::Vector<Function>{std::move(empty_constructor), std::move(copy_constructor)};

        result.reserve(result.size() + extra_types.size());

        for (auto extra_type : extra_types) {
            result.emplace_back(Function{
                type,
                type.getName(),
                "",
                type,
                {Argument{"value", extra_type, ArgumentCategory::IN}},
                info::NoexceptMethod,
                {},
                MagicFunctionType::INIT});
        }

        return result;
    }
}// namespace fsc::builtin

#endif /* FSC_IMPLEMENT_OPERATORS_HPP */
