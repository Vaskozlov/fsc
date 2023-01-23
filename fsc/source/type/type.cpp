#include "type/type.hpp"
#include "type/builtin_types.hpp"
#include <ast/value/variable.hpp>
#include <mutex>

namespace fsc
{
    using namespace ccl;

    // NOLINTNEXTLINE
    Map<Id, std::string> FscType::typenameById{
        {Void::typeId, "void"},     {Auto::typeId, "void"},   {Int32::typeId, "i32"},
        {Int64::typeId, "i64"},     {UInt32::typeId, "u32"},  {UInt64::typeId, "u64"},
        {Float32::typeId, "f32"},   {Float64::typeId, "f64"}, {Bool::typeId, "bool"},
        {String::typeId, "String"}, {Char::typeId, "char"}};

    // NOLINTNEXTLINE
    Map<std::string, Id> FscType::idByTypename{
        {"void", Void::typeId},     {"auto", Auto::typeId},   {"i32", Int32::typeId},
        {"i64", Int64::typeId},     {"u32", UInt32::typeId},  {"u64", UInt64::typeId},
        {"f32", Float32::typeId},   {"f64", Float64::typeId}, {"bool", Bool::typeId},
        {"String", String::typeId}, {"char", Char::typeId}};

    // NOLINTNEXTLINE
    Map<Id, TypeFlags> FscType::typeFlags{{Void::typeId, {.isTriviallyCopyable = false}},
                                          {Int32::typeId, {.isTriviallyCopyable = true}},
                                          {Int64::typeId, {.isTriviallyCopyable = true}},
                                          {UInt32::typeId, {.isTriviallyCopyable = true}},
                                          {UInt64::typeId, {.isTriviallyCopyable = true}},
                                          {Float32::typeId, {.isTriviallyCopyable = true}},
                                          {Float64::typeId, {.isTriviallyCopyable = true}},
                                          {Bool::typeId, {.isTriviallyCopyable = true}},
                                          {String::typeId, {.isTriviallyCopyable = false}},
                                          {Char::typeId, {.isTriviallyCopyable = true}}};

    Map<Id, Map<std::string, SharedPtr<ast::Variable>>>// NOLINTNEXTLINE
        FscType::typeMemberVariables{};

    // NOLINTNEXTLINE
    Set<Id> FscType::templateTypes{};

    // NOLINTNEXTLINE
    Map<Id, Id> FscType::remapTypes{};

    FscType::FscType(const Id type_id)
      : typeId{type_id}
    {
        if (!exists(typeId)) {
            throw std::invalid_argument("Type not found");
        }
    }

    FscType::FscType(const std::string &type_name)
    {
        if (!exists(type_name)) {
            throw std::invalid_argument("Type not found");
        }

        typeId = getTypeId(type_name);
    }

    auto FscType::isTemplate(Id id) noexcept -> bool
    {
        if (remapTypes.contains(id)) {
            return isTemplate(remapTypes[id]);
        }

        return templateTypes.contains(id);
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
        templateTypes.emplace(getTypeId(type_name));
    }

    auto FscType::freeTemplateType(const std::string &type_name) -> void
    {
        idByTypename.erase(type_name);
    }

    auto FscType::registerNewType(const std::string &name, const TypeFlags flags) noexcept(false)
        -> void
    {
        static std::mutex type_registration_mutex;

        if (exists(name)) {
            throw std::invalid_argument(fmt::format("Type {} already registered", name));
        }

        auto type_id = TypeFactory();
        auto scope_lock = std::scoped_lock{type_registration_mutex};

        typenameById.emplace(type_id, name);
        idByTypename.emplace(name, type_id);
        typeFlags.emplace(type_id, flags);
    }

    auto FscType::addMemberVariable(Id type_id, SharedPtr<ast::Variable> variable) -> void
    {
        if (remapTypes.contains(type_id)) {
            return addMemberVariable(remapTypes[type_id], std::move(variable));
        }

        typeMemberVariables[type_id].emplace(variable->getName(), variable);
    }

    auto FscType::hasMemberVariables(Id type_id, const std::string &name) -> bool
    {
        if (remapTypes.contains(type_id)) {
            return hasMemberVariables(remapTypes[type_id], name);
        }

        return typeMemberVariables.contains(type_id) &&
               typeMemberVariables.at(type_id).contains(name);
    }

    auto FscType::getMemberVariable(Id type_id, const std::string &name) -> SharedPtr<ast::Variable>
    {
        if (templateTypes.contains(type_id)) {
            return getMemberVariable(remapTypes[type_id], name);
        }

        if (name == "this") {
            return makeShared<ast::Variable>(
                "*this", type_id, ast::VariableFlags{.reference = true});
        }

        return typeMemberVariables.at(type_id).at(name);
    }

    auto FscType::getTrueType(Id type_id) noexcept -> Id
    {
        if (remapTypes.contains(type_id)) {
            return getTrueType(remapTypes[type_id]);
        }

        return type_id;
    }

    auto FscType::removeRemap(Id type_id) noexcept -> void
    {
        if (remapTypes.contains(type_id)) {
            remapTypes.erase(type_id);
        }
    }

    auto FscType::remapType(Id type_to_remap, Id target_type_id) -> void
    {
        if (!remapTypes.contains(type_to_remap)) {
            remapTypes.emplace(type_to_remap, target_type_id);
        } else {
            throw std::invalid_argument(fmt::format("Type {} already remapped", type_to_remap));
        }
    }

    auto operator<<(codegen::BasicCodeGenerator &generator, const FscType &fsc_type)
        -> codegen::BasicCodeGenerator &
    {
        fsc_type.codeGen(generator);
        return generator;
    }
}// namespace fsc
