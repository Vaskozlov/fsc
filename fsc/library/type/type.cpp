#include "type/type.hpp"
#include "ast/value/variable.hpp"
#include "type/builtin_types.hpp"
#include "type/type_manager.hpp"
#include <mutex>

namespace fsc
{
    using namespace ccl;
    using namespace std::string_literals;

    FscType::FscType(Id type_id) noexcept(false)
      : typeId{type_id}
    {
        if (!TypeManager::exists(typeId)) [[unlikely]] {
            throw FscException{"Type not found"};
        }
    }

    FscType::FscType(const std::string &type_name) noexcept(false)
    {
        *this = TypeManager::createFromName(type_name);
    }

    auto FscType::operator==(FscType other) const noexcept -> bool
    {
        const auto lhs_true_type = TypeManager::getTrueType(*this);
        const auto rhs_true_type = TypeManager::getTrueType(other);

        return lhs_true_type.getId() == rhs_true_type.getId();
    }

    auto FscType::operator<=>(FscType other) const noexcept -> std::weak_ordering
    {
        const auto lhs_true_type = TypeManager::getTrueType(*this);
        const auto rhs_true_type = TypeManager::getTrueType(other);

        return lhs_true_type.getId() <=> rhs_true_type.getId();
    }

    auto FscType::isTemplate() const noexcept -> bool
    {
        return TypeManager::isTemplate(*this);
    }

    auto FscType::isRemapTemplate() const noexcept -> bool
    {
        return TypeManager::isRemapTemplate(*this);
    }

    auto FscType::isTriviallyCopyable() const noexcept -> bool
    {
        return TypeManager::isTriviallyCopyable(*this);
    }

    auto FscType::addMemberVariable(ast::NodePtr variable) const -> void
    {
        TypeManager::addMemberVariable(*this, std::move(variable));
    }

    auto FscType::hasMemberVariables(const std::string &name) const -> bool
    {
        return TypeManager::hasMemberVariable(*this, name);
    }

    auto FscType::getClass() const noexcept(false) -> ast::NodePtr
    {
        return TypeManager::getFscClass(*this);
    }

    auto FscType::getName() const -> std::string
    {
        return TypeManager::getTypename(*this);
    }

    auto FscType::getMemberVariable(const std::string &name) const -> ast::NodePtr
    {
        return TypeManager::getMemberVariable(*this, name);
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


auto std::hash<fsc::FscType>::operator()(fsc::FscType type) const noexcept -> std::size_t
{
    return fsc::TypeManager::hash(type);
}
