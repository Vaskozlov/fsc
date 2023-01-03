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
        try {
            constructProgram(ctx);
        } catch (const std::exception &e) {
            parser.notifyErrorListeners(ctx->getStart(), e.what(), std::make_exception_ptr(e));
            exit(0);
        }

        return {};
    }

    auto Visitor::visitStmt(FscParser::StmtContext *const ctx) -> std::any
    {
        try {
            return constructStatement(ctx);
        } catch (const std::exception &e) {
            parser.notifyErrorListeners(ctx->getStart(), e.what(), std::make_exception_ptr(e));
            exit(0);
        }
    }

    auto Visitor::visitWhile_loop(FscParser::While_loopContext *ctx) -> std::any
    {
        try {
            return constructWhile(ctx);
        } catch (const std::exception &e) {
            parser.notifyErrorListeners(ctx->getStart(), e.what(), std::make_exception_ptr(e));
            exit(0);
        }
    }

    auto Visitor::visitIf_stmt(FscParser::If_stmtContext *ctx) -> std::any
    {
        try {
            return constructIf(ctx);
        } catch (const std::exception &e) {
            parser.notifyErrorListeners(ctx->getStart(), e.what(), std::make_exception_ptr(e));
            exit(0);
        }
    }

    auto Visitor::visitFunction(FscParser::FunctionContext *const ctx) -> std::any
    {
        try {
            return constructFunction(ctx);
        } catch (const std::exception &e) {
            parser.notifyErrorListeners(ctx->getStart(), e.what(), std::make_exception_ptr(e));
            exit(0);
        }
    }

    auto Visitor::visitVariable_definition(FscParser::Variable_definitionContext *const ctx)
        -> std::any
    {
        try {
            return visitChildren(ctx);
        } catch (const std::exception &e) {
            parser.notifyErrorListeners(ctx->getStart(), e.what(), std::make_exception_ptr(e));
            exit(0);
        }
    }

    auto Visitor::visitAuto_variable_definition(
        FscParser::Auto_variable_definitionContext *const ctx) -> std::any
    {
        try {
            return visitChildren(ctx);
        } catch (const std::exception &e) {
            parser.notifyErrorListeners(ctx->getStart(), e.what(), std::make_exception_ptr(e));
            exit(0);
        }
    }

    auto Visitor::visitClass(FscParser::ClassContext *ctx) -> std::any
    {
        try {
            return constructClass(ctx);
        } catch (const std::exception &e) {
            parser.notifyErrorListeners(ctx->getStart(), e.what(), std::make_exception_ptr(e));
            exit(0);
        }
    }

    auto Visitor::visitBody(FscParser::BodyContext *const ctx) -> std::any
    {
        try {
            return constructBody<ast::Body>(ctx);
        } catch (const std::exception &e) {
            parser.notifyErrorListeners(ctx->getStart(), e.what(), std::make_exception_ptr(e));
            exit(0);
        }
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
