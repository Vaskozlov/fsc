#include "type/type_manager.hpp"
#include "ast/container/class.hpp"
#include "function/functions_holder.hpp"

using namespace ccl;

namespace fsc
{
    CCL_INLINE auto TypeManager::getFrame() noexcept -> TypeManagerFrame &
    {
        static auto type_manager_frame = TypeManagerFrame{};
        return type_manager_frame;
    }

    CCL_INLINE auto TypeManager::getTypenameById() noexcept -> Map<Id, std::string> &
    {
        return getFrame().typenameById;
    }

    CCL_INLINE auto TypeManager::getTypeByName() noexcept -> Map<std::string, FscType> &
    {
        return getFrame().idByTypename;
    }

    CCL_INLINE auto TypeManager::getTypeFlags() noexcept -> Map<FscType, TypeFlags> &
    {
        return getFrame().typeFlags;
    }

    CCL_INLINE auto TypeManager::getTypesMemberVariables() noexcept
        -> Map<FscType, Map<std::string, ast::NodePtr>> &
    {
        return getFrame().memberVariables;
    }

    CCL_INLINE auto TypeManager::getTemplatedTypes() noexcept -> Set<FscType> &
    {
        return getFrame().templateTypes;
    }

    CCL_INLINE auto TypeManager::getRemapTypes() noexcept -> Map<ccl::Id, FscType> &
    {
        return getFrame().remapTypes;
    }

    CCL_INLINE auto TypeManager::getFscClasses() noexcept -> Map<FscType, ast::NodePtr> &
    {
        return getFrame().fscClasses;
    }

    CCL_INLINE auto TypeManager::generateUuid() noexcept -> Id
    {
        static constinit auto type_uuid_creator = std::atomic<ccl::Id>{0};

        return type_uuid_creator.fetch_add(1U, std::memory_order_relaxed);
    }

    CCL_INLINE auto TypeManager::templateTypeExists(const std::string &name) -> bool
    {
        const auto template_begin = name.find('<');

        if (template_begin == std::string::npos) {
            return false;
        }

        const auto base_name = name.substr(0, template_begin);
        auto template_name = name.substr(template_begin + 1);
        template_name.pop_back();

        if (exactTypeExists(base_name)) {
            instantiatedTemplate(base_name, template_name);
            return true;
        }

        return false;
    }

    CCL_INLINE auto TypeManager::exactTypeExists(const std::string &type_name) noexcept -> bool
    {
        return getTypeByName().contains(type_name);
    }

    CCL_INLINE auto
        TypeManager::postCreationSetupForTemplates(FscType type, CreationType creation_type) -> void
    {
        if (creation_type == CreationType::DEFAULT) {
            return;
        }

        getTemplatedTypes().emplace(type);

        // TODO: weak free
    }

    auto TypeManager::instantiatedTemplate(
        const std::string &base_name, const std::string &template_name) -> void
    {
        // TODO: add additional checks
        if (!exactTypeExists(base_name)) {
            throw std::invalid_argument{fmt::format("{} is not a valid type", base_name)};
        }

        createFromName(fmt::format("{}<{}>", base_name, template_name));
    }

    auto TypeManager::map(FscType key, FscType value) -> void
    {
        if (getRemapTypes().contains(key.getId())) {
            throw std::invalid_argument{
                fmt::format("Unable to map {} more than once at the same time", getTypename(key))};
        }

        getTemplatedTypes().emplace(key);
        getTypeByName().emplace(key.getName(), value);
        getRemapTypes().emplace(key.getId(), value);
    }

    auto TypeManager::unmap(FscType key) -> void
    {
        if (!getRemapTypes().contains(key.getId())) {
            throw std::invalid_argument{
                fmt::format("Unable to unmap {}, because it is not a key type", getTypename(key))};
        }

        getRemapTypes().erase(key.getId());
        getTypeByName().erase(getTypename(key));
    }

    auto TypeManager::hideTemplate(const std::string &type_name) -> void
    {
        // TODO: add checks
        getTypeByName().erase(type_name);
    }

    auto TypeManager::getTrueType(FscType type) -> FscType
    {
        while (getRemapTypes().contains(type.getId())) {
            type = getRemapTypes().at(type.getId());
        }

        return type;
    }

    auto TypeManager::getTypename(FscType type) -> std::string
    {
        type = getTrueType(type);

        return getTypenameById().at(type.getId());
    }

