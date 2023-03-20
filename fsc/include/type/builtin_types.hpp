#ifndef FSC_BUILTIN_TYPES_HPP
#define FSC_BUILTIN_TYPES_HPP

#include "ccl/string_view.hpp"
#include "type/type_manager.hpp"
#include <ccl/ccl.hpp>
#include <ccl/const_string.hpp>
#include <utility>

#define FSC_WRAP_TYPE(TypeName, TypeRepr, StoredType)                                              \
    class Fsc##TypeName : public FscTypeWrapper<TypeRepr, StoredType>                              \
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
    template<ccl::ConstString String, typename T>
    struct FscTypeWrapper;

    template<typename T>
    class ReprOrValue
    {
    private:
        using StoredVariant = std::variant<T, std::string>;

        StoredVariant value{};

    public:
        ReprOrValue() = default;

        template<typename... Ts>
        constexpr ReprOrValue(Ts &&...args)// NOLINT
            requires std::constructible_from<T, Ts...>
          : value{std::in_place_index<0>, std::forward<Ts>(args)...} {};

        template<typename... Ts>
        constexpr ReprOrValue(Ts &&...args)// NOLINT
            requires std::constructible_from<std::string, Ts...>
          : value{std::in_place_index<1>, std::forward<Ts>(args)...} {};

        CCL_DECL auto storesValue() const noexcept -> bool
        {
            return value.index() == 0;
        }

        CCL_DECL auto storesString() const noexcept -> bool
        {
            return !storesValue();
        }

        CCL_DECL auto getValue() const noexcept
            -> std::conditional_t<std::is_trivial_v<T>, T, const T &>
        {
            return std::get<0>(value);
        }

        CCL_DECL auto getRepr() const noexcept -> const std::string &
        {
            return std::get<1>(value);
        }

        CCL_DECL auto toString() const noexcept -> std::string
        {
            if (storesValue()) {
                return fmt::to_string(getValue());
            }

            return getRepr();
        }

        auto setValue(T &&new_value) noexcept -> void
        {
            value = std::move(new_value);
        }

        auto setValue(const T &new_value) noexcept -> void
        {
            value = std::move(new_value);
        }

        auto setValue(std::string &&new_value) noexcept -> void
        {
            value = std::move(new_value);
        }

        auto setValue(const std::string &new_value) noexcept -> void
        {
            value = new_value;
        }
    };

    template<ccl::ConstString String>
    struct FscTypeWrapper<String, void>
    {
        inline constinit static ccl::Id typeId = 0;

        static auto initialize(TypeInfo type_info, CreationType creation_type) -> void
        {
            typeId = TypeManager::createNewType(
                         static_cast<std::string>(String), type_info, creation_type)
                         .getId();
        }
    };

    template<ccl::ConstString String, typename T>
    struct FscTypeWrapper
    {
    public:
        inline constinit static ccl::Id typeId = 0;

        static auto initialize(TypeInfo type_info, CreationType creation_type) -> void
        {
            typeId = TypeManager::createNewType(
                         static_cast<std::string>(String), type_info, creation_type)
                         .getId();
        }

        T value;

        FscTypeWrapper() = default;

        CCL_PERFECT_FORWARDING(U, T)
        explicit FscTypeWrapper(U &&initial_value)
          : value{std::forward<U>(initial_value)}
        {}
    };

    struct VoidType : FscTypeWrapper<"void", void>
    {
    };

    struct AutoType : FscTypeWrapper<"auto", void>
    {
    };

    struct VectorType : FscTypeWrapper<"Vector", void>
    {
    };

    inline constexpr auto Void = VoidType{};
    inline constexpr auto Auto = AutoType{};
    inline constexpr auto VectorTemplate = VectorType{};

    FSC_WRAP_TYPE(Bool, "bool", bool);

    FSC_WRAP_TYPE(Int32, "i32", ccl::i32);
    FSC_WRAP_TYPE(UInt32, "u32", ccl::u32);
    FSC_WRAP_TYPE(Int64, "i64", ccl::i64);
    FSC_WRAP_TYPE(UInt64, "u64", ccl::u64);
    FSC_WRAP_TYPE(Float32, "f32", ReprOrValue<ccl::f32>);
    FSC_WRAP_TYPE(Float64, "f64", ReprOrValue<ccl::f64>);

    FSC_WRAP_TYPE(Char, "char", char);
    FSC_WRAP_TYPE(String, "String", std::string);

    FSC_WRAP_TYPE(Template1, "_FSC_TEMPLATE_1", void);
    FSC_WRAP_TYPE(Template2, "_FSC_TEMPLATE_2", void);
    FSC_WRAP_TYPE(Template3, "_FSC_TEMPLATE_3", void);
    FSC_WRAP_TYPE(Template4, "_FSC_TEMPLATE_4", void);

    namespace builtin
    {
        auto initializeCompilerBuiltin() -> void;
    }
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_HPP */
