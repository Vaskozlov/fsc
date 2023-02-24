#include "visitor.hpp"
#include "ast/container/body.hpp"
#include <ccl/handler/cmd_handler.hpp>
#include <ccl/text/iterator_exception.hpp>
#include <ccl/text/location.hpp>
#include <cstdlib>
#include <ranges>
#include <type/antlr-types.hpp>

using namespace std::string_view_literals;

namespace fsc
{
    static auto splitTextIntoLines(const std::string &text) -> ccl::Vector<std::string>
    {
        auto split_lines = std::ranges::views::split(text, '\n');
        auto result = ccl::Vector<std::string>{};

        for (auto line : split_lines) {
            result.emplace_back(std::string_view{line});
        }

        return result;
    }

    Visitor::Visitor(std::string_view name_of_file, antlr4::ANTLRInputStream &input)
      : filename{name_of_file}
      , inputStream{input}
      , inputAsLines{splitTextIntoLines(inputStream.toString())}
    {
        ast::SourceFile = filename;
        ast::SourceLines = inputAsLines;
    }

    auto Visitor::throwError(BasicContextPtr ctx, std::string_view message) -> void
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
            inputAsLines.at(location.getLine() - 1),
            message};

        handler.handle(iterator_exception);

        program.print("", true);

        std::exit(1);
    }

    auto Visitor::visitProgram(FscParser::ProgramContext *ctx) -> std::any
    {
        try {
            constructProgram(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }

        return {};
    }

    auto Visitor::visitStmt(FscParser::StmtContext *const ctx) -> std::any
    {
        try {
            return constructStatement(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitWhile_loop(FscParser::While_loopContext *ctx) -> std::any
    {
        try {
            return constructWhile(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitExpr(ExpressionContext *ctx) -> std::any
    {
        try {
            return constructExpression(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitIf_stmt(FscParser::If_stmtContext *ctx) -> std::any
    {
        try {
            return constructIf(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitFunction(FunctionContext *ctx) -> std::any
    {
        try {
            return constructFunction(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitVariable_definition(FscParser::Variable_definitionContext *const ctx)
        -> std::any
    {
        try {
            return visitChildren(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitAuto_variable_definition(
        FscParser::Auto_variable_definitionContext *const ctx) -> std::any
    {
        try {
            return visitChildren(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitClass(FscParser::ClassContext *ctx) -> std::any
    {
        try {
            return constructClass(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitBody(FscParser::BodyContext *const ctx) -> std::any
    {
        try {
            return constructBody(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::visitFunction_call(FscParser::Function_callContext *ctx) -> std::any
    {
        try {
            return constructFunctionCall(ctx);
        } catch (const FscException &e) {
            throwError(ctx, e.what());
        }
    }

    auto Visitor::codeGen() -> std::string
    {
        auto generator = ccl::codegen::BasicCodeGenerator{};
        generator << program;
        return generator.getCode();
    }

    auto Visitor::analyze() -> void
    {
        program.analyze();
    }
}// namespace fsc
