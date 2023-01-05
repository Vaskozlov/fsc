#include "type/type.hpp"
#include "type/builtin_types.hpp"
#include <ast/value/variable.hpp>
#include <mutex>

namespace fsc
{
    // NOLINTNEXTLINE
    ccl::Map<ccl::Id, std::string> FscType::typenameById{
        {Void::typeId, "void"},     {Auto::typeId, "void"},   {Int32::typeId, "i32"},
        {Int64::typeId, "i64"},     {UInt32::typeId, "u32"},  {UInt64::typeId, "u64"},
        {Float32::typeId, "f32"},   {Float64::typeId, "f64"}, {Bool::typeId, "bool"},
        {String::typeId, "String"}, {Char::typeId, "char"}};

    // NOLINTNEXTLINE
    ccl::Map<std::string, ccl::Id> FscType::idByTypename{
        {"void", Void::typeId},     {"auto", Auto::typeId},   {"i32", Int32::typeId},
        {"i64", Int64::typeId},     {"u32", UInt32::typeId},  {"u64", UInt64::typeId},
        {"f32", Float32::typeId},   {"f64", Float64::typeId}, {"bool", Bool::typeId},
        {"String", String::typeId}, {"char", Char::typeId}};

    // NOLINTNEXTLINE
    ccl::Map<ccl::Id, TypeFlags> FscType::typeFlags{
        {Void::typeId, {.isTriviallyCopyable = false}},
        {Int32::typeId, {.isTriviallyCopyable = true}},
        {Int64::typeId, {.isTriviallyCopyable = true}},
        {UInt32::typeId, {.isTriviallyCopyable = true}},
        {UInt64::typeId, {.isTriviallyCopyable = true}},
        {Float32::typeId, {.isTriviallyCopyable = true}},
        {Float64::typeId, {.isTriviallyCopyable = true}},
        {Bool::typeId, {.isTriviallyCopyable = true}},
        {String::typeId, {.isTriviallyCopyable = false}},
        {Char::typeId, {.isTriviallyCopyable = true}}};

    ccl::Map<ccl::Id, ccl::Map<std::string, ccl::SharedPtr<ast::Variable>>>// NOLINTNEXTLINE
        FscType::typeMemberVariables{};

    // NOLINTNEXTLINE
    ccl::Set<ccl::Id> FscType::templateTypes{};

    FscType::FscType(const ccl::Id type_id)
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

    auto FscType::isTemplate(ccl::Id id) noexcept -> bool
    {
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

    auto FscType::addMemberVariable(ccl::Id type_id, ccl::SharedPtr<ast::Variable> variable) -> void
    {
        typeMemberVariables[type_id].emplace(variable->getName(), variable);
    }

    auto FscType::hasMemberVariables(ccl::Id type_id, const std::string &name) -> bool
    {
        return typeMemberVariables.contains(type_id) &&
               typeMemberVariables.at(type_id).contains(name);
    }

    auto FscType::getMemberVariable(ccl::Id type_id, const std::string &name)
        -> ccl::SharedPtr<ast::Variable>
    {
        if (name == "this") {
            return ccl::makeShared<ast::Variable>(
                "*this", type_id, ast::VariableFlags{.reference = true});
        }

        return typeMemberVariables.at(type_id).at(name);
    }

    auto operator<<(ccl::codegen::BasicCodeGenerator &generator, const FscType &fsc_type)
        -> ccl::codegen::BasicCodeGenerator &
    {
        fsc_type.codeGen(generator);
        return generator;
    }
}// namespace fsc
