#include "visitor.hpp"
#include "ast/container/body.hpp"
#include <ccl/handler/cmd_handler.hpp>
#include <ccl/text/iterator_exception.hpp>
#include <ccl/text/location.hpp>
#include <cstdlib>
#include <exception>
#include <ranges>

using namespace std::string_view_literals;

namespace fsc
{
    extern template auto Visitor::constructBody<ast::Body>(FscParser::BodyContext *ctx)
        -> ast::NodePtr;

    auto Visitor::throwError(antlr4::ParserRuleContext *ctx, std::string_view message) -> void
    {
        auto &handler = ccl::handler::Cmd::instance();
        auto location = ccl::text::Location{
            filename, ctx->start->getLine(), ctx->start->getCharPositionInLine()};
        auto length = ctx->stop->getCharPositionInLine() - ctx->start->getCharPositionInLine() +
                      ctx->stop->getText().size();

        auto iterator_exception = ccl::text::TextIteratorException{
            ccl::ExceptionCriticality::PANIC,
            ccl::AnalysisStage::PARSING,
            location,
            length,
            inputAsLines[location.getLine() - 1],
            message,
            ""};

        handler.handle(iterator_exception);
        std::exit(1);
    }

    auto Visitor::visitProgram(FscParser::ProgramContext *ctx) -> std::any
    {
        try {
            constructProgram(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }

        return {};
    }

    auto Visitor::visitStmt(FscParser::StmtContext *const ctx) -> std::any
    {
        try {
            return constructStatement(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitWhile_loop(FscParser::While_loopContext *ctx) -> std::any
    {
        try {
            return constructWhile(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitExpr(FscParser::ExprContext *ctx) -> std::any
    {
        try {
            return constructExpression(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitIf_stmt(FscParser::If_stmtContext *ctx) -> std::any
    {
        try {
            return constructIf(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitFunction(FscParser::FunctionContext *const ctx) -> std::any
    {
        try {
            return constructFunction(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitVariable_definition(FscParser::Variable_definitionContext *const ctx)
        -> std::any
    {
        try {
            return visitChildren(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitAuto_variable_definition(
        FscParser::Auto_variable_definitionContext *const ctx) -> std::any
    {
        try {
            return visitChildren(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitClass(FscParser::ClassContext *ctx) -> std::any
    {
        try {
            return constructClass(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitBody(FscParser::BodyContext *const ctx) -> std::any
    {
        try {
            return constructBody<ast::Body>(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitFunction_call(FscParser::Function_callContext *ctx) -> std::any
    {
        try {
            return constructFunctionCall(ctx);
        } catch (const std::exception &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::codeGen() -> std::string
    {
        auto generator = ccl::codegen::BasicCodeGenerator{};

        program.print("", false);

        generator << program;
        return generator.getCode();
    }

    auto Visitor::analyze() const -> void
    {
        program.analyze();
    }
}// namespace fsc
