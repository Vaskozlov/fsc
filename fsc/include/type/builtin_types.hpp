#ifndef FSC_BUILTIN_TYPES_HPP
#define FSC_BUILTIN_TYPES_HPP

#include "ccl/string_view.hpp"
#include "type/type.hpp"
#include "uuid_factory.hpp"
#include <ccl/ccl.hpp>
#include <ccl/const_string.hpp>
#include <utility>

#define FSC_WRAP_TYPE(TypeName, TypeRepr, StoredType)                                              \
    class TypeName : public FscTypeWrapper<TypeRepr, StoredType>                                   \
    {                                                                                              \
    public:                                                                                        \
        TypeName() = default;                                                                      \
                                                                                                   \
        CCL_PERFECT_FORWARDING(FSC_T, StoredType)                                                  \
        TypeName(FSC_T &&initial_value)                                                            \
          : FscTypeWrapper{std::forward<FSC_T>(initial_value)}                                     \
        {}                                                                                         \
    }


namespace fsc
{
    inline UuidFactory TypeFactory{0};

    template<ccl::ConstString String, typename T>
    struct FscTypeWrapper;

    template<>
    struct FscTypeWrapper<"void", void>
    {
        inline const static ccl::Id typeId = FscType::registerNewType("void", {});
    };

    template<ccl::ConstString String, typename T>
    class FscTypeWrapper
    {
    public:
        inline const static ccl::Id typeId = FscType::registerNewType(
            static_cast<std::string>(static_cast<ccl::string_view>(String)), {});

        T value;

        FscTypeWrapper() = default;

        CCL_PERFECT_FORWARDING(U, T)
        explicit FscTypeWrapper(U &&initial_value)
          : value{std::forward<U>(initial_value)}
        {}
    };

    struct VoidT : FscTypeWrapper<"void", void>
    {
    };

    struct AutoT
    {
        inline const static ccl::Id typeId = FscType::registerNewType("auto", {});
    };

    constexpr auto Void = VoidT{};
    constexpr auto Auto = AutoT{};

    FSC_WRAP_TYPE(Bool, "bool", bool);

    FSC_WRAP_TYPE(Int32, "i32", ccl::i32);
    FSC_WRAP_TYPE(UInt32, "u32", ccl::u32);
    FSC_WRAP_TYPE(Int64, "i64", ccl::i64);
    FSC_WRAP_TYPE(UInt64, "u64", ccl::u64);
    FSC_WRAP_TYPE(Float32, "f32", ccl::f32);
    FSC_WRAP_TYPE(Float64, "f64", ccl::f64);

    FSC_WRAP_TYPE(Char, "char", char);
    FSC_WRAP_TYPE(String, "String", std::string);
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_HPP */
