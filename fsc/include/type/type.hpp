#ifndef FSC_TYPE_HPP
#define FSC_TYPE_HPP

#include "ast/basic_node.hpp"
#include "exception.hpp"
#include "visibility.hpp"
#include <ccl/ccl.hpp>
#include <ccl/codegen/basic_codegen.hpp>
#include <compare>
#include <concepts>

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

    template<ccl::ConstString String, typename T>
    struct FscTypeWrapper;

    class CCL_TRIVIAL_ABI FscType// NOLINT (non virtual destructor)
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

        static auto getVariables() -> FscTypeVariables &;

        static auto getTypenameById() -> TypenameByIdStorage &
        {
            return getVariables().typenameById;
        }

        static auto getIdByTypename() -> IdByTypenameStorage &
        {
            return getVariables().idByTypename;
        }

        static auto getTypeFlags() -> TypeFlagsStorage &
        {
            return getVariables().typeFlags;
        }

        static auto getTypesMemberVariables() -> TypesMemberVariablesStorage &
        {
            return getVariables().typeMemberVariables;
        }

        static auto getTemplatedTypes() -> TemplatedTypesStorage &
        {
            return getVariables().templateTypes;
        }

        static auto getRemapTypes() -> RemapTypesStorage &
        {
            return getVariables().remapTypes;
        }

        static auto getFscClasses() -> FscClasses &
        {
            return getVariables().fscClasses;
        }

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
        FscType(const FscTypeWrapper<String, T> &derived_type) noexcept
          : typeId{derived_type.typeId}
        {}

        explicit FscType(const std::string &type_name) noexcept(false);

        auto operator<=>(const FscType &other) const noexcept -> std::weak_ordering = default;

        [[nodiscard]] virtual auto toString() const -> std::string;

        virtual auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void;

        auto map(FscType target_type) const -> void;
        auto unmap() const noexcept -> void;

        [[nodiscard]] auto getId() const noexcept -> ccl::Id
        {
            return typeId;
        }

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

        static auto registerTemplate(const std::string &type_name) -> void;

        static auto freeTemplateType(const std::string &type_name) -> void;

        static auto registerNewType(const std::string &name, TypeFlags flags) noexcept(false)
            -> ccl::Id;

        static auto registerFscClass(ast::NodePtr new_fsc_class) -> void;
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
    };

    auto operator<<(ccl::codegen::BasicCodeGenerator &generator, const FscType &fsc_type)
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
