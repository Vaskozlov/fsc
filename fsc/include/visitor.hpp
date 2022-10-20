#ifndef FSC_VISITOR_HPP
#define FSC_VISITOR_HPP

#include "FscBaseVisitor.h"
#include "ast/node.hpp"
#include "function.hpp"

namespace fsc {
    class Visitor : public FscBaseVisitor {
    public:
        auto callMain() -> void;

    private:
        auto visitStmt(FscParser::StmtContext *ctx) -> std::any override;
        auto visitFunction(FscParser::FunctionContext *ctx) -> std::any override;
        auto visitVariable_definition(FscParser::Variable_definitionContext *ctx)
                -> std::any override;
        auto visitAuto_variable_definition(FscParser::Auto_variable_definitionContext *ctx)
                -> std::any override;
        auto visitBody(FscParser::BodyContext *ctx) -> std::any override;
        auto visitExpr(FscParser::ExprContext *ctx) -> std::any override;

        auto constructVariable(const std::string &name) -> std::shared_ptr<AstNode>;
        auto constructBody(FscParser::BodyContext *ctx) -> std::shared_ptr<AstNode>;
        auto constructFunctionCall(FscParser::ExprContext *ctx) -> std::shared_ptr<AstNode>;
        auto getFunctionArguments(FscParser::Function_parameterContext *function_parameters)
                -> std::vector<FunctionArgument>;
        auto constructFunctionArgument(FscParser::Function_argumentContext *argument_context)
                -> FunctionArgument;
        auto constructReturn(FscParser::StmtContext *ctx) -> std::shared_ptr<AstNode>;
        auto binaryOperation(const std::string &function_name,
                             const std::vector<antlr4::tree::ParseTree *> &children)
                -> std::shared_ptr<AstNode>;

        Program program;
        std::unique_ptr<AstNode> currentNode;
    };
}// namespace fsc

#endif /* FSC_VISITOR_HPP */
