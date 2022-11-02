#ifndef FSC_VISITOR_HPP
#define FSC_VISITOR_HPP

#include "FscBaseVisitor.h"
#include "ast/program.hpp"

namespace fsc {
    class Visitor : public FscBaseVisitor {
    public:
        auto callMain() -> void;

        auto visitNode(auto *node) -> std::shared_ptr<ast::Node>
        {
            return castToNode(visit(node));
        }

    private:
        auto visitProgram(FscParser::ProgramContext *ctx) -> std::any override;
        auto visitStmt(FscParser::StmtContext *ctx) -> std::any override;
        auto visitFunction(FscParser::FunctionContext *ctx) -> std::any override;
        auto visitVariable_definition(FscParser::Variable_definitionContext *ctx)
                -> std::any override;
        auto visitAuto_variable_definition(FscParser::Auto_variable_definitionContext *ctx)
                -> std::any override;
        auto visitClass(FscParser::ClassContext *ctx) -> std::any override;
        auto visitBody(FscParser::BodyContext *ctx) -> std::any override;
        auto visitExpr(FscParser::ExprContext *ctx) -> std::any override;
        auto visitFunction_call(FscParser::Function_callContext *ctx) -> std::any override;

        auto constructVariableDefinition(FscParser::Variable_definitionContext *ctx)

                -> std::shared_ptr<ast::Node>;
        auto constructAutoVariableDefinition(FscParser::Auto_variable_definitionContext *ctx)
                -> std::shared_ptr<ast::Node>;

        auto constructClass(FscParser::ClassContext *ctx) -> std::shared_ptr<ast::Node>;

        auto constructConversion(FscParser::ExprContext *ctx) -> std::shared_ptr<ast::Node>;

        template<typename BodyT, typename... Ts>
        auto constructBody(FscParser::BodyContext *ctx, Ts &&...args) -> std::shared_ptr<ast::Node>;

        auto constructReturn(FscParser::StmtContext *ctx) -> std::shared_ptr<ast::Node>;

        auto constructBinaryExpression(FscParser::ExprContext *ctx) -> std::shared_ptr<ast::Node>;

        auto processFunctionArguments(FscParser::Function_parameterContext *ctx)
                -> std::pair<std::vector<func::Argument>, std::vector<std::shared_ptr<ast::Node>>>;

        auto constructFunctionArgument(FscParser::Function_argumentContext *argument_context)
                -> std::pair<func::Argument, std::shared_ptr<ast::Node>>;

        static auto castToNode(std::any &to_cast) -> std::shared_ptr<ast::Node>
        {
            return std::any_cast<std::shared_ptr<ast::Node>>(to_cast);
        }

        static auto castToNode(std::any &&to_cast) -> std::shared_ptr<ast::Node>
        {
            return std::any_cast<std::shared_ptr<ast::Node>>(to_cast);
        }

        ast::Program program;
    };
}// namespace fsc

#endif /* FSC_VISITOR_HPP */
