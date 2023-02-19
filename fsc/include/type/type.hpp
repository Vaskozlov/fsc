#ifndef FSC_TYPE_HPP
#define FSC_TYPE_HPP

#include "ast/basic_node.hpp"
#include "exception.hpp"
#include "visibility.hpp"
#include <ccl/ccl.hpp>
#include <ccl/codegen/basic_codegen.hpp>
#include <compare>

namespace fsc
{
    namespace ast
    {
        class Class;
    }

    struct TypeFlags
    {
        bool isTriviallyCopyable = false;
    };

    enum struct CreationType : ccl::u16
    {
        DEFAULT,
        STRONG_TEMPLATE,
        WEAK_TEMPLATE
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
        virtual auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void;
    };

    auto operator<<(ccl::codegen::BasicCodeGenerator &generator, FscTypeInterface &fsc_type)
        -> ccl::codegen::BasicCodeGenerator &;
}// namespace fsc

template<>
struct fmt::formatter<fsc::FscType> : fmt::formatter<std::string>
{
    auto format(fsc::FscType fsc_type, format_context &ctx) const
    {
        return formatter<std::string>::format(fsc_type.getName(), ctx);
    }
};


#endif /* FSC_TYPE_HPP */
