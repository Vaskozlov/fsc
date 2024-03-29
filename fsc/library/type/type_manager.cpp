#include "type/type_manager.hpp"
#include "ast/container/class.hpp"
#include "function/functions_holder.hpp"
#include <range/v3/view.hpp>

using namespace ccl;

namespace fsc
{
    static auto checkTemplatePackCorrect(const std::string &templates) -> Vector<FscType>
    {
        auto result = Vector<FscType>{};

        for (auto rng : templates | ranges::views::split(',')) {
            const auto template_name =
                ccl::string_view{&*rng.begin(), as<size_t>(ranges::distance(rng))};
            auto converted_name = std::string{template_name.strip(" ")};

            if (!TypeManager::exists(converted_name)) {
                throw std::invalid_argument{fmt::format("{} is not a valid type", template_name)};
            }

            result.emplace_back(std::move(converted_name));
        }

        return result;
    }

    auto TypeManager::getFrame() noexcept -> TypeManagerFrame &
    {
        static auto type_manager_frame = TypeManagerFrame{};
        return type_manager_frame;
    }

    auto TypeManager::getTypenameById() noexcept -> UnorderedMap<Id, std::string> &
    {
        return getFrame().typenameById;
    }

    auto TypeManager::getTypeByName() noexcept -> UnorderedMap<std::string, FscType> &
    {
        return getFrame().idByTypename;
    }

    auto TypeManager::getTypeInfo() noexcept -> UnorderedMap<FscType, TypeInfo> &
    {
        return getFrame().typeInfo;
    }

    auto TypeManager::getTypesMemberVariables() noexcept
        -> UnorderedMap<FscType, Map<std::string, ast::NodePtr>> &
    {
        return getFrame().memberVariables;
    }

    auto TypeManager::getTemplatedTypes() noexcept -> UnorderedSet<FscType> &
    {
        return getFrame().templateTypes;
    }

    auto TypeManager::getRemapTypes() noexcept -> UnorderedMap<ccl::Id, FscType> &
    {
        return getFrame().remapTypes;
    }

    auto TypeManager::getInstantiatedTemplates() noexcept
        -> ccl::UnorderedMap<FscType, ccl::Map<FscType, FscType>> &
    {
        return getFrame().instantiatedTemplates;
    }

    auto TypeManager::getInstantiatedTypeToBase() noexcept -> ccl::UnorderedMap<FscType, FscType> &
    {
        return getFrame().instantiatedTypeToBase;
    }

    auto TypeManager::getFscClasses() noexcept -> UnorderedMap<FscType, ast::NodePtr> &
    {
        return getFrame().fscClasses;
    }

    auto TypeManager::generateUuid() noexcept -> Id
    {
        static constinit auto type_uuid_creator = std::atomic<ccl::Id>{0};

        return type_uuid_creator.fetch_add(1U, std::memory_order_relaxed);
    }

    auto TypeManager::templateTypeExists(const std::string &name) -> bool
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

    auto TypeManager::exactTypeExists(const std::string &type_name) noexcept -> bool
    {
        return getTypeByName().contains(type_name);
    }

    auto TypeManager::postCreationSetupForTemplates(FscType type, CreationType creation_type)
        -> void
    {
        if (creation_type == CreationType::DEFAULT) {
            return;
        }

        getTemplatedTypes().emplace(type);

        if (creation_type == CreationType::TEMPLATE_HIDE_NAME) {
            hideTemplate(type.getName());
        }
    }

    auto TypeManager::instantiatedTemplate(
        const std::string &base_name,
        const std::string &template_name) -> FscType
    {
        if (!exactTypeExists(base_name)) {
            throw std::invalid_argument{fmt::format("{} is not a valid type", base_name)};
        }

        return createFromName(fmt::format("{}<{}>", base_name, template_name));
    }

