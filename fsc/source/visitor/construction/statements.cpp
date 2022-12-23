#include "ast/if_stmt.hpp"
#include "ast/return.hpp"
#include "visitor.hpp"

namespace fsc
{
    using namespace std::string_view_literals;

    auto Visitor::constructReturn(FscParser::StmtContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;

        return ccl::makeShared<ast::Return>(*this, visitAsNode(children[1]));
    }

    auto Visitor::constructIf(FscParser::If_stmtContext *ctx) -> ast::NodePtr
    {
        return ccl::makeShared<ast::IfStmt>(*this, ctx);
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

        return visitChildren(ctx);
    }
}// namespace fsc
