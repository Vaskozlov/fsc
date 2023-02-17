#include "type/type.hpp"
#include "ast/container/class.hpp"
#include "ast/value/variable.hpp"
#include "function/functions_holder.hpp"
#include "type/builtin_types.hpp"
#include <ccl/lex/tokenizer.hpp>
#include <mutex>

namespace fsc
{
    using namespace ccl;
    using namespace std::string_literals;

    auto FscType::getVariables() -> FscTypeVariables &
    {
        static auto variables = FscTypeVariables{};
        return variables;
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

    auto FscType::ensureTypeExists(const std::string &type_name) -> void
    {
        if (exists(type_name)) {
            return;
        }

        throw FscException(fmt::format("Type {} not found", type_name));
    }

    auto FscType::weakFreeTemplateType(const std::string &type_name) -> void
    {
        getIdByTypename().erase(type_name);
    }

    auto FscType::registerNewType(
        const std::string &name, TypeFlags flags, CreationType creation_type,
        bool add_to_builtin) noexcept(false) -> Id
    {
        static auto type_registration_mutex = std::mutex{};
        static constinit auto TypeUuidCreator = std::atomic<ccl::Id>{0};

        if (getIdByTypename().contains(name)) {
            throw std::invalid_argument(fmt::format("Type {} already registered", name));
        }

        auto type_id = TypeUuidCreator.fetch_add(1U, std::memory_order_relaxed);

        {
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
        }

        if (add_to_builtin) {
            addTypeToBuiltinFunctions(FscType{type_id});
        }

        return type_id;
    }

    auto FscType::registerFscClass(ast::NodePtr new_fsc_class) -> void
    {
        auto fsc_class = new_fsc_class->as<ast::Class>();
        auto value_type = FscType{fsc_class.getName()};

        getFscClasses().emplace(value_type, std::move(new_fsc_class));
    }

    auto FscType::addTypeToBuiltinFunctions(FscType type) -> void
    {
        auto vector_name = fmt::format("Vector<{}>", type.getName());
        auto vector_id = FscType{registerNewType(vector_name, {}, CreationType::DEFAULT, false)};

        func::Functions.registerFunction(ast::Function(Void, vector_name, vector_id, {}));
        func::Functions.registerFunction(
            ast::Function(vector_id, "at", type, {{"index", UInt32, ArgumentCategory::IN}}));
        func::Functions.registerFunction(
            ast::Function(vector_id, "push_back", Void, {{"value", type, ArgumentCategory::IN}}));
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
            throw std::runtime_error("Bad attempt to get class");
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
