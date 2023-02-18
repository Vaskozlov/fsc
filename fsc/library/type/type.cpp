#include "type/type.hpp"
#include "ast/container/class.hpp"
#include "ast/value/variable.hpp"
#include "function/functions_holder.hpp"
#include "type/builtin_types.hpp"
#include <mutex>

namespace fsc
{
    using namespace ccl;
    using namespace std::string_literals;

    static constinit auto TypeUuidCreator = std::atomic<ccl::Id>{0};

    CCL_INLINE auto FscType::getVariables() noexcept -> FscTypeVariables &
    {
        static auto variables = FscTypeVariables{};
        return variables;
    }

    CCL_INLINE auto FscType::getTypenameById() noexcept -> TypenameByIdStorage &
    {
        return getVariables().typenameById;
    }

    CCL_INLINE auto FscType::getIdByTypename() noexcept -> IdByTypenameStorage &
    {
        return getVariables().idByTypename;
    }

    CCL_INLINE auto FscType::getTypeFlags() noexcept -> TypeFlagsStorage &
    {
        return getVariables().typeFlags;
    }

    CCL_INLINE auto FscType::getTypesMemberVariables() noexcept -> TypesMemberVariablesStorage &
    {
        return getVariables().typeMemberVariables;
    }

    CCL_INLINE auto FscType::getTemplatedTypes() noexcept -> TemplatedTypesStorage &
    {
        return getVariables().templateTypes;
    }

    CCL_INLINE auto FscType::getRemapTypes() noexcept -> RemapTypesStorage &
    {
        return getVariables().remapTypes;
    }

    CCL_INLINE auto FscType::getFscClasses() noexcept -> FscClasses &
    {
        return getVariables().fscClasses;
    }

    FscType::FscType(const std::string &type_name) noexcept(false)
    {
        if (!exists(type_name)) {
            throw FscException("Type not found");
        }

        typeId = getIdByTypename().at(type_name);
    }

    auto FscType::isTemplate() const noexcept -> bool
    {
        return getVariables().templateTypes.contains(*this);
    }

    auto FscType::exists(Id type_id) -> bool
    {
        return getTypenameById().contains(type_id);
    }

    auto FscType::exists(const std::string &type_name) -> bool
    {
        if (getIdByTypename().contains(type_name)) {
            return true;
        }

        if (type_name.contains('<')) {
            const auto base_name = type_name.substr(0, type_name.find('<'));

            if (exists(base_name)) {
                auto new_type = registerNewType(type_name, {});
                func::Functions.map(FscType{base_name}, FscType{new_type});
                return true;
            }
        }

        return false;
    }

    auto FscType::registerInstantiatedTemplate(
        const std::string &full_name, const std::string &base_name) -> void
    {
        if (!full_name.contains('<')) {
            throw std::invalid_argument{"Name in not a valid template"};
        }

        if (!getIdByTypename().contains(base_name)) {
            throw std::invalid_argument{fmt::format("{} is not a valid type", base_name)};
        }
    }

    auto FscType::registerInstantiatedTemplate(const std::string &full_name) -> void
    {
        return registerInstantiatedTemplate(full_name, full_name.substr(0, full_name.find('<')));
    }

    auto FscType::templateTypeExist(const std::string &name) -> bool
    {
        if (!name.contains('<')) {
            return false;
        }

        const auto base_name = name.substr(0, name.find('<'));

        if (exists(base_name)) {}
    }

    auto FscType::ensureTypeExists(const std::string &type_name) -> void
    {
        if (exists(type_name)) {
            return;
        }

        throw FscException{fmt::format("Type {} not found", type_name)};
    }

    auto FscType::weakFreeTemplateType(const std::string &type_name) -> void
    {
        getIdByTypename().erase(type_name);
    }

    auto FscType::registerNewType(
        const std::string &name, TypeFlags flags, CreationType creation_type) noexcept(false) -> Id
    {
        static auto type_registration_mutex = std::mutex{};

        if (getIdByTypename().contains(name)) {
            throw std::invalid_argument{fmt::format("Type {} already registered", name)};
        }

        auto type_id = TypeUuidCreator.fetch_add(1U, std::memory_order_relaxed);
        auto scope_lock = std::scoped_lock{type_registration_mutex};

        getTypenameById().emplace(type_id, name);
        getIdByTypename().emplace(name, type_id);
        getTypeFlags().emplace(type_id, flags);

        if (creation_type != CreationType::DEFAULT) {
            getTemplatedTypes().emplace(name);
        }

        if (creation_type == CreationType::WEAK_TEMPLATE) {
            weakFreeTemplateType(name);
        }

        return type_id;
    }

    auto FscType::registerFscClass(ast::NodePtr new_fsc_class) -> void
    {
        auto fsc_class = new_fsc_class->as<ast::Class>();
        auto value_type = FscType{fsc_class.getName()};

        getFscClasses().emplace(value_type, std::move(new_fsc_class));
    }

    auto FscType::isTriviallyCopyable() const noexcept -> bool
    {
        return getTypeFlags().at(*this).isTriviallyCopyable;
    }

    auto FscType::addMemberVariable(ast::NodePtr variable) const -> void
    {
        auto type = getTrueType();

        getTypesMemberVariables()[type].emplace(
            ccl::as<ast::Variable *>(variable.get())->getName(), variable);
    }

    auto FscType::hasMemberVariables(const std::string &name) const -> bool
    {
        auto type = getTrueType();

        return getTypesMemberVariables().contains(type) &&
               getTypesMemberVariables().at(type).contains(name);
    }

    auto FscType::getClass() const noexcept(false) -> ast::NodePtr
    {
        auto type = getTrueType();

        if (!getFscClasses().contains(type)) {
            throw std::runtime_error{"Bad attempt to get class"};
        }

        return getFscClasses().at(type);
    }

    auto FscType::getName() const -> std::string
    {
        return getTypenameById().at(typeId);
    }

    auto FscType::getMemberVariable(const std::string &name) const -> ast::NodePtr
    {
        auto type = getTrueType();

        if (name == "this") {
            return makeShared<ast::Variable>("*this", type, ast::VariableFlags{.reference = true});
        }

        return getTypesMemberVariables().at(type).at(name);
    }

    auto FscType::getTrueType() const noexcept -> FscType
    {
        auto true_type = *this;

        while (getRemapTypes().contains(true_type)) {
            true_type = getRemapTypes()[true_type];
        }

        return true_type;
    }

    auto FscType::unmap() const noexcept -> void
    {
        if (getRemapTypes().contains(*this)) {
            getRemapTypes().erase(*this);
            getIdByTypename().erase(getName());
        }
    }

    auto FscType::map(FscType target_type) const -> void
    {
        const auto already_map = getRemapTypes().contains(*this);

        if (!already_map) {
            getRemapTypes().emplace(*this, target_type.typeId);
        } else {
            throw std::invalid_argument{fmt::format("Type {} already remapped", typeId)};
        }

        getIdByTypename().emplace(getName(), typeId);
    }

    auto operator<<(codegen::BasicCodeGenerator &generator, FscTypeInterface &fsc_type)
        -> codegen::BasicCodeGenerator &
    {
        fsc_type.codeGen(generator);
        return generator;
    }

    auto FscTypeInterface::toString() const -> std::string
    {
        throw std::logic_error("FscType::toString is not implemented for FscType base class");
    }

    auto FscTypeInterface::codeGen(codegen::BasicCodeGenerator & /* unused */) -> void
    {
        throw std::logic_error("FscType::codeGen is not implemented for FscType base class");
    }
}// namespace fsc
