#ifndef FSC_VISITOR_HPP
#define FSC_VISITOR_HPP

#include "ast/program.hpp"
#include "FscBaseVisitor.h"
#include "function/argument.hpp"
#include <FscParser.h>
#include <ast/basic_node.hpp>

namespace fsc
{
    class Visitor : public FscBaseVisitor
    {
    private:
        ast::Program program;

    public:
        auto codeGen() -> void;

        auto visitNode(auto *node) -> ccl::SharedPtr<ast::Node>
        {
            return castToNode(visit(node));
        }

    private:
        static auto castToNode(std::any &to_cast) -> ast::NodePtr
        {
            return std::any_cast<ast::NodePtr>(to_cast);
        }

        static auto castToNode(std::any &&to_cast) -> ast::NodePtr
        {
            return std::any_cast<ast::NodePtr>(to_cast);
        }

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
            -> ast::NodePtr;

        auto constructMemberVariableAccess(FscParser::ExprContext *ctx) -> ast::NodePtr;

        auto constructAutoVariableDefinition(FscParser::Auto_variable_definitionContext *ctx)
            -> ast::NodePtr;

        auto constructClass(FscParser::ClassContext *ctx) -> ast::NodePtr;

        auto constructConversion(FscParser::ExprContext *ctx) -> ast::NodePtr;

        template<typename BodyT, typename... Ts>
        auto constructBody(FscParser::BodyContext *ctx, Ts &&...args) -> ast::NodePtr;

        auto constructReturn(FscParser::StmtContext *ctx) -> ast::NodePtr;

        auto constructBinaryExpression(FscParser::ExprContext *ctx) -> ast::NodePtr;

        auto processFunctionArguments(FscParser::Function_parameterContext *ctx)
            -> ccl::Pair<ccl::SmallVector<Argument>, ccl::SmallVector<ast::NodePtr>>;

        auto constructFunctionArgument(FscParser::Function_argumentContext *argument_context)
            -> ccl::Pair<Argument, ast::NodePtr>;
    };
}// namespace fsc

#endif /* FSC_VISITOR_HPP */