    auto TypeManager::isTemplate(FscType type) noexcept -> bool
    {
        return getTemplatedTypes().contains(type);
    }

    auto TypeManager::isRemapTemplate(FscType type) noexcept -> bool
    {
        return isTemplate(type) && getTrueType(type) != type;
    }

    auto TypeManager::isTriviallyCopyable(FscType type) noexcept -> bool
    {
        type = getTrueType(type);
        return getTypeFlags().at(type).isTriviallyCopyable;
    }

    auto TypeManager::exists(ccl::Id type_id) -> bool
    {
        return getTypenameById().contains(type_id);
    }

    auto TypeManager::exists(const std::string &name) -> bool
    {
        if (exactTypeExists(name)) {
            return true;
        }

        return templateTypeExists(name);
    }

    auto TypeManager::ensureTypeExists(const std::string &name) noexcept(false) -> void
    {
        if (!exists(name)) {
            throw FscException{fmt::format("{} is not a valid type", name)};
        }
    }

    auto TypeManager::addFscClass(ast::NodePtr class_node) -> void
    {
        const auto &fsc_class = class_node->as<ast::Class>();
        getFscClasses().emplace(fsc_class.getType(), std::move(class_node));
    }

    auto TypeManager::addMemberVariable(FscType type, ast::NodePtr variable_node) -> void
    {
        type = getTrueType(type);

        const auto &variable = ccl::as<ast::Variable &>(*variable_node);
        auto &class_variables = getTypesMemberVariables().at(type);

        class_variables.emplace(variable.getName(), std::move(variable_node));
    }

    auto TypeManager::hasMemberVariable(FscType type, const std::string &variable_name) -> bool
    {
        const auto &member_variables_map = getTypesMemberVariables();
        type = getTrueType(type);

        return member_variables_map.contains(type) &&
               member_variables_map.at(type).contains(variable_name);
    }

    auto TypeManager::getFscClass(FscType type) -> ast::NodePtr
    {
        const auto &fsc_classes = getFscClasses();
        type = getTrueType(type);

        if (!fsc_classes.contains(type)) {
            throw std::invalid_argument{
                fmt::format("{} is not a valid fsc class", getTypename(type))};
        }

        return fsc_classes.at(type);
    }

    auto TypeManager::getMemberVariable(FscType type, const std::string &member_variable_name)
        -> ast::NodePtr
    {
        if (!hasMemberVariable(type, member_variable_name)) {
            throw FscException{fmt::format(
                "{} does not have {} member variable", getTypename(type), member_variable_name)};
        }

        if (member_variable_name == "this") {
            // TODO: check for const reference
            return makeShared<ast::Variable>("*this", type, ast::VariableFlags{.reference = true});
        }

        return getTypesMemberVariables().at(type).at(member_variable_name);
    }

    auto TypeManager::createNewType(
        const std::string &type_name, TypeFlags type_flags, CreationType creation_type) -> FscType
    {
        static auto type_registration_mutex = std::mutex{};

        if (exactTypeExists(type_name)) {
            throw std::invalid_argument{fmt::format("Type {} already exists", type_name)};
        }

        const auto type = FscType{generateUuid(), std::in_place};
        const auto creation_lock = std::scoped_lock{type_registration_mutex};

        getTypeByName().emplace(type_name, type);
        getTypenameById().emplace(type.getId(), type_name);
        getTypeFlags().emplace(type, type_flags);
        getTypesMemberVariables().insert({type, {}});

        postCreationSetupForTemplates(type, creation_type);

        return type;
    }

    auto TypeManager::createFromName(const std::string &type_name) -> FscType
    {
        if (exactTypeExists(type_name)) {
            return getTypeByName().at(type_name);
        }

        const auto template_index = type_name.find('<');

        if (template_index != std::string::npos) {
            const auto base_name = type_name.substr(0, template_index);
            auto template_name = type_name.substr(template_index + 1);
            template_name.pop_back();

            if (!exactTypeExists(base_name)) {
                throw FscException{fmt::format("{} is not a valid type", base_name)};
            }

            if (!exists(template_name)) {
                throw FscException{fmt::format("{} is not a valid type", template_name)};
            }

            const auto new_type = createNewType(type_name, {});

            func::Functions.map(FscType{base_name}, new_type);
            return new_type;
        }

        return getTypeByName().at(type_name);
    }
}// namespace fsc