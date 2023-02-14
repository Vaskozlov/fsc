#ifndef FSC_BUILTIN_TYPES_HPP
#define FSC_BUILTIN_TYPES_HPP

#include "ccl/string_view.hpp"
#include "type/type.hpp"
#include "uuid_factory.hpp"
#include <ccl/ccl.hpp>
#include <ccl/const_string.hpp>
#include <utility>

#define FSC_WRAP_TYPE(TypeName, TypeRepr, StoredType, WayOfCreatingNewType)                        \
    class Fsc##TypeName : public FscTypeWrapper<TypeRepr, StoredType, WayOfCreatingNewType>        \
    {                                                                                              \
    public:                                                                                        \
        Fsc##TypeName() = default;                                                                 \
                                                                                                   \
        CCL_PERFECT_FORWARDING(FSC_T, StoredType)                                                  \
        Fsc##TypeName(FSC_T &&initial_value)                                                       \
          : FscTypeWrapper{std::forward<FSC_T>(initial_value)}                                     \
        {}                                                                                         \
    };                                                                                             \
                                                                                                   \
    inline auto TypeName = Fsc##TypeName{};


namespace fsc
{
    inline UuidFactory TypeFactory{0};

    template<ccl::ConstString String, typename T, CreationType WayOfCreatingNewType>
    struct FscTypeWrapper;

    template<ccl::ConstString String, CreationType WayOfCreatingNewType>
    struct FscTypeWrapper<String, void, WayOfCreatingNewType>
    {
        inline const static ccl::Id typeId = FscType::registerNewType(
            static_cast<std::string>(static_cast<ccl::string_view>(String)), {},
            WayOfCreatingNewType);
    };

    template<ccl::ConstString String, typename T, CreationType WayOfCreatingNewType>
    class FscTypeWrapper
    {
    public:
        inline const static ccl::Id typeId = FscType::registerNewType(
            static_cast<std::string>(static_cast<ccl::string_view>(String)), {},
            WayOfCreatingNewType);

        T value;

        FscTypeWrapper() = default;

        CCL_PERFECT_FORWARDING(U, T)
        explicit FscTypeWrapper(U &&initial_value)
          : value{std::forward<U>(initial_value)}
        {}
    };

    struct VoidT : FscTypeWrapper<"void", void, CreationType::DEFAULT>
    {
    };

    struct AutoT : FscTypeWrapper<"auto", void, CreationType::DEFAULT>
    {
    };

    constexpr auto Void = VoidT{};
    constexpr auto Auto = AutoT{};

    FSC_WRAP_TYPE(Bool, "bool", bool, CreationType::DEFAULT);

    FSC_WRAP_TYPE(Int32, "i32", ccl::i32, CreationType::DEFAULT);
    FSC_WRAP_TYPE(UInt32, "u32", ccl::u32, CreationType::DEFAULT);
    FSC_WRAP_TYPE(Int64, "i64", ccl::i64, CreationType::DEFAULT);
    FSC_WRAP_TYPE(UInt64, "u64", ccl::u64, CreationType::DEFAULT);
    FSC_WRAP_TYPE(Float32, "f32", ccl::f32, CreationType::DEFAULT);
    FSC_WRAP_TYPE(Float64, "f64", ccl::f64, CreationType::DEFAULT);

    FSC_WRAP_TYPE(Char, "char", char, CreationType::DEFAULT);
    FSC_WRAP_TYPE(String, "String", std::string, CreationType::DEFAULT);

    FSC_WRAP_TYPE(Template1, "T1", void, CreationType::WEAK_TEMPLATE);
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_HPP */
