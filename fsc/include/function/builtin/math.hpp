#ifndef FSC_SINGLE_ARGUMENT_MATH_FUNCTION_HPP
#define FSC_SINGLE_ARGUMENT_MATH_FUNCTION_HPP

#include "ast/value/value.hpp"
#include "function/from_stack_getter.hpp"
#include "type/builtin_types_impl.hpp"

namespace fsc::builtin
{
    template<std::floating_point T>
    static auto log(T argument, T base) -> T
    {
        return std::log(argument) / std::log(base);
    }

    template<std::floating_point Float, Float (*BuiltinFunction)(Float)>
    static auto builtinMathFunction() -> ccl::Optional<ast::NodePtr>
    {
        auto value = stack::getVariable<ReprOrValue<Float>>("value");

        if (!value.has_value()) {
            return std::nullopt;
        }

        auto [function_argument, ctx] = *value;
        auto floating_point_value = convertToFloatingPoint(function_argument);
        auto evaluated = BuiltinFunction(floating_point_value);

        return ccl::makeShared<ast::Value>(
            ccl::makeUnique<FscBuiltinType<ReprOrValue<Float>>>(evaluated), ctx);
    }

    template<std::floating_point Float, Float (*BuiltinFunction)(Float, Float)>
    static auto builtinLogWithBase() -> ccl::Optional<ast::NodePtr>
    {
        auto argument = stack::getVariable<ReprOrValue<Float>>("argument");
        auto base = stack::getVariable<ReprOrValue<Float>>("base");

        if (!(argument.has_value() && base.has_value())) {
            return std::nullopt;
        }

        auto [function_argument, ctx] = *argument;
        auto [function_base, base_ctx] = *base;
        auto floating_point_value = convertToFloatingPoint(function_argument);
        auto floating_point_base = convertToFloatingPoint(function_base);

        auto evaluated = BuiltinFunction(floating_point_value, floating_point_base);

        return ccl::makeShared<ast::Value>(
            ccl::makeUnique<FscBuiltinType<ReprOrValue<Float>>>(evaluated), ctx);
    }
}// namespace fsc::builtin

#endif /* FSC_SINGLE_ARGUMENT_MATH_FUNCTION_HPP */
