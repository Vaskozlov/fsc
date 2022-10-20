#include "visitor.hpp"
#include "ast/function_node.hpp"
#include "functions.hpp"
#include "stack.hpp"
#include <fmt/format.h>

using namespace std::string_view_literals;

namespace fsc {
    [[nodiscard]] static auto convertInt(const std::string &repr) -> std::shared_ptr<AstNode>
    {
        ssize_t result = 0;

        if (repr.starts_with("0b")) {
            result = std::stol(repr.substr("0b"sv.size()), nullptr, 2);
        } else if (repr.starts_with("0o")) {
            result = std::stol(repr.substr("0o"sv.size()), nullptr, 8);
        } else if (repr.starts_with("0x")) {
            result = std::stol(repr.substr("0x"sv.size()), nullptr, 16);
        } else {
            result = std::stol(repr);
        }

        if ((result > std::numeric_limits<int32_t>::max()) ||
            (result < std::numeric_limits<int32_t>::min())) {
            return std::make_shared<ValueExpression>(FscValue{result, Int64::hash});
        }

        return std::make_shared<ValueExpression>(
                FscValue{static_cast<int32_t>(result), Int32::hash});
    }

    [[nodiscard]] static auto convertFloat(const std::string &repr) -> std::shared_ptr<AstNode>
    {
        return std::make_shared<ValueExpression>(FscValue{std::stof(repr), Float::hash});
    }

    auto Visitor::visitStmt(FscParser::StmtContext *ctx) -> std::any
    {
        const auto &children = ctx->children;

        if (const auto first_child = children[0]->getText(); first_child == "return") {
            return constructReturn(ctx);
        }

        return visitChildren(ctx);
    }

    auto Visitor::constructReturn(FscParser::StmtContext *ctx) -> std::shared_ptr<AstNode>
    {
        const auto &children = ctx->children;

        return std::make_shared<ReturnStatement>(
                std::any_cast<std::shared_ptr<AstNode>>(visit(children[1])));
    }

    auto Visitor::visitFunction(FscParser::FunctionContext *ctx) -> std::any
    {
        Functions.add(ctx, *this);
        return std::any{};
    }

    auto Visitor::visitVariable_definition(FscParser::Variable_definitionContext *ctx) -> std::any
    {
        return visitChildren(ctx);
    }

    auto Visitor::visitAuto_variable_definition(FscParser::Auto_variable_definitionContext *ctx)
            -> std::any
    {
        return visitChildren(ctx);
    }

    auto Visitor::visitBody(FscParser::BodyContext *ctx) -> std::any
    {
        return constructBody(ctx);
    }

    auto Visitor::constructBody(FscParser::BodyContext *ctx) -> std::shared_ptr<AstNode>
    {
        const auto &children = ctx->children;
        auto body = std::make_shared<Body>();

        for (auto &&child :
             children | std::views::drop(1) | std::views::take(ctx->children.size() - 2)) {
            if (child->getText() == "\n") {
                continue;
            }

            body->addNode(std::any_cast<std::shared_ptr<AstNode>>(visit(child)));
        }

        return body;
    }

    auto Visitor::visitExpr(FscParser::ExprContext *ctx) -> std::any
    {
        const auto &children = ctx->children;
        auto node = std::shared_ptr<AstNode>{};

        if (ctx->INT() != nullptr) {
            node = convertInt(ctx->getText());
        } else if (ctx->FLOAT() != nullptr) {
            node = convertFloat(ctx->getText());
        } else if (ctx->NAME() != nullptr) {
            node = constructVariable(ctx->getText());
        } else if (ctx->ADD() != nullptr) {
            node = binaryOperation("__add__", children);
        } else if (ctx->MUL() != nullptr) {
            node = binaryOperation("__mul__", children);
        } else if (ctx->DIV() != nullptr) {
            node = binaryOperation("__div__", children);
        } else if (ctx->MOD() != nullptr) {
            node = binaryOperation("__mod__", children);
        } else if (ctx->function_call()) {
            node = constructFunctionCall(ctx);
        }

        if (node != nullptr) {
            return node;
        }

        return visitChildren(ctx);
    }

    auto Visitor::constructFunctionCall(FscParser::ExprContext *ctx) -> std::shared_ptr<AstNode>
    {
        const auto &children = ctx->children;
        const auto name = children.at(0)->getText();
        const auto parameters = getFunctionArguments(
                dynamic_cast<FscParser::Function_parameterContext *>(children.at(1)));
        auto function = Functions.get(name, parameters);

        return std::make_shared<FunctionCall>(FunctionCall{function, {}});
    }

    auto Visitor::getFunctionArguments(FscParser::Function_parameterContext *function_parameters)
            -> std::vector<FunctionArgument>
    {
        const auto &children = function_parameters->children;
        auto result = std::vector<FunctionArgument>{};

        for (const auto &parameter :
             children | std::views::drop(1) | std::views::take(children.size() - 2)) {
            result.push_back(constructFunctionArgument(
                    dynamic_cast<FscParser::Function_argumentContext *>(parameter)));
        }

        return result;
    }

    auto Visitor::constructFunctionArgument(FscParser::Function_argumentContext *argument_context)
            -> FunctionArgument
    {
        const auto &children = argument_context->children;
        auto argument_node = std::any_cast<std::shared_ptr<AstNode>>(visit(children.back()));
        return createArgument(argument_node->getValueType());
    }

    auto Visitor::constructVariable(const std::string &name) -> std::shared_ptr<AstNode>
    {
        return std::make_shared<VariableExpression>(name);
    }

    auto Visitor::binaryOperation(const std::string &function_name,
                                  const std::vector<antlr4::tree::ParseTree *> &children)
            -> std::shared_ptr<AstNode>
    {
        const auto lhs = std::any_cast<std::shared_ptr<AstNode>>(visit(children[0]));
        const auto rhs = std::any_cast<std::shared_ptr<AstNode>>(visit(children[2]));

        auto function = Functions.get(function_name, {createArgument(lhs->getValueType()),
                                                      createArgument(rhs->getValueType())});

        return std::make_shared<FunctionCall>(FunctionCall{function, {lhs, rhs}});
    }

    auto Visitor::callMain() -> void
    {
        ProgramsStack.pushScope();

        auto function = Functions.get("main", {});
        auto result = function.invoke();

        ProgramsStack.popScope();

        if (result.type == Int32::hash) {
            fmt::print("{}\n", std::any_cast<int32_t>(result.value));
        } else if (result.type == Float::hash) {
            fmt::print("{}\n", std::any_cast<float>(result.value));
        }
    }
}// namespace fsc
