#ifndef FSC_BUILTIN_TYPES_IMPL_HPP
#define FSC_BUILTIN_TYPES_IMPL_HPP

#include "type/builtin_types.hpp"
#include "type/type.hpp"
#include <fmt/format.h>

namespace fsc
{
    template<typename T>
    class FscBuiltinType : public FscTypeInterface
    {
        T value;

    public:
        CCL_PERFECT_FORWARDING(U, T)
        explicit FscBuiltinType(U &&value_)
          : FscTypeInterface{T::typeId}
          , value{std::forward<U>(value_)}
        {}

        [[nodiscard]] auto toString() const -> std::string final
        {
            return fmt::format("{}: {}", getName(), value.value);
        }

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final
        {
            if constexpr (std::is_same_v<FscFloat32, T>) {
                fmt::format_to(output.getBackInserter(), "{:.8e}F", value.value);
            } else if constexpr (std::is_same_v<FscFloat64, T>) {
                fmt::format_to(output.getBackInserter(), "{:.15e}", value.value);
            } else if constexpr (std::is_same_v<FscString, T>) {
                fmt::format_to(output.getBackInserter(), "String{{{}}}", value.value);
            } else {
                output << value.value;
            }
        }
    };

    extern template class FscBuiltinType<FscFloat32>;
    extern template class FscBuiltinType<FscInt64>;

    extern template class FscBuiltinType<FscUInt32>;
    extern template class FscBuiltinType<FscUInt64>;

    extern template class FscBuiltinType<FscFloat32>;
    extern template class FscBuiltinType<FscFloat64>;

    extern template class FscBuiltinType<FscBool>;

    extern template class FscBuiltinType<FscString>;
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_IMPL_HPP */
