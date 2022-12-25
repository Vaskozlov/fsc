#include "ast/statement/if_stmt.hpp"
#include "ast/expression/parenthesized.hpp"
#include <ccl/ccl.hpp>

namespace fsc::ast
{
    IfStmt::IfStmt(Visitor &visitor, FscParser::If_stmtContext *ctx)
    {
        const auto &children = ctx->children;
        auto if_context = children.at(0);
        auto elif_context = children.at(1);
        auto else_context = children.at(2);

        parseIfStmt(visitor, ccl::as<FscParser::IfContext *>(if_context));
        parseElifStmt(visitor, ccl::as<FscParser::ElifContext *>(elif_context));
        parseElseStmt(visitor, ccl::as<FscParser::ElseContext *>(else_context));
    }

    auto IfStmt::codeGen(gen::CodeGenerator &output) const -> void
    {
        output << *ifNode;

        for (const auto &node : elifNodes) {
            output << gen::endl << *node;
        }

        if (elseNode != nullptr) {
            output << gen::endl << *elseNode;
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

    auto IfStmt::parseIfStmt(Visitor &visitor, FscParser::IfContext *ctx) -> void
    {
        const auto &children = ctx->children;
        auto expr = visitor.visitAsNode(children.at(1));
        auto body = visitor.visitAsNode(children.at(3));

        ifNode = ccl::makeShared<If>(IfType::IF, ccl::makeShared<Parenthesized>(expr), body);
    }

    auto IfStmt::parseElifStmt(Visitor &visitor, FscParser::ElifContext *ctx) -> void
    {
        for (auto *context : ctx->children) {
            const auto &children = context->children;
            auto expr = visitor.visitAsNode(children.at(1));
            auto body = visitor.visitAsNode(children.at(3));

            elifNodes.emplace_back(
                ccl::makeShared<If>(IfType::ELIF, ccl::makeShared<Parenthesized>(expr), body));
        }
    }

    auto IfStmt::parseElseStmt(Visitor &visitor, FscParser::ElseContext *ctx) -> void
    {
        const auto &children = ctx->children;

        if (children.empty()) {
            return;
        }

        auto body = visitor.visitAsNode(children.at(1));
        elseNode = ccl::makeShared<Parenthesized>(ccl::makeShared<If>(IfType::ELSE, nullptr, body));
    }
}// namespace fsc::ast
