#include "ast/value/member_variable.hpp"
#include "ast/value/variable.hpp"
#include "type/type.hpp"
#include <ccl/ccl.hpp>

namespace fsc::ast
{
    using namespace ccl;
    using namespace std::string_view_literals;

    MemberVariable::MemberVariable(NodePtr node_to_access, std::string variable_name)
      : node{std::move(node_to_access)}
      , name{std::move(variable_name)}
    {}

    auto MemberVariable::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        output << *node << '.' << name;
    }

    auto MemberVariable::optimize(OptimizationLevel level) -> void
    {
        node->optimize(level);
    }

    auto MemberVariable::analyze() -> AnalysisReport
    {
        if (!canAccessMember()) {
            throw std::runtime_error{"unable to construct member access"};
        }

        return node->analyze();
    }

    auto MemberVariable::print(const std::string &prefix, bool is_left) const -> void
    {
        node->print(prefix, is_left);
        fmt::print("{}Member variable: {}\n", expandPrefix(prefix, is_left), name);
    }

    auto MemberVariable::getValueType() -> FscType
    {
        return node->getValueType().getMemberVariable(name)->getValueType();
    }

    auto MemberVariable::canAccessMember() const noexcept -> bool
    {
        auto id = getTypeOfNode();

        if (!id.has_value()) {
            return false;
        }

        return id->hasMemberVariables(name);
    }

    auto MemberVariable::getTypeOfNode() const noexcept -> Optional<FscType>
    {
        try {
            return node->getValueType();
        } catch (const std::exception & /* unused */) {
            return std::nullopt;
        }
    }
}// namespace fsc::ast
