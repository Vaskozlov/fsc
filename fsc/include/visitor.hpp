#ifndef FSC_VISITOR_HPP
#define FSC_VISITOR_HPP

#include "ast/container/program.hpp"
#include "codegen.hpp"
#include "FscBaseVisitor.h"
#include "function/argument.hpp"
#include <ANTLRInputStream.h>
#include <ccl/raii.hpp>
#include <FscParser.h>
#include <tuple>

namespace fsc
{
    class Visitor : public FscBaseVisitor
    {
    private:
        friend class FunctionScope;

        ast::Program program;
        ccl::Vector<ccl::Id> functionReturnStack;
        antlr4::ANTLRInputStream &inputStream;
        FscParser &parser;

    public:
        explicit Visitor(antlr4::ANTLRInputStream &input, FscParser &fsc_parser)
          : inputStream{input}
          , parser{fsc_parser}
        {}

        auto codeGen() -> std::string;

        [[nodiscard]] auto getCurrentFunctionReturnType() const -> ccl::Id
        {
            return functionReturnStack.back();
        }

        [[nodiscard]] auto acquireFunctionScope(ccl::Id return_type) -> auto
        {
            return ccl::Raii{
                [this, return_type]() { functionReturnStack.push_back(return_type); },
                [this]() { functionReturnStack.pop_back(); },
            };
        }

        auto updateFunctionReturnType(ccl::Id new_type) -> void
        {
            functionReturnStack.back() = new_type;
        }

        [[nodiscard]] auto visitAsNode(auto *node) -> ccl::SharedPtr<ast::Node>
        {
            return castToNode(visit(node));
        }

    private:
        CCL_PERFECT_FORWARDING(T, std::any)
        static auto castToNode(T &&to_cast) -> ast::NodePtr
        {
            return std::any_cast<ast::NodePtr>(to_cast);
        }

        auto visitProgram(FscParser::ProgramContext *ctx) -> std::any final;

        auto visitStmt(FscParser::StmtContext *ctx) -> std::any final;

        auto visitWhile_loop(FscParser::While_loopContext *ctx) -> std::any final;

        auto visitIf_stmt(FscParser::If_stmtContext *ctx) -> std::any final;

        auto visitFunction(FscParser::FunctionContext *ctx) -> std::any final;

        auto visitVariable_definition(FscParser::Variable_definitionContext *ctx) -> std::any final;

        auto visitAuto_variable_definition(FscParser::Auto_variable_definitionContext *ctx)
            -> std::any final;

        auto visitClass(FscParser::ClassContext *ctx) -> std::any final;

        auto visitBody(FscParser::BodyContext *ctx) -> std::any final;

        auto visitExpr(FscParser::ExprContext *ctx) -> std::any final;

        auto visitFunction_call(FscParser::Function_callContext *ctx) -> std::any final;

        auto constructVariableDefinition(FscParser::Variable_definitionContext *ctx)
            -> ast::NodePtr;

        auto constructMethodCall(FscParser::ExprContext *ctx) -> ast::NodePtr;

        auto constructMemberVariableAccess(FscParser::ExprContext *ctx) -> ast::NodePtr;

        auto constructAutoVariableDefinition(FscParser::Auto_variable_definitionContext *ctx)
            -> ast::NodePtr;

        auto constructProgram(FscParser::ProgramContext *ctx) -> void;

        auto constructClass(FscParser::ClassContext *ctx) -> ast::NodePtr;

        auto constructConversion(FscParser::ExprContext *ctx) -> ast::NodePtr;

        template<typename BodyT, typename... Ts>
        auto constructBody(FscParser::BodyContext *ctx, Ts &&...args) -> ast::NodePtr;

        auto constructReturn(FscParser::StmtContext *ctx) -> ast::NodePtr;

        auto constructIf(FscParser::If_stmtContext *ctx) -> ast::NodePtr;

        auto constructWhile(FscParser::While_loopContext *ctx) -> ast::NodePtr;

        auto constructStatement(FscParser::StmtContext *ctx) -> std::any;

        auto constructParenthesized(FscParser::ExprContext *expr_context) -> ast::NodePtr;

        auto constructBinaryExpression(FscParser::ExprContext *ctx) -> ast::NodePtr;

        auto constructFunctionCall(FscParser::Function_callContext *ctx) -> ast::NodePtr;

        auto constructFunction(FscParser::FunctionContext *ctx) -> ast::NodePtr;

        auto processFunctionArguments(FscParser::Function_parameterContext *ctx)
            -> ccl::Pair<ccl::SmallVector<Argument>, ccl::SmallVector<ast::NodePtr>>;

        auto constructFunctionArgument(FscParser::Function_argumentContext *argument_context)
            -> ccl::Pair<Argument, ast::NodePtr>;

        auto parseFunction(FscParser::Function_callContext *ctx)
            -> std::tuple<std::string, ccl::SmallVector<Argument>, ccl::SmallVector<ast::NodePtr>>;
    };
}// namespace fsc

#endif /* FSC_VISITOR_HPP */
