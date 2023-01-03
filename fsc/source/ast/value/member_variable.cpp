#include "ast/value/member_variable.hpp"
#include "type/type.hpp"
#include <ccl/ccl.hpp>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    MemberVariable::MemberVariable(NodePtr node_to_access, std::string variable_name)
      : node{std::move(node_to_access)}
      , name{std::move(variable_name)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::MEMBER_VARIABLE);

        if (!canAccessMember()) {
            throw std::runtime_error{"Unable to construct member access"};
        }
    }

    auto MemberVariable::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        output << *node << '.' << name;
    }

    auto MemberVariable::print(const std::string &prefix, bool is_left) const -> void
    {
        node->print(prefix, is_left);
        fmt::print("{}.{}\n", expandPrefix(prefix, is_left), name);
    }

    auto MemberVariable::getValueType() const -> ccl::Id
    {
        return FscType::getMemberVariable(node->getValueType(), name)->getValueType();
    }

    auto MemberVariable::canAccessMember() const noexcept -> bool
    {
        auto id = getTypeOfNode();

        if (!id.has_value()) {
            return false;
        }

        return FscType::hasMemberVariables(*id, name);
    }

    auto MemberVariable::getTypeOfNode() const noexcept -> ccl::Optional<ccl::Id>
    {
        try {
            return node->getValueType();
        } catch (const std::exception & /* unused */) {
            return std::nullopt;
        }
    }
}// namespace fsc::ast
