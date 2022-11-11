#include "type/type.hpp"
#include "type/builtin_types.hpp"
#include <mutex>

namespace fsc {
    ccl::Map<TypeId, std::string> FscType::typenameById{
            {Void::typeId, "void"},   {Int32::typeId, "i32"},  {Int64::typeId, "i64"},
            {UInt32::typeId, "u32"},  {UInt64::typeId, "u64"}, {Float32::typeId, "f32"},
            {Float64::typeId, "f64"}, {Bool::typeId, "bool"}};

    ccl::Map<std::string, TypeId> FscType::idByTypename{
            {"void", Void::typeId},   {"i32", Int32::typeId},  {"i64", Int64::typeId},
            {"u32", UInt32::typeId},  {"u64", UInt64::typeId}, {"f32", Float32::typeId},
            {"f64", Float64::typeId}, {"bool", Bool::typeId}};

    ccl::Map<TypeId, TypeFlags> FscType::typeFlags{{Void::typeId, {.isTriviallyCopyable = false}},
                                                   {Int32::typeId, {.isTriviallyCopyable = true}},
                                                   {Int64::typeId, {.isTriviallyCopyable = true}},
                                                   {UInt32::typeId, {.isTriviallyCopyable = true}},
                                                   {UInt64::typeId, {.isTriviallyCopyable = true}},
                                                   {Float32::typeId, {.isTriviallyCopyable = true}},
                                                   {Float64::typeId, {.isTriviallyCopyable = true}},
                                                   {Bool::typeId, {.isTriviallyCopyable = true}}};

    ccl::Map<TypeId, ccl::Map<std::string, ccl::SharedPtr<ast::Variable>>>
            FscType::typeMemberVariables;

    FscType::FscType(const TypeId type_id) : typeId{type_id}
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

    auto FscType::checkTypeExistence(const std::string &type_name) -> void
    {
        if (exists(type_name)) {
            return;
        }

        throw std::invalid_argument(fmt::format("Type {} not found", type_name));
    }

    auto FscType::registerNewType(const std::string &name, const TypeFlags flags) -> void
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

    auto FscType::addMemberVariable(TypeId type_id, ccl::SharedPtr<ast::Variable> variable) -> void
    {
        typeMemberVariables[type_id].emplace(variable->getName(), variable);
    }

    auto FscType::hasMemberVariables(TypeId type_id, const std::string &name) -> bool
    {
        return typeMemberVariables.contains(type_id) &&
               typeMemberVariables.at(type_id).contains(name);
    }

    auto FscType::getMemberVariable(TypeId type_id, const std::string &name)
            -> ccl::SharedPtr<ast::Variable>
    {
        return typeMemberVariables.at(type_id).at(name);
    }
}// namespace fsc
