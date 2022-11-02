#ifndef FSC_BUILTIN_TYPES_IMPL_HPP
#define FSC_BUILTIN_TYPES_IMPL_HPP

#include "type/builtin_types.hpp"
#include "type/type.hpp"
#include <fmt/format.h>

namespace fsc {
    template<typename T>
    class FscBuiltinType : public FscType {
        T value;

    public:
        explicit FscBuiltinType(const T &value_, ValueOptions value_options)
            : FscType(T::typeId, value_options), value(value_)
        {}

        explicit FscBuiltinType(T &&value_, ValueOptions value_options)
            : FscType(T::typeId, value_options), value(std::move(value_))
        {}

        auto toString() const -> std::string final
        {
            return fmt::format("{}: {}", getTypeName(), value.value);
        }

        auto codeGen(gen::CodeGenerator &output) const -> void final
        {
            if constexpr (std::is_same_v<Float32, T>) {
                fmt::format_to(output.getBackInserter(), "{}F", value.value);
            } else {
                fmt::format_to(output.getBackInserter(), "{}", value.value);
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
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_IMPL_HPP */
