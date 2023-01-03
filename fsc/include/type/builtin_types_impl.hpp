#ifndef FSC_BUILTIN_TYPES_IMPL_HPP
#define FSC_BUILTIN_TYPES_IMPL_HPP

#include "type/builtin_types.hpp"
#include "type/type.hpp"
#include <fmt/format.h>

namespace fsc
{
    template<typename T>
    class FscBuiltinType : public FscType
    {
        T value;

    public:
        CCL_PERFECT_FORWARDING(U, T)
        explicit FscBuiltinType(U &&value_)
          : FscType{T::typeId}
          , value{std::forward<U>(value_)}
        {}

        [[nodiscard]] auto toString() const -> std::string final
        {
            return fmt::format("{}: {}", getTypeName(), value.value);
        }

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void final
        {
            if constexpr (std::is_same_v<Float32, T>) {
                fmt::format_to(output.getBackInserter(), "{:.8e}F", value.value);
            } else if constexpr (std::is_same_v<Float64, T>) {
                fmt::format_to(output.getBackInserter(), "{:.15e}", value.value);
            } else if constexpr (std::is_same_v<String, T>) {
                fmt::format_to(output.getBackInserter(), "String{{{}}}", value.value);
            } else {
                output << value.value;
            }
        }
    };

    extern template class FscBuiltinType<Int32>;
    extern template class FscBuiltinType<Int64>;

    extern template class FscBuiltinType<UInt32>;
    extern template class FscBuiltinType<UInt64>;

    extern template class FscBuiltinType<Float32>;
    extern template class FscBuiltinType<Float64>;

    extern template class FscBuiltinType<Bool>;

    extern template class FscBuiltinType<String>;
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_IMPL_HPP */
