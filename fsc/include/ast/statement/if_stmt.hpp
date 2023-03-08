#ifndef FSC_IF_STMT_HPP
#define FSC_IF_STMT_HPP

#include "ast/statement/if.hpp"
#include "visitor.hpp"
#include <type/antlr-types.hpp>

namespace fsc::ast
{
    class IfStmt final : public NodeWrapper<NodeType::IF_STMT, SemicolonNeed::DO_NOT_NEED>
    {
    private:
        ccl::Vector<NodePtr> elifNodes;
        NodePtr ifNode;
        NodePtr elseNode;

    public:
        IfStmt(IfStatementContext *ctx);

        auto analyze() -> AnalysisReport final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;

        auto optimize(OptimizationLevel level) -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

    private:
        auto parseIfStmt(IfContext *ctx) -> void;
        auto parseElifStmt(ElifContext *ctx) -> void;
        auto parseElseStmt(ElseContext *ctx) -> void;
    };
}// namespace fsc::ast

#endif /* FSC_IF_STMT_HPP */