    auto TypeManager::map(FscType key, FscType value) -> void
    {
        if (getRemapTypes().contains(key.getId())) {
            throw std::invalid_argument{fmt::format(
                "Unable to map {}:{} more than once at the same time",
                getTypename(key),
                key.getId())};
        }

        getTemplatedTypes().emplace(key);
        getTypeByName().try_emplace(key.getName(), value);
        getRemapTypes().try_emplace(key.getId(), value);
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
        if (!getTypeByName().contains(type_name)) {
            throw std::invalid_argument{
                fmt::format("Unable to hide {}, because it is not a valid type", type_name)};
        }

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
        return getTypeInfo().at(type).isTriviallyCopyable;
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

    auto TypeManager::getInfoAboutType(FscType type) -> TypeInfo
    {
        return getTypeInfo().at(type);
    }

    auto TypeManager::updateTypeInfo(FscType type, TypeInfo type_info) -> void
    {
        getTypeInfo().at(type) = type_info;
    }

    auto TypeManager::addFscClass(ast::NodePtr class_node) -> void
    {
        const auto &fsc_class = class_node->as<ast::Class>();
        getFscClasses().try_emplace(fsc_class.getType(), std::move(class_node));
    }

    auto TypeManager::addMemberVariable(FscType type, ast::NodePtr variable_node) -> void
    {
        type = getTrueType(type);

        const auto &variable = ccl::as<ast::Variable &>(*variable_node);
        auto &class_variables = getTypesMemberVariables().at(type);

        class_variables.try_emplace(variable.getName(), std::move(variable_node));
    }

    auto TypeManager::hasMemberVariable(FscType type, const std::string &variable_name) -> bool
    {
        type = getBaseTypeOfInstantiatedTemplate(type);

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

    auto TypeManager::convertToClassPrivateInstantiatedTemplate(FscType fsc_class, FscType type)
        -> FscType
    {
        fsc_class = getTrueType(fsc_class);
        type = getTrueType(type);

        if (!getInstantiatedTemplates().contains(fsc_class)) {
            return type;
        }

        const auto &instantiated_templates = getInstantiatedTemplates().at(fsc_class);

        if (instantiated_templates.contains(type)) {
            return instantiated_templates.at(type);
        }

        return type;
    }

    auto TypeManager::getBaseTypeOfInstantiatedTemplate(FscType type) -> FscType
    {
        type = getTrueType(type);

        if (getInstantiatedTypeToBase().contains(type)) {
            type = getInstantiatedTypeToBase().at(type);
        }

        return type;
    }

    auto TypeManager::getMemberVariable(FscType type, const std::string &member_variable_name)
        -> ast::NodePtr
    {
        type = getBaseTypeOfInstantiatedTemplate(type);

        if (!hasMemberVariable(type, member_variable_name)) {
            throw FscException{fmt::format(
                "{} does not have {} member variable", getTypename(type), member_variable_name)};
        }

        if (member_variable_name == "this") {
            // TODO: check for const reference
            return makeShared<ast::Variable>(
                nullptr, "*this", ccl::toLazy(type), ast::VariableFlags{.reference = true});
        }

        return getTypesMemberVariables().at(type).at(member_variable_name);
    }

    auto TypeManager::getMemberVariables(FscType type)
        -> const ccl::Map<std::string, ast::NodePtr> &
    {
        return getTypesMemberVariables()[type];
    }

    auto TypeManager::createNewType(
        const std::string &type_name,
        TypeInfo type_flags,
        CreationType creation_type) -> FscType
    {
        static auto type_registration_mutex = std::mutex{};

        if (exactTypeExists(type_name)) {
            throw std::invalid_argument{fmt::format("Type {} already exists", type_name)};
        }

        const auto type = FscType{generateUuid(), std::in_place};
        const auto creation_lock = std::scoped_lock{type_registration_mutex};

        getTypeByName().try_emplace(type_name, type);
        getTypenameById().try_emplace(type.getId(), type_name);
        getTypeInfo().try_emplace(type, type_flags);
        getTypesMemberVariables().try_emplace(type);
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

            const auto base_type = FscType{base_name};
            const auto templates_count = std::ranges::count(template_name, ',') + 1;

            if (ccl::as<size_t>(templates_count) !=
                getTypeInfo().at(base_type).templatesParametersCount) {
                throw FscException{fmt::format(
                    "{} can not hold {} templates parameters", base_name, templates_count)};
            }

            auto templates = checkTemplatePackCorrect(template_name);
            auto class_node = getFscClass(base_type);
            const auto &fsc_class = class_node->as<ast::Class>();
            const auto &class_templates = fsc_class.getTemplates();
            const auto new_type = createNewType(type_name, {});
            auto &instantiated_templates_map = getInstantiatedTemplates()[new_type];

            for (auto i = as<size_t>(0); i != templates.size(); ++i) {
                instantiated_templates_map.emplace(class_templates[i], templates[i]);
            }

            getInstantiatedTypeToBase().emplace(new_type, base_type);
            func::Functions.map(FscType{base_name}, new_type);
            return new_type;
        }

        return getTypeByName().at(type_name);
    }

    auto TypeManager::hash(FscType type) noexcept -> size_t
    {
        return getTrueType(type).getId();
    }
}// namespace fsc