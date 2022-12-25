#include "visitor.hpp"
#include "ast/container/body.hpp"
#include <exception>
#include <ranges>

using namespace std::string_view_literals;

namespace fsc
{
    extern template auto Visitor::constructBody<ast::Body>(FscParser::BodyContext *ctx)
        -> ast::NodePtr;

    auto Visitor::visitProgram(FscParser::ProgramContext *ctx) -> std::any
    {
        constructProgram(ctx);
        return {};
    }

    auto Visitor::visitStmt(FscParser::StmtContext *const ctx) -> std::any
    {
        return constructStatement(ctx);
    }

    auto Visitor::visitWhile_loop(FscParser::While_loopContext *ctx) -> std::any
    {
        return constructWhile(ctx);
    }

    auto Visitor::visitIf_stmt(FscParser::If_stmtContext *ctx) -> std::any
    {
        return constructIf(ctx);
    }

    auto Visitor::visitFunction(FscParser::FunctionContext *const ctx) -> std::any
    {
        return constructFunction(ctx);
    }

    auto Visitor::visitVariable_definition(FscParser::Variable_definitionContext *const ctx)
        -> std::any
    {
        return visitChildren(ctx);
    }

    auto Visitor::visitAuto_variable_definition(
        FscParser::Auto_variable_definitionContext *const ctx) -> std::any
    {
        return visitChildren(ctx);
    }

    auto Visitor::visitClass(FscParser::ClassContext *ctx) -> std::any
    {
        return constructClass(ctx);
    }

    auto Visitor::visitBody(FscParser::BodyContext *const ctx) -> std::any
    {
        return constructBody<ast::Body>(ctx);
    }

    auto Visitor::visitFunction_call(FscParser::Function_callContext *ctx) -> std::any
    {
        try {
            return constructFunctionCall(ctx);
        } catch (const std::exception &e) {
            parser.notifyErrorListeners(ctx->getStart(), e.what(), std::make_exception_ptr(e));
            exit(0);
        }
    }

    auto Visitor::codeGen() -> std::string
    {
        program.print("", false);
        gen::CodeGenerator generator;
        generator << program;
        return generator.getGenerated();
    }
}// namespace fsc
