#include "ast/return.hpp"
#include "ast/statement/if_stmt.hpp"
#include "ast/statement/while.hpp"
#include "visitor.hpp"
#include <type/antlr-types.hpp>

namespace fsc
{
    using namespace ccl;
    using namespace std::string_view_literals;

    auto Visitor::constructReturn(StatementContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;

        return makeShared<ast::Return>(visitAsNode(children.at(1)));
    }

    auto Visitor::constructIf(IfStatementContext *ctx) -> ast::NodePtr
    {
        return makeShared<ast::IfStmt>(*this, ctx);
    }

    auto Visitor::constructWhile(WhileContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;
        auto condition = visitAsNode(children.at(2));
        auto body = visitAsNode(children.at(4));

        return makeShared<ast::While>(std::move(condition), std::move(body));
    }

    auto Visitor::constructStatement(StatementContext *ctx) -> std::any
    {
        const auto &children = ctx->children;

        if (children.at(0)->getText() == "return"sv) {
            return constructReturn(ctx);
        }

        if (auto *func = ctx->function(); func != nullptr) {
            return visitFunction(func);
        }

        if (auto *class_ = ctx->class_(); class_ != nullptr) {
            return visitClass(class_);
        }

        if (auto *if_stmt = ctx->if_stmt(); if_stmt != nullptr) {
            return visitIf_stmt(if_stmt);
        }

        if (auto *expr = ctx->expr(); expr != nullptr) {
            return visitExpr(expr);
        }

        if (auto *while_loop = ctx->while_loop(); while_loop != nullptr) {
            return visitWhile_loop(while_loop);
        }

        return visitChildren(ctx);
    }
}// namespace fsc
