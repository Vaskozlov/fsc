#ifndef FSC_TYPE_HPP
#define FSC_TYPE_HPP

#include "ast/basic_node.hpp"
#include "exception.hpp"
#include "visibility.hpp"
#include <ccl/codegen/basic_codegen.hpp>
#include <compare>

namespace fsc
{
    struct CCL_TRIVIAL_ABI TypeInfo
    {
        size_t templatesParametersCount = 0;
        bool isTriviallyCopyable = false;
    };

    enum struct CreationType : ccl::u16
    {
        DEFAULT,
        TEMPLATE_KEEP_NAME,
        TEMPLATE_HIDE_NAME
    };

    template<ccl::ConstString String, typename T>
    struct FscTypeWrapper;

    class TypeManager;

    class CCL_TRIVIAL_ABI FscType
    {
    private:
        friend TypeManager;

        ccl::Id typeId{};

        explicit FscType(ccl::Id type_id, std::in_place_t /* unused */)
          : typeId{type_id}
        {}

    public:
        FscType() = default;

        explicit FscType(ccl::Id type_id) noexcept(false);

        template<ccl::ConstString String, typename T>
        // NOLINTNEXTLINE
        FscType(const FscTypeWrapper<String, T> &derived_type) noexcept
          : typeId{derived_type.typeId}
        {}

        explicit FscType(const std::string &type_name) noexcept(false);

        [[nodiscard]] auto operator==(FscType other) const noexcept -> bool;
        [[nodiscard]] auto operator<=>(FscType other) const noexcept -> std::weak_ordering;

        [[nodiscard]] auto getId() const noexcept -> ccl::Id
        {
            return typeId;
        }

        [[nodiscard]] auto isTemplate() const noexcept -> bool;

        [[nodiscard]] auto isRemapTemplate() const noexcept -> bool;

        [[nodiscard]] auto getName() const -> std::string;

        [[nodiscard]] auto getMemberVariable(const std::string &name) const -> ast::NodePtr;

        [[nodiscard]] auto hasMemberVariables(const std::string &name) const -> bool;

        [[nodiscard]] auto getClass() const noexcept(false) -> ast::NodePtr;

        auto addMemberVariable(ast::NodePtr variable) const -> void;

        [[nodiscard]] auto isTriviallyCopyable() const noexcept -> bool;
    };

    class FscTypeInterface : public FscType
    {
    public:
        FscTypeInterface() = default;

        explicit FscTypeInterface(ccl::Id id)
          : FscType{id}
        {}

        FscTypeInterface(const FscTypeInterface &) = default;
        FscTypeInterface(FscTypeInterface &&) noexcept = default;

        virtual ~FscTypeInterface() = default;

        auto operator=(const FscTypeInterface &) -> FscTypeInterface & = default;
        auto operator=(FscTypeInterface &&) noexcept -> FscTypeInterface & = default;

        [[nodiscard]] virtual auto toString() const -> std::string;
        [[nodiscard]] virtual auto getValue() const -> std::any = 0;
        virtual auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void;
    };

    auto operator<<(ccl::codegen::BasicCodeGenerator &generator, FscTypeInterface &fsc_type)
        -> ccl::codegen::BasicCodeGenerator &;
}// namespace fsc

template<>
struct std::hash<fsc::FscType>
{
    auto operator()(fsc::FscType type) const noexcept -> std::size_t;
};

template<>
struct fmt::formatter<fsc::FscType> : fmt::formatter<std::string>
{
    auto format(fsc::FscType fsc_type, format_context &ctx) const
    {
        return formatter<std::string>::format(fsc_type.getName(), ctx);
    }
};

namespace fsc
{
    auto hashTypes(ccl::Iterable auto &&container) -> ccl::Id
        requires std::is_same_v<std::remove_cvref_t<decltype(*container.begin())>, FscType>
    {
        constexpr static ccl::Id hash_magic = 31;

        auto result = ccl::Id{};

        for (auto elem : container) {
            result += std::hash<FscType>{}(elem);
            result *= hash_magic;
        }

        return result;
    }
}// namespace fsc

#endif /* FSC_TYPE_HPP */
