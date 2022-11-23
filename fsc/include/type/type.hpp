#ifndef FSC_TYPE_HPP
#define FSC_TYPE_HPP

#include "ast/variable.hpp"
#include "codegen.hpp"
#include "visibility.hpp"
#include <ccl/ccl.hpp>

namespace fsc {
    using TypeId = size_t;

    struct TypeFlags {
        bool isTriviallyCopyable : 1;
    };

    class FscType {
        static ccl::Map<TypeId, std::string> typenameById;
        static ccl::Map<std::string, TypeId> idByTypename;
        static ccl::Map<TypeId, TypeFlags> typeFlags;
        static ccl::Map<TypeId, ccl::Map<std::string, ccl::SharedPtr<ast::Variable>>>
                typeMemberVariables;

        TypeId typeId;

    public:
        explicit FscType(const TypeId type_id);
        explicit FscType(const std::string &type_name);

        FscType(const FscType &other) = default;
        FscType(FscType &&other) noexcept = default;

        virtual ~FscType() = default;

        auto operator=(const FscType &other) -> FscType & = default;
        auto operator=(FscType &&other) noexcept -> FscType & = default;

        [[nodiscard]] virtual auto toString() const -> std::string = 0;
        virtual auto codeGen(gen::CodeGenerator &output) const -> void = 0;

        [[nodiscard]] static auto isTriviallyCopyable(const TypeId id) -> bool
        {
            return typeFlags[id].isTriviallyCopyable;
        }

        [[nodiscard]] auto is(const TypeId id) const noexcept -> bool
        {
            return id == getId();
        }

        [[nodiscard]] auto getId() const noexcept -> TypeId
        {
            return typeId;
        }

        [[nodiscard]] auto getTypeName() const -> std::string
        {
            return FscType::getTypeName(getId());
        }

        [[nodiscard]] static auto exists(const TypeId type_id) -> bool
        {
            return typenameById.contains(type_id);
        }

        [[nodiscard]] static auto exists(const std::string &type_name) -> bool
        {
            return idByTypename.contains(type_name);
        }

        [[nodiscard]] static auto checkTypeExistence(const std::string &type_name) -> void;

        [[nodiscard]] static auto getTypeId(const std::string &type_name) -> TypeId
        {
            return idByTypename.at(type_name);
        }

        [[nodiscard]] static auto getTypeName(const TypeId type_id) -> std::string
        {
            return typenameById.at(type_id);
        }

        static auto registerNewType(const std::string &name, const TypeFlags flags) -> void;
        static auto addMemberVariable(TypeId type_id, ccl::SharedPtr<ast::Variable> variable)
                -> void;

        static auto hasMemberVariables(TypeId type_id, const std::string &name) -> bool;
        static auto getMemberVariable(TypeId type_id, const std::string &name)
                -> ccl::SharedPtr<ast::Variable>;
    };
}// namespace fsc

#endif /* FSC_TYPE_HPP */
