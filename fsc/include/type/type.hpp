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

    class CCL_TRIVIAL_ABI FscType
    {
    private:
        using TypenameByIdStorage = ccl::Map<ccl::Id, std::string>;
        using IdByTypenameStorage = ccl::Map<std::string, ccl::Id>;
        using TypeFlagsStorage = ccl::Map<FscType, TypeFlags>;
        using TypesMemberVariablesStorage = ccl::Map<FscType, ccl::Map<std::string, ast::NodePtr>>;
        using TemplatedTypesStorage = ccl::Set<FscType>;
        using RemapTypesStorage = ccl::Map<FscType, FscType>;
        using FscClasses = ccl::Map<FscType, ast::NodePtr>;

        struct FscTypeVariables
        {
            TypenameByIdStorage typenameById;
            IdByTypenameStorage idByTypename;
            TypeFlagsStorage typeFlags;
            TypesMemberVariablesStorage typeMemberVariables;
            TemplatedTypesStorage templateTypes;
            RemapTypesStorage remapTypes;
            FscClasses fscClasses;
        };

        static auto getVariables() noexcept -> FscTypeVariables &;

        static auto getTypenameById() noexcept -> TypenameByIdStorage &;
        static auto getIdByTypename() noexcept -> IdByTypenameStorage &;
        static auto getTypeFlags() noexcept -> TypeFlagsStorage &;
        static auto getTypesMemberVariables() noexcept -> TypesMemberVariablesStorage &;
        static auto getTemplatedTypes() noexcept -> TemplatedTypesStorage &;
        static auto getRemapTypes() noexcept -> RemapTypesStorage &;
        static auto getFscClasses() noexcept -> FscClasses &;

        ccl::Id typeId{};

    public:
        FscType() = default;

        explicit FscType(ccl::Id type_id) noexcept(false)
          : typeId{type_id}
        {
            if (!exists(typeId)) [[unlikely]] {
                throw FscException{"Type not found"};
            }
        }

        template<ccl::ConstString String, typename T>
        // NOLINTNEXTLINE
        FscType(const FscTypeWrapper<String, T> &derived_type) noexcept
          : typeId{derived_type.typeId}
        {}

        explicit FscType(const std::string &type_name) noexcept(false);

        auto operator<=>(const FscType &other) const noexcept -> std::weak_ordering = default;

        [[nodiscard]] auto getId() const noexcept -> ccl::Id
        {
            return typeId;
        }

        auto map(FscType target_type) const -> void;

        auto unmap() const noexcept -> void;

        [[nodiscard]] auto isTemplate() const noexcept -> bool;

        [[nodiscard]] auto getName() const -> std::string;

        [[nodiscard]] auto getMemberVariable(const std::string &name) const -> ast::NodePtr;

        [[nodiscard]] auto getTrueType() const noexcept -> FscType;

        [[nodiscard]] auto hasMemberVariables(const std::string &name) const -> bool;

        [[nodiscard]] auto getClass() const noexcept(false) -> ast::NodePtr;

        auto addMemberVariable(ast::NodePtr variable) const -> void;

        [[nodiscard]] auto isTriviallyCopyable() const noexcept -> bool;

        [[nodiscard]] static auto exists(ccl::Id type_id) -> bool;

        [[nodiscard]] static auto exists(const std::string &type_name) -> bool;

        static auto ensureTypeExists(const std::string &type_name) -> void;

        static auto weakFreeTemplateType(const std::string &type_name) -> void;

        static auto registerNewType(
            const std::string &name, TypeFlags flags,
            CreationType creation_type = CreationType::DEFAULT) noexcept(false) -> ccl::Id;

        static auto registerFscClass(ast::NodePtr new_fsc_class) -> void;

    private:
        static auto templateTypeExist(const std::string &name) -> bool;

        static auto
            registerInstantiatedTemplate(const std::string &full_name, const std::string &base_name)
                -> void;

        static auto registerInstantiatedTemplate(const std::string &full_name) -> void;
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
