#ifndef FSC_TYPE_MANAGER_HPP
#define FSC_TYPE_MANAGER_HPP

#include "type/type.hpp"
#include <ccl/raii.hpp>

namespace fsc
{
    class TypeManager
    {
    private:
        friend class FscType;

        struct TypeManagerFrame
        {
            ccl::Map<ccl::Id, std::string> typenameById;
            ccl::Map<std::string, FscType> idByTypename;
            ccl::Map<FscType, TypeFlags> typeFlags;
            ccl::Map<FscType, ccl::Map<std::string, ast::NodePtr>> memberVariables;
            ccl::Set<FscType> templateTypes;
            ccl::Map<ccl::Id, FscType> remapTypes;
            ccl::Map<FscType, ast::NodePtr> fscClasses;
        };

        [[nodiscard]] static auto getFrame() noexcept -> TypeManagerFrame &;

        [[nodiscard]] static auto getTypenameById() noexcept -> ccl::Map<ccl::Id, std::string> &;

        [[nodiscard]] static auto getTypeByName() noexcept -> ccl::Map<std::string, FscType> &;

        [[nodiscard]] static auto getTypeFlags() noexcept -> ccl::Map<FscType, TypeFlags> &;

        [[nodiscard]] static auto getTypesMemberVariables() noexcept
            -> ccl::Map<FscType, ccl::Map<std::string, ast::NodePtr>> &;

        [[nodiscard]] static auto getTemplatedTypes() noexcept -> ccl::Set<FscType> &;

        [[nodiscard]] static auto getRemapTypes() noexcept -> ccl::Map<ccl::Id, FscType> &;

        [[nodiscard]] static auto getFscClasses() noexcept -> ccl::Map<FscType, ast::NodePtr> &;

    public:
        static auto hideTemplate(const std::string &type_name) -> void;

        [[nodiscard]] static auto getTypename(FscType type) -> std::string;

        [[nodiscard]] static auto isTemplate(FscType type) noexcept -> bool;

        [[nodiscard]] static auto isRemapTemplate(FscType type) noexcept -> bool;

        [[nodiscard]] static auto isMap(FscType type) -> void;

        [[nodiscard]] static auto isTriviallyCopyable(FscType type) noexcept -> bool;

        [[nodiscard]] static auto exists(ccl::Id type_id) -> bool;

        [[nodiscard]] static auto exists(const std::string &name) -> bool;

        static auto ensureTypeExists(const std::string &name) noexcept(false) -> void;

        static auto addFscClass(ast::NodePtr class_node) -> void;

        static auto addMemberVariable(FscType type, ast::NodePtr variable_node) -> void;

        [[nodiscard]] static auto hasMemberVariable(FscType type, const std::string &variable_name)
            -> bool;

        [[nodiscard]] static auto getFscClass(FscType type) -> ast::NodePtr;

        [[nodiscard]] static auto
            getMemberVariable(FscType type, const std::string &member_variable_name)
                -> ast::NodePtr;

        static auto createNewType(
            const std::string &type_name, TypeFlags type_flags = TypeFlags{},
            CreationType creation_type = CreationType::DEFAULT) -> FscType;

        [[nodiscard]] static auto createFromName(const std::string &type_name) -> FscType;

        [[nodiscard]] static auto acquireTypeMap(FscType key, FscType value) -> auto
        {
            return ccl::Raii(
                [key, value]() {
                    TypeManager::map(key, value);
                },
                [key]() {
                    TypeManager::unmap(key);
                });
        }

    private:
        [[nodiscard]] static auto generateUuid() noexcept -> ccl::Id;

        [[nodiscard]] static auto exactTypeExists(const std::string &type_name) noexcept -> bool;

        [[nodiscard]] static auto templateTypeExists(const std::string &name) -> bool;

        static auto postCreationSetupForTemplates(FscType type, CreationType creation_type) -> void;

        static auto
            instantiatedTemplate(const std::string &base_name, const std::string &template_name)
                -> void;

        static auto map(FscType key, FscType value) -> void;

        static auto unmap(FscType key) -> void;

        [[nodiscard]] static auto getTrueType(FscType type) -> FscType;
    };
}// namespace fsc

#endif /* FSC_TYPE_MANAGER_HPP */
