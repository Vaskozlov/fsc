#ifndef FSC_BUILTIN_TYPES_IMPL_HPP
#define FSC_BUILTIN_TYPES_IMPL_HPP

#include "type/builtin_types.hpp"
#include "type/type.hpp"
#include <fmt/format.h>

namespace fsc
{
    template<typename T>
    concept HasToString = requires(const T &object) { object.toString(); };

    template<typename T>
    class FscBuiltinType : public FscTypeInterface
    {
        [[no_unique_address]] T value;

    public:
        template<typename... Ts>
        explicit FscBuiltinType(FscType type, Ts &&...args)
          : FscTypeInterface{type.getId()}
          , value{std::forward<Ts>(args)...}
        {}

        [[nodiscard]] auto toString() const -> std::string final
        {
            if constexpr (std::is_same_v<VoidType, T>) {
                return "void";
            } else if constexpr (!HasToString<T>) {
                return fmt::format("{}", value.value);
            } else {
                return fmt::format("{}", value.toString());
            }
        }

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final
        {
            if constexpr (std::is_same_v<VoidType, T>) {
                fmt::format_to(output.getBackInserter(), "void");
            } else if constexpr (std::is_same_v<ReprOrValue<ccl::f32>, T>) {
                fmt::format_to(output.getBackInserter(), "float({})", value.toString());
            } else if constexpr (std::is_same_v<ReprOrValue<ccl::f64>, T>) {
                fmt::format_to(output.getBackInserter(), "double({})", value.toString());
            } else if constexpr (std::is_same_v<FscString, T>) {
                fmt::format_to(output.getBackInserter(), "String{{{}}}", value.value);
            } else {
                output << value.value;
            }
        }
    };

    extern template class FscBuiltinType<VoidType>;

    extern template class FscBuiltinType<FscInt32>;
    extern template class FscBuiltinType<FscInt64>;

    extern template class FscBuiltinType<FscUInt32>;
    extern template class FscBuiltinType<FscUInt64>;

    extern template class FscBuiltinType<ReprOrValue<ccl::f32>>;
    extern template class FscBuiltinType<ReprOrValue<ccl::f64>>;

    extern template class FscBuiltinType<FscBool>;

    extern template class FscBuiltinType<FscString>;
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_IMPL_HPP */
