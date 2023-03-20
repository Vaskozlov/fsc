#ifndef FSC_UNARY_HPP
#define FSC_UNARY_HPP

#include "ast/function/magic_methods_table.hpp"
#include "ast/value/value.hpp"
#include "function/from_stack_getter.hpp"
#include "type/builtin_types_impl.hpp"

namespace fsc::builtin
{
    template<FscIntegral FscInt, typename BuiltinFunction>
    auto builtinUnaryFunction() -> ccl::Optional<ast::NodePtr>
    {
        auto value = stack::getVariable<FscInt>("value");

        if (!value.has_value()) {
            return std::nullopt;
        }

        auto [function_argument, ctx] = *value;
        auto argument_value = function_argument.value;

        auto evaluated = BuiltinFunction{}(argument_value);
        auto constructed_value = ccl::makeUnique<FscBuiltinType<FscInt>>(evaluated);

        return ccl::makeShared<ast::Value>(std::move(constructed_value), ctx);
    }
}// namespace fsc::builtin

#endif /* FSC_UNARY_HPP */
