#ifndef FSC_TYPE_HPP
#define FSC_TYPE_HPP

#include "ast/value/variable.hpp"
#include "visibility.hpp"
#include <ccl/ccl.hpp>
#include <ccl/codegen/basic_codegen.hpp>

namespace fsc
{
    struct TypeFlags
    {
        bool isTriviallyCopyable = false;
    };

    class FscType
    {
        static ccl::Map<ccl::Id, std::string> typenameById;
        static ccl::Map<std::string, ccl::Id> idByTypename;
        static ccl::Map<ccl::Id, TypeFlags> typeFlags;
        static ccl::Map<ccl::Id, ccl::Map<std::string, ccl::SharedPtr<ast::Variable>>>
            typeMemberVariables;
        static ccl::Set<ccl::Id> templateTypes;

        ccl::Id typeId;

    public:
        explicit FscType(const ccl::Id type_id);
        explicit FscType(const std::string &type_name);

        FscType(const FscType &other) = default;
        FscType(FscType &&other) noexcept = default;

        virtual ~FscType() = default;

        auto operator=(const FscType &other) -> FscType & = default;
        auto operator=(FscType &&other) noexcept -> FscType & = default;

        [[nodiscard]] virtual auto toString() const -> std::string = 0;
        virtual auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void = 0;

        [[nodiscard]] static auto isTriviallyCopyable(const ccl::Id id) -> bool
        {
            return typeFlags[id].isTriviallyCopyable;
        }

        [[nodiscard]] auto is(ccl::Id id) const noexcept -> bool
        {
            return id == getId();
        }

        [[nodiscard]] auto getId() const noexcept -> ccl::Id
        {
            return typeId;
        }

        [[nodiscard]] auto getTypeName() const -> std::string
        {
            return FscType::getTypeName(getId());
        }

        [[nodiscard]] static auto exists(const ccl::Id type_id) -> bool
        {
            return typenameById.contains(type_id);
        }

        [[nodiscard]] static auto exists(const std::string &type_name) -> bool
        {
            return idByTypename.contains(type_name);
        }

        [[nodiscard]] static auto isTemplate(ccl::Id id) noexcept -> bool;

        [[nodiscard]] static auto ensureTypeExists(const std::string &type_name) -> void;

        [[nodiscard]] static auto getTypeId(const std::string &type_name) -> ccl::Id
        {
            return idByTypename.at(type_name);
        }

        [[nodiscard]] static auto getTypeName(const ccl::Id type_id) -> std::string
        {
            return typenameById.at(type_id);
        }

        static auto registerTemplate(const std::string &type_name) -> void;

        static auto freeTemplateType(const std::string &type_name) -> void;

        static auto registerNewType(const std::string &name, const TypeFlags flags) noexcept(false)
            -> void;

        static auto addMemberVariable(ccl::Id type_id, ccl::SharedPtr<ast::Variable> variable)
            -> void;

        static auto hasMemberVariables(ccl::Id type_id, const std::string &name) -> bool;

        static auto getMemberVariable(ccl::Id type_id, const std::string &name)
            -> ccl::SharedPtr<ast::Variable>;
    };

    auto operator<<(ccl::codegen::BasicCodeGenerator &generator, const FscType &fsc_type)
        -> ccl::codegen::BasicCodeGenerator &;
}// namespace fsc

#endif /* FSC_TYPE_HPP */
