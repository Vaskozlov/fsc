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
            ccl::UnorderedMap<ccl::Id, std::string> typenameById;
            ccl::UnorderedMap<std::string, FscType> idByTypename;
            ccl::UnorderedMap<FscType, TypeInfo> typeInfo;
            ccl::UnorderedMap<FscType, ccl::Map<std::string, ast::NodePtr>> memberVariables;
            ccl::UnorderedSet<FscType> templateTypes;
            ccl::UnorderedMap<ccl::Id, FscType> remapTypes;
            ccl::UnorderedMap<FscType, ast::NodePtr> fscClasses;
            ccl::UnorderedMap<FscType, ccl::Map<FscType, FscType>> instantiatedTemplates;
        };

        [[nodiscard]] static auto getFrame() noexcept -> TypeManagerFrame &;

        [[nodiscard]] static auto getTypenameById() noexcept
            -> ccl::UnorderedMap<ccl::Id, std::string> &;

        [[nodiscard]] static auto getTypeByName() noexcept
            -> ccl::UnorderedMap<std::string, FscType> &;

        [[nodiscard]] static auto getTypeInfo() noexcept -> ccl::UnorderedMap<FscType, TypeInfo> &;

        [[nodiscard]] static auto getTypesMemberVariables() noexcept
            -> ccl::UnorderedMap<FscType, ccl::Map<std::string, ast::NodePtr>> &;

        [[nodiscard]] static auto getTemplatedTypes() noexcept -> ccl::UnorderedSet<FscType> &;

        [[nodiscard]] static auto getRemapTypes() noexcept -> ccl::UnorderedMap<ccl::Id, FscType> &;

        [[nodiscard]] static auto getInstantiatedTemplates() noexcept
            -> ccl::UnorderedMap<FscType, ccl::Map<FscType, FscType>> &;

        [[nodiscard]] static auto getFscClasses() noexcept
            -> ccl::UnorderedMap<FscType, ast::NodePtr> &;

    public:
        static auto hideTemplate(const std::string &type_name) -> void;

        [[nodiscard]] static auto getTypename(FscType type) -> std::string;

        [[nodiscard]] static auto isTemplate(FscType type) noexcept -> bool;

        [[nodiscard]] static auto isRemapTemplate(FscType type) noexcept -> bool;

        [[nodiscard]] static auto isTriviallyCopyable(FscType type) noexcept -> bool;

        [[nodiscard]] static auto exists(ccl::Id type_id) -> bool;

        [[nodiscard]] static auto exists(const std::string &name) -> bool;

        static auto ensureTypeExists(const std::string &name) noexcept(false) -> void;

        [[nodiscard]] static auto getInfoAboutType(FscType type) -> TypeInfo;

        static auto updateTypeInfo(FscType type, TypeInfo type_info) -> void;

        static auto addFscClass(ast::NodePtr class_node) -> void;

        static auto addMemberVariable(FscType type, ast::NodePtr variable_node) -> void;

        [[nodiscard]] static auto hasMemberVariable(FscType type, const std::string &variable_name)
            -> bool;

        [[nodiscard]] static auto getFscClass(FscType type) -> ast::NodePtr;

        [[nodiscard]] static auto getInstantiatedTemplate(FscType fsc_class, FscType type)
            -> FscType;

        [[nodiscard]] static auto
            getMemberVariable(FscType type, const std::string &member_variable_name)
                -> ast::NodePtr;

        [[nodiscard]] static auto getMemberVariables(FscType type)
            -> const ccl::Map<std::string, ast::NodePtr> &;

        static auto createNewType(
            const std::string &type_name,
            TypeInfo type_flags,
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

        [[nodiscard]] static auto hash(FscType type) noexcept -> size_t;

    private:
        [[nodiscard]] static auto generateUuid() noexcept -> ccl::Id;

        [[nodiscard]] static auto exactTypeExists(const std::string &type_name) noexcept -> bool;

        [[nodiscard]] static auto templateTypeExists(const std::string &name) -> bool;

        static auto postCreationSetupForTemplates(FscType type, CreationType creation_type) -> void;

        static auto
            instantiatedTemplate(const std::string &base_name, const std::string &template_name)
                -> FscType;

        static auto map(FscType key, FscType value) -> void;

        static auto unmap(FscType key) -> void;

        [[nodiscard]] static auto getTrueType(FscType type) -> FscType;
    };

    using AcquireTypeMapType = decltype(TypeManager::acquireTypeMap(FscType{}, FscType{}));
}// namespace fsc

#endif /* FSC_TYPE_MANAGER_HPP */
