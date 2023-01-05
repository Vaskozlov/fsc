#include "ast/value/member_variable.hpp"
#include "ast/value/variable_definition.hpp"
#include "stack/stack.hpp"
#include "visitor.hpp"

namespace fsc
{
    auto Visitor::constructVariableDefinition(FscParser::Variable_definitionContext *ctx)
        -> ast::NodePtr
    {
        auto variable = ccl::makeShared<ast::VariableDefinition>(*this, ctx);
        ProgramStack.addVariable(variable);
        return variable;
    }

    auto Visitor::constructAutoVariableDefinition(FscParser::Auto_variable_definitionContext *ctx)
        -> ast::NodePtr
    {
        auto variable = ccl::makeShared<ast::VariableDefinition>(*this, ctx);
        ProgramStack.addVariable(variable);
        return variable;
    }

    auto Visitor::constructMemberVariableAccess(FscParser::ExprContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;
        auto base_node = visitAsNode(children.at(0));
        auto member_variable_name = children.at(1)->children.at(1)->getText();
        return ccl::makeShared<ast::MemberVariable>(base_node, member_variable_name);
    }
}// namespace fsc
