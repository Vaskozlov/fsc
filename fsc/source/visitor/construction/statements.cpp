#include "ast/return.hpp"
#include "ast/statement/if_stmt.hpp"
#include "ast/statement/while.hpp"
#include "ccl/core/types.hpp"
#include "visitor.hpp"

namespace fsc
{
    using namespace std::string_view_literals;

    auto Visitor::constructReturn(FscParser::StmtContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;

        return ccl::makeShared<ast::Return>(*this, visitAsNode(children.at(1)));
    }

    auto Visitor::constructIf(FscParser::If_stmtContext *ctx) -> ast::NodePtr
    {
        return ccl::makeShared<ast::IfStmt>(*this, ctx);
    }

    auto Visitor::constructWhile(FscParser::While_loopContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;
        auto condition = visitAsNode(children.at(2));
        auto body = visitAsNode(children.at(4));

        return ccl::makeShared<ast::While>(std::move(condition), std::move(body));
    }

    auto Visitor::constructStatement(FscParser::StmtContext *ctx) -> std::any
    {
        const auto &children = ctx->children;

        if (children[0]->getText() == "return"sv) {
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
