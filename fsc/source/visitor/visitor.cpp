#include "visitor.hpp"
#include "ast/body.hpp"
#include "ast/function.hpp"
#include "ast/function_call.hpp"
#include "ast/variable.hpp"
#include "converters/float.hpp"
#include "converters/int.hpp"
#include "function/functions_holder.hpp"
#include "stack/stack.hpp"
#include <ccl/ccl.hpp>
#include <ranges>

using namespace std::string_view_literals;

namespace fsc {
    extern template auto Visitor::constructBody<ast::Body>(FscParser::BodyContext *ctx)
            -> ast::NodePtr;

    auto Visitor::visitProgram(FscParser::ProgramContext *ctx) -> std::any
    {
        const auto &children = ctx->children;

        for (auto *child : children) {
            auto result = visit(child);

            if (result.type() == typeid(ast::NodePtr)) {
                program.addNode(castToNode(result));
            }
        }

        return {};
    }

    auto Visitor::visitStmt(FscParser::StmtContext *const ctx) -> std::any
    {
        const auto &children = ctx->children;

        if (children[0]->getText() == "return"sv) {
            return constructReturn(ctx);
        }

        if (ctx->function() != nullptr) {
            return visitFunction(ctx->function());
        }

        if (ctx->class_() != nullptr) {
            return visitClass(ctx->class_());
        }

        if (ctx->expr() != nullptr) {
            return visitExpr(ctx->expr());
        }

        return visitChildren(ctx);
    }

    auto Visitor::visitFunction(FscParser::FunctionContext *const ctx) -> std::any
    {
        auto function =
                ccl::makeShared<ast::Function>(ctx, *this, ProgramStack.getCurrentClassScope());
        func::Functions.registerFunction(function);
        return ccl::SharedPtr<ast::Node>(function);
    }

    auto Visitor::visitVariable_definition(FscParser::Variable_definitionContext *const ctx)
            -> std::any
    {
        return visitChildren(ctx);
    }

    auto
    Visitor::visitAuto_variable_definition(FscParser::Auto_variable_definitionContext *const ctx)
            -> std::any
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

    auto Visitor::visitExpr(FscParser::ExprContext *const ctx) -> std::any
    {
        auto node = ast::NodePtr{};
        const auto &children = ctx->children;

        if (ctx->AS() != nullptr) {
            node = constructConversion(ctx);
        }

        else if (ctx->INT() != nullptr) {
            node = converter::toInt(ctx->getText());
        }

        else if (ctx->FLOAT() != nullptr) {
            node = converter::toFloat(ctx->getText());
        }

        else if (children.size() == 3 && children.at(1)->getText() == ".") {
            fmt::print("Member access \n");
        }

        else if (ctx->NAME() != nullptr) {
            node = ccl::makeShared<ast::Variable>(ProgramStack.get(ctx->getText()));
        }

        else if (ctx->function_call() != nullptr) {
            node = visitNode(ctx->function_call());
        }

        else if (ctx->ADD() != nullptr || ctx->SUB() != nullptr || ctx->MUL() != nullptr ||
                 ctx->DIV() != nullptr || ctx->MUL() != nullptr || ctx->EQUALITY() != nullptr ||
                 ctx->INEQUALITY() != nullptr || ctx->LOGICAL_AND() != nullptr ||
                 ctx->LOGICAL_OR() != nullptr) {
            node = constructBinaryExpression(ctx);
        }

        else if (ctx->variable_definition()) {
            node = constructVariableDefinition(ctx->variable_definition());
        }

        else if (ctx->auto_variable_definition()) {
            node = constructAutoVariableDefinition(ctx->auto_variable_definition());
        }

        else {
            return visitChildren(ctx);
        }

        return node;
    }

    auto Visitor::visitFunction_call(FscParser::Function_callContext *ctx) -> std::any
    {
        const auto &children = ctx->children;
        const auto name = children[0]->getText();
        auto *args = children[1];

        auto [argument, values] =
                processFunctionArguments(ccl::as<FscParser::Function_parameterContext *>(args));

        const auto &function = func::Functions.get({name, argument}, CallRequirements::EXPLICIT);

        return ccl::makeShared<ast::Node, ast::FunctionCall>(function, values);
    }

    auto Visitor::codeGen() -> void
    {
        program.print("", false);
        gen::CodeGenerator generator;
        program.codeGen(generator);
        fmt::print("{}\n", generator.getGenerated());
    }
}// namespace fsc
