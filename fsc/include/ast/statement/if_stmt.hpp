#ifndef FSC_IF_STMT_HPP
#define FSC_IF_STMT_HPP

#include "ast/statement/if.hpp"
#include "visitor.hpp"

namespace fsc::ast
{
    class IfStmt : public NodeWrapper<NodeType::IF_STMT, SemicolonNeed::DO_NOT_NEED>
    {
    private:
        ccl::Vector<NodePtr> elifNodes;
        NodePtr ifNode;
        NodePtr elseNode;

    public:
        IfStmt(Visitor &visitor, FscParser::If_stmtContext *ctx);

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

    private:
        auto parseIfStmt(Visitor &visitor, FscParser::IfContext *ctx) -> void;
        auto parseElifStmt(Visitor &visitor, FscParser::ElifContext *ctx) -> void;
        auto parseElseStmt(Visitor &visitor, FscParser::ElseContext *ctx) -> void;
    };
}// namespace fsc::ast

#endif /* FSC_IF_STMT_HPP */
