#ifndef FSC_VISITOR_HPP
#define FSC_VISITOR_HPP

#include "FscBaseVisitor.h"

namespace fsc {
    class Visitor : public FscBaseVisitor {
    public:
        auto main() -> void;

    private:
        auto visitStmt(FscParser::StmtContext *ctx) -> std::any override;
        auto visitFunction(FscParser::FunctionContext *ctx) -> std::any override;
        auto visitVariable_definition(FscParser::Variable_definitionContext *ctx)
                -> std::any override;
        auto visitAuto_variable_definition(FscParser::Auto_variable_definitionContext *ctx)
                -> std::any override;
        auto visitBody(FscParser::BodyContext *ctx) -> std::any override;
        auto visitExpr(FscParser::ExprContext *ctx) -> std::any override;

        auto binaryOperation(const std::string &function_name,
                             const std::vector<antlr4::tree::ParseTree *> &children) -> std::any;
    };
}// namespace fsc

#endif /* FSC_VISITOR_HPP */
