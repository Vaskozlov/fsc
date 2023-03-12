#ifndef FSC_FROM_STACK_GETTER_HPP
#define FSC_FROM_STACK_GETTER_HPP

#include "stack/stack.hpp"
#include <ccl/ccl.hpp>

namespace fsc::builtin
{
    template<std::floating_point Float>
    static auto convertToFloatingPoint(ReprOrValue<Float> repr_or_value) -> Float
    {
        auto floating_point_value = Float{};

        if (repr_or_value.storesValue()) {
            floating_point_value = repr_or_value.getValue();
        } else {
            floating_point_value = static_cast<Float>(std::stod(repr_or_value.getRepr()));
        }

        return floating_point_value;
    }
}// namespace fsc::builtin

namespace fsc::stack
{
    template<typename T>
    static auto getVariable(const std::string &name) -> ccl::Optional<ccl::Pair<T, BasicContextPtr>>
    {
        auto argument = ProgramStack.get(name);
        auto argument_node = argument.getStoredValue();

        if (argument_node == nullptr) {
            return std::nullopt;
        }

        const auto *stored_value = argument_node->getValue();

        return ccl::Optional<ccl::Pair<T, BasicContextPtr>>{
            std::in_place, std::any_cast<T>(stored_value->getValue()),
            argument_node->getContext().value()};
    }
}// namespace fsc::stack

#endif /* FSC_FROM_STACK_GETTER_HPP */
