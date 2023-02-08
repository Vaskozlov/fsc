#include "type/type.hpp"
#include "ast/container/class.hpp"
#include "ast/value/variable.hpp"
#include "type/builtin_types.hpp"
#include <mutex>

namespace fsc
{
    using namespace ccl;

    auto FscType::getVariables() -> FscTypeVariables &
    {
        static auto variables = FscTypeVariables{};
        return variables;
    }

    FscType::FscType(const std::string &type_name) noexcept(false)
    {
        if (!exists(type_name)) {
            throw std::invalid_argument("Type not found");
        }

        typeId = getVariables().idByTypename.at(type_name);
    }

    auto FscType::toString() const -> std::string
    {
        throw std::logic_error("FscType::toString is not implemented for FscType base class");
    }

    auto FscType::codeGen(codegen::BasicCodeGenerator & /* unused */) const -> void
    {
        throw std::logic_error("FscType::codeGen is not implemented for FscType base class");
    }

    auto FscType::isTemplate() const noexcept -> bool
    {
        return getTemplatedTypes().contains(getTrueType());
    }

    auto FscType::exists(Id type_id) -> bool
    {
        return getVariables().typenameById.contains(type_id);
    }

    auto FscType::exists(const std::string &type_name) -> bool
    {
        return getVariables().idByTypename.contains(type_name);
    }

    auto FscType::ensureTypeExists(const std::string &type_name) -> void
    {
        if (exists(type_name)) {
            return;
        }

        throw std::invalid_argument(fmt::format("Type {} not found", type_name));
    }

    auto FscType::registerTemplate(const std::string &type_name) -> void
    {
        registerNewType(type_name, TypeFlags{});
        getTemplatedTypes().emplace(type_name);
    }

    auto FscType::freeTemplateType(const std::string &type_name) -> void
    {
        getIdByTypename().erase(type_name);
    }

    auto FscType::registerNewType(const std::string &name, TypeFlags flags) noexcept(false) -> Id
    {
        static std::mutex type_registration_mutex;

        if (exists(name)) {
            throw std::invalid_argument(fmt::format("Type {} already registered", name));
        }

        auto type_id = TypeFactory();
        auto scope_lock = std::scoped_lock{type_registration_mutex};

        getTypenameById().emplace(type_id, name);
        getIdByTypename().emplace(name, type_id);
        getTypeFlags().emplace(type_id, flags);

        return type_id;
    }

    auto FscType::registerFscClass(ast::NodePtr new_fsc_class) -> void
    {
        auto fsc_class = new_fsc_class->as<ast::Class>();

        getFscClasses().emplace(FscType{fsc_class.getName()}, std::move(new_fsc_class));
    }

    auto FscType::isTriviallyCopyable() const noexcept -> bool
    {
        return getVariables().typeFlags.at(*this).isTriviallyCopyable;
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
            throw std::runtime_error("Bad attempt to get class");
        }

        return getFscClasses().at(type);
    }

    auto FscType::getName() const -> std::string
    {
        return getVariables().typenameById.at(typeId);
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
        if (getRemapTypes().contains(*this)) {
            return getRemapTypes()[*this].getTrueType();
        }

        return *this;
    }

    auto FscType::unmap() const noexcept -> void
    {
        if (getRemapTypes().contains(*this)) {
            getRemapTypes().erase(*this);
        }
    }

    auto FscType::map(FscType target_type) const -> void
    {
        const auto already_map = getRemapTypes().contains(*this);

        if (!already_map) {
            getRemapTypes().emplace(*this, target_type.typeId);
        } else {
            throw std::invalid_argument(fmt::format("Type {} already remapped", typeId));
        }
    }

    auto operator<<(codegen::BasicCodeGenerator &generator, const FscType &fsc_type)
        -> codegen::BasicCodeGenerator &
    {
        fsc_type.codeGen(generator);
        return generator;
    }
}// namespace fsc
