#include "ast/expression/binary_operator.hpp"
#include "ast/expression/conversion.hpp"
#include "ast/expression/parenthesized.hpp"
#include "converters/bool.hpp"
#include "converters/float.hpp"
#include "converters/int.hpp"
#include "converters/string.hpp"
#include "stack/stack.hpp"
#include "visitor.hpp"
#include <ccl/flatmap.hpp>
#include <type/type.hpp>

namespace fsc
{
    using namespace ccl;
    using namespace std::string_view_literals;

    static auto isBinaryOperator(ExpressionContext *ctx) -> bool
    {
        static constexpr auto binary_expressions = StaticFlatmap<std::string_view, bool, 19>{
            {"+", true},  {"-", true},  {"*", true},  {"/", true},  {"%", true},
            {"+=", true}, {"-=", true}, {"*=", true}, {"/=", true}, {"%=", true},
            {"==", true}, {"!=", true}, {"<", true},  {">", true},  {"<=", true},
            {">=", true}, {"||", true}, {"&&", true}, {"=", true},
        };

        return ctx->children.size() == 3 &&
               binary_expressions.contains(ctx->children.at(1)->getText());
    }

    auto Visitor::constructParenthesized(ExpressionContext *expr_context) -> ast::NodePtr
    {
        const auto &children = expr_context->children;
        auto stored_node = visitAsNode(children.at(1));
        return makeShared<ast::Parenthesized>(std::move(stored_node));
    }

    auto Visitor::constructExpression(ExpressionContext *ctx) -> std::any
    {
        auto node = ast::NodePtr{};
        const auto &children = ctx->children;

        if (ctx->AS() != nullptr) {
            node = constructConversion(ctx);
        }

        else if (ctx->INT() != nullptr) {
            node = converter::toInt(ctx->getText(), ctx);
        }

        else if (ctx->FLOAT() != nullptr) {
            node = converter::toFloat(ctx->getText(), ctx);
        }

        else if (ctx->TRUE() != nullptr) {
            node = converter::toBoolean(ctx->getText(), ctx);
        }

        else if (ctx->STRING() != nullptr) {
            node = converter::toString(ctx->getText(), ctx);
        }

        else if (children.size() == 3 && children.at(0)->getText() == "("sv) {
            node = constructParenthesized(ctx);
        }

        else if (ctx->member_variable_access() != nullptr) {
            node = constructMemberVariableAccess(ctx);
        }

        else if (ctx->method_call() != nullptr) {
            node = constructMethodCall(ctx);
        }

        else if (ctx->function_call() != nullptr) {
            node = visitAsNode(ctx->function_call());
        }

        else if (isBinaryOperator(ctx)) {
            node = constructBinaryExpression(ctx);
        }

        else if (ctx->variable_definition() != nullptr) {
            node = constructVariableDefinition(ctx->variable_definition());
        }

        else if (ctx->auto_variable_definition() != nullptr) {
            node = constructAutoVariableDefinition(ctx->auto_variable_definition());
        }

        else if (ctx->IDENTIFIER() != nullptr) {
            node = makeShared<ast::Variable>(ProgramStack.get(ctx->getText()));
        }

        else {
            return visitChildren(ctx);
        }

        return node;
    }

    auto Visitor::constructBinaryExpression(ExpressionContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;

        auto lhs = visitAsNode(children.at(0));
        auto rhs = visitAsNode(children.at(2));

        return makeShared<ast::BinaryOperation>(
            ctx, children.at(1)->getText(), std::move(lhs), std::move(rhs));
    }

    auto Visitor::constructConversion(ExpressionContext *ctx) -> ast::NodePtr
    {
        auto expr_to_convert = visitAsNode(ctx->children.at(0));
        const auto target_type = ctx->children.at(2)->getText();
        return makeShared<ast::Conversion>(std::move(expr_to_convert), FscType{target_type});
    }
}// namespace fsc
