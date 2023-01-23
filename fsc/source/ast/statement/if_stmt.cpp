#include "ast/statement/if_stmt.hpp"
#include "ast/expression/parenthesized.hpp"
#include <ccl/ccl.hpp>
#include <type/antlr-types.hpp>

namespace fsc::ast
{
    using namespace ccl;

    IfStmt::IfStmt(Visitor &visitor, IfStatementContext *ctx)
    {
        const auto &children = ctx->children;
        auto *if_context = ccl::as<IfContext *>(children.at(0));
        auto *elif_context = ccl::as<ElifContext *>(children.at(1));
        auto *else_context = ccl::as<ElseContext *>(children.at(2));

        parseIfStmt(visitor, if_context);
        parseElifStmt(visitor, elif_context);
        parseElseStmt(visitor, else_context);
    }

    auto IfStmt::analyze() const -> void
    {
        ifNode->analyze();

        for (const auto &elif_node : elifNodes) {
            elif_node->analyze();
        }

        elseNode->analyze();
    }

    auto IfStmt::codeGen(codegen::BasicCodeGenerator &output) const -> void
    {
        using namespace codegen;

        output << *ifNode;

        for (const auto &node : elifNodes) {
            output << endl << *node;
        }

        if (elseNode != nullptr) {
            output << endl << *elseNode;
        }
    }

    auto IfStmt::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);

        fmt::print("{}If statement\n", getPrintingPrefix(prefix, is_left));
        ifNode->print(expanded_prefix, (!elifNodes.empty()) or (elseNode != nullptr));

        for (const auto &node : elifNodes | ccl::views::dropBack(elifNodes)) {
            node->print(expanded_prefix, true);
        }

        if (!elifNodes.empty()) {
            const auto &last_node = elifNodes.back();
            last_node->print(expanded_prefix, elseNode != nullptr);
        }

        if (elseNode != nullptr) {
            elseNode->print(expanded_prefix, false);
        }
    }

    auto IfStmt::parseIfStmt(Visitor &visitor, IfContext *ctx) -> void
    {
        const auto &children = ctx->children;
        auto expr = visitor.visitAsNode(children.at(1));
        auto body = visitor.visitAsNode(children.at(3));

        ifNode = makeShared<If>(IfType::IF, makeShared<Parenthesized>(expr), body);
    }

    auto IfStmt::parseElifStmt(Visitor &visitor, ElifContext *ctx) -> void
    {
        for (auto *context : ctx->children) {
            const auto &children = context->children;
            auto expr = visitor.visitAsNode(children.at(1));
            auto body = visitor.visitAsNode(children.at(3));

            elifNodes.emplace_back(
                makeShared<If>(IfType::ELIF, makeShared<Parenthesized>(expr), body));
        }
    }

    auto IfStmt::parseElseStmt(Visitor &visitor, ElseContext *ctx) -> void
    {
        if (ctx->children.empty()) {
            return;
        }

        const auto &children = ctx->children.at(0)->children;
        auto body = visitor.visitAsNode(children.at(1));

        elseNode = makeShared<If>(IfType::ELSE, nullptr, body);
    }
}// namespace fsc::ast
