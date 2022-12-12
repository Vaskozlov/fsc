#include "ast/member_variable.hpp"
#include "ccl/core/types.hpp"
#include "type/type.hpp"

namespace fsc::ast
{
    MemberVariable::MemberVariable(NodePtr node_to_access, std::string variable_name)
      : node{std::move(node_to_access)}
      , name{std::move(variable_name)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::MEMBER_VARIABLE);

        if (!canAccessMember()) {
            throw std::runtime_error{"Unable to construct member access"};
        }
    }

    auto MemberVariable::codeGen(gen::CodeGenerator &output) const -> void
    {
        output.write('(');
        node->codeGen(output);
        output.write(')');
        output.write('.');
        output.write(name);
    }

    auto MemberVariable::print(const std::string &prefix, bool is_left) const -> void
    {
        node->print(prefix, is_left);
        fmt::print("{}{}\n", expandPrefix(prefix, is_left), name);
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
