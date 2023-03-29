#include "visitor.hpp"
#include "ast/container/body.hpp"
#include "function/functions_holder.hpp"
#include <ccl/handler/cmd.hpp>
#include <ccl/text/iterator_exception.hpp>
#include <ccl/text/location.hpp>
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

    auto Visitor::throwError(
        ccl::ExceptionCriticality exception_criticality, BasicContextPtr ctx,
        std::string_view message, std::string_view suggestion) -> void
    {
        auto &handler = ccl::handler::Cmd::instance();
        auto location = ccl::text::Location{
            filename, ctx->start->getLine(), ctx->start->getCharPositionInLine()};
        auto length = ctx->stop->getCharPositionInLine() - ctx->start->getCharPositionInLine() +
                      ctx->stop->getText().size();

        auto iterator_exception = ccl::text::TextIteratorException{
            exception_criticality,
            ccl::AnalysisStage::PARSING,
            location,
            length,
            inputAsLines.at(location.getLine() - 1),
            message,
            suggestion};

        handler.handle(iterator_exception);

        if (exception_criticality != ccl::ExceptionCriticality::WARNING &&
            exception_criticality != ccl::ExceptionCriticality::SUGGESTION) {
            program.print("", true);
            std::terminate();
        }
    }

    auto Visitor::visitProgram(FscParser::ProgramContext *ctx) -> std::any
    {
        preparerToCatchError(
            [this, ctx]() {
                constructProgram(ctx);
            },
            ctx);

        return {};
    }

    auto Visitor::visitStmt(FscParser::StmtContext *const ctx) -> std::any
    {
        return preparerToCatchError(
            [this, ctx]() {
                return constructStatement(ctx);
            },
            ctx);
    }

    auto Visitor::visitWhile_loop(FscParser::While_loopContext *ctx) -> std::any
    {
        return preparerToCatchError(
            [this, ctx]() {
                return constructWhile(ctx);
            },
            ctx);
    }

    auto Visitor::visitExpr(ExpressionContext *ctx) -> std::any
    {
        return preparerToCatchError(
            [this, ctx]() {
                return constructExpression(ctx);
            },
            ctx);
    }

    auto Visitor::visitIf_stmt(FscParser::If_stmtContext *ctx) -> std::any
    {
        return preparerToCatchError(
            [this, ctx]() {
                return constructIf(ctx);
            },
            ctx);
    }

    auto Visitor::visitFunction(FunctionContext *ctx) -> std::any
    {
        return preparerToCatchError(
            [this, ctx]() {
                return constructFunction(ctx);
            },
            ctx);
    }

    auto Visitor::visitVariable_definition(FscParser::Variable_definitionContext *const ctx)
        -> std::any
    {
        return preparerToCatchError(
            [this, ctx]() {
                return visitChildren(ctx);
            },
            ctx);
    }

    auto Visitor::visitAuto_variable_definition(
        FscParser::Auto_variable_definitionContext *const ctx) -> std::any
    {
        return preparerToCatchError(
            [this, ctx]() {
                return visitChildren(ctx);
            },
            ctx);
    }

    auto Visitor::visitClass(FscParser::ClassContext *ctx) -> std::any
    {
        return preparerToCatchError(
            [this, ctx]() {
                return constructClass(ctx);
            },
            ctx);
    }

    auto Visitor::visitBody(FscParser::BodyContext *const ctx) -> std::any
    {
        return preparerToCatchError(
            [this, ctx]() {
                return constructBody(ctx);
            },
            ctx);
    }

    auto Visitor::visitFunction_call(FscParser::Function_callContext *ctx) -> std::any
    {
        return preparerToCatchError(
            [this, ctx]() {
                return constructFunctionCall(ctx);
            },
            ctx);
    }

    auto Visitor::codeGen() -> std::string
    {
        auto generator = ccl::codegen::BasicCodeGenerator{};
        generator << program;
        return generator.getCode();
    }

    auto Visitor::analyze() -> void
    {
        auto main_func = func::Functions.get(SignatureView{"main", {}, Void});
        main_func->analyzeOnCall({}, {});
        program.analyze();
    }

    auto Visitor::optimize(ast::OptimizationLevel level) -> void
    {
        program.optimize(level);
    }
}// namespace fsc
