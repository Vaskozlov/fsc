#include "visitor.hpp"
#include "ast/body.hpp"
#include "ast/function.hpp"
#include "stack/stack.hpp"
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
        return constructFunctionCall(ctx);
    }

    auto Visitor::codeGen() -> std::string
    {
        program.print("", false);
        gen::CodeGenerator generator;
        generator << program;
        return generator.getGenerated();
    }
}// namespace fsc
