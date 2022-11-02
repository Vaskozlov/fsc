#include "visitor.hpp"
#include "ast/binary_operator.hpp"
#include "ast/body.hpp"
#include "ast/class.hpp"
#include "ast/conversion.hpp"
#include "ast/function.hpp"
#include "ast/function_call.hpp"
#include "ast/return.hpp"
#include "ast/variable.hpp"
#include "ast/variable_definition.hpp"
#include "converters/float.hpp"
#include "converters/int.hpp"
#include "function/functions_holder.hpp"
#include "stack/stack.hpp"
#include <fmt/format.h>
#include <ranges>

using namespace std::string_view_literals;

namespace fsc {
    template<typename BodyT, typename... Ts>
    auto Visitor::constructBody(FscParser::BodyContext *ctx, Ts &&...args)
            -> std::shared_ptr<ast::Node>
    {
        const auto &children = ctx->children;
        auto body = std::make_shared<BodyT>(std::forward<Ts>(args)...);

        if constexpr (std::is_same_v<BodyT, ast::Class>) {
            ProgramStack.pushClassScope(FscType::getTypeId(body->getName()));
        }

        ProgramStack.pushScope(ScopeType::SOFT);

        for (auto &&child :
             children | std::views::drop(1) | std::views::take(ctx->children.size() - 2)) {
            if (child->getText() == "\n") {
                continue;
            }

            body->addNode(visitNode(child));
        }

        ProgramStack.popScope();

        if constexpr (std::is_same_v<BodyT, ast::Class>) {
            ProgramStack.popClassScope();
        }

        return body;
    }

    auto Visitor::visitProgram(FscParser::ProgramContext *ctx) -> std::any
    {
        const auto &children = ctx->children;

        for (const auto &child : children) {
            auto result = visit(child);

            if (result.type() == typeid(std::shared_ptr<ast::Node>)) {
                program.addNode(std::any_cast<std::shared_ptr<ast::Node>>(result));
            }
        }

        return {};
    }

    auto Visitor::visitStmt(FscParser::StmtContext *const ctx) -> std::any
    {
        const auto &children = ctx->children;

        if (children[0]->getText() == "return") {
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
        auto function = func::Function(ctx, *this);
        func::Functions.registerFunction(function);
        return std::shared_ptr<ast::Node>(std::make_shared<ast::Function>(function));
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
        std::shared_ptr<ast::Node> node;

        if (ctx->AS() != nullptr) {
            node = constructConversion(ctx);
        }

        else if (ctx->INT() != nullptr) {
            node = converter::toInt(ctx->getText());
        }

        else if (ctx->FLOAT() != nullptr) {
            node = converter::toFloat(ctx->getText());
        }

        else if (ctx->NAME() != nullptr) {
            node = std::make_shared<ast::Variable>(ProgramStack.get(ctx->getText()));
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

    auto Visitor::constructVariableDefinition(FscParser::Variable_definitionContext *ctx)
            -> std::shared_ptr<ast::Node>
    {
        const auto &children = ctx->children;
        const auto name = children[1]->getText();
        const auto type = children[3]->getText();
        const auto converted_type = FscType::getTypeId(type);
        const auto *expr = dynamic_cast<const FscParser::ExprContext *>(children.back());

        if (expr != nullptr) {
            return std::make_shared<ast::VariableDefinition>(name, converted_type,
                                                             visitNode(children.back()));
        }

        return std::make_shared<ast::VariableDefinition>(name, converted_type);
    }

    auto Visitor::constructAutoVariableDefinition(FscParser::Auto_variable_definitionContext *ctx)
            -> std::shared_ptr<ast::Node>
    {
        const auto &children = ctx->children;
        const auto name = children[1]->getText();
        return std::make_shared<ast::VariableDefinition>(name, visitNode(children.back()));
    }

    auto Visitor::visitFunction_call(FscParser::Function_callContext *ctx) -> std::any
    {
        const auto &children = ctx->children;
        const auto name = children[0]->getText();
        const auto args = children[1];

        auto [argument, values] = processFunctionArguments(
                dynamic_cast<FscParser::Function_parameterContext *>(args));

        const auto function =
                func::Functions.get({name, argument}, func::CallRequirements::EXPLICIT);

        return std::shared_ptr<ast::Node>(std::make_shared<ast::FunctionCall>(function, values));
    }

    auto Visitor::processFunctionArguments(FscParser::Function_parameterContext *ctx)
            -> std::pair<std::vector<func::Argument>, std::vector<std::shared_ptr<ast::Node>>>
    {
        static constexpr auto comma_filter = [](const auto &elem) {
            return elem->getText() != ",";
        };

        const auto &children = ctx->children;
        auto *argument_list =
                dynamic_cast<FscParser::Function_typed_arguments_listContext *>(children[1]);
        auto result =
                std::pair<std::vector<func::Argument>, std::vector<std::shared_ptr<ast::Node>>>{};

        for (const auto &parameter : argument_list->children | std::views::filter(comma_filter)) {
            auto &&[argument, node] = constructFunctionArgument(
                    dynamic_cast<FscParser::Function_argumentContext *>(parameter));
            result.first.push_back(argument);
            result.second.push_back(std::move(node));
        }

        return result;
    }

    auto Visitor::constructFunctionArgument(FscParser::Function_argumentContext *argument_context)
            -> std::pair<func::Argument, std::shared_ptr<ast::Node>>
    {
        const auto &children = argument_context->children;
        auto argument_node = std::any_cast<std::shared_ptr<ast::Node>>(visitNode(children.back()));
        auto argument_type = argument_node->getValueType();
        return {{children.front()->getText(), argument_type, {}}, argument_node};
    }

    auto Visitor::constructClass(FscParser::ClassContext *const ctx) -> std::shared_ptr<ast::Node>
    {
        const auto &children = ctx->children;
        const auto name = children[1]->getText();
        return constructBody<ast::Class>(dynamic_cast<FscParser::BodyContext *>(children.back()),
                                         name);
    }

    auto Visitor::constructConversion(FscParser::ExprContext *ctx) -> std::shared_ptr<ast::Node>
    {
        auto expr_to_convert = visitNode(ctx->children[0]);
        auto target_type = ctx->children[2]->getText();
        return std::make_shared<ast::Conversion>(std::move(expr_to_convert),
                                                 FscType::getTypeId(target_type));
    }

    auto Visitor::constructReturn(FscParser::StmtContext *ctx) -> std::shared_ptr<ast::Node>
    {
        const auto &children = ctx->children;

        return std::make_shared<ast::Return>(visitNode(children[1]));
    }

    auto Visitor::constructBinaryExpression(FscParser::ExprContext *ctx)
            -> std::shared_ptr<ast::Node>
    {
        const auto &children = ctx->children;

        auto lhs = visitNode(children[0]);
        auto rhs = visitNode(children[2]);

        return std::make_shared<ast::BinaryOperation>(children[1]->getText(), std::move(lhs),
                                                      std::move(rhs));
    }

    auto Visitor::callMain() -> void
    {
        program.print("", false);
        gen::CodeGenerator generator;
        program.codeGen(generator);
        fmt::print("{}\n", generator.getGenerated());
    }
}// namespace fsc
