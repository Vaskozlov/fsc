#include "visitor.hpp"
#include "ast/node.hpp"
#include "builtin/statements.hpp"
#include "functions.hpp"
#include "stack.hpp"
#include <fmt/format.h>

namespace fsc {
    static auto convertInt(const std::string &repr) -> std::any
    {
        ssize_t result = 0;

        if (repr.starts_with("0b")) {
            result = std::stol(repr.substr(2), nullptr, 2);
        } else if (repr.starts_with("0o")) {
            result = std::stol(repr.substr(2), nullptr, 8);
        } else if (repr.starts_with("0x")) {
            result = std::stol(repr.substr(2), nullptr, 16);
        } else {

            result = std::stol(repr);
        }

        if (result >= 0) {
            if (result > std::numeric_limits<int32_t>::max()) {
                return result;
            }

            return static_cast<int32_t>(result);
        }

        if (result < std::numeric_limits<int32_t>::min()) {
            return result;
        }

        return static_cast<int32_t>(result);
    }

    static auto convertFloat(const std::string &repr) -> std::any
    {
        return std::stof(repr);
    }

    auto Visitor::visitStmt(FscParser::StmtContext *ctx) -> std::any
    {
        const auto &children = ctx->children;

        if (const auto first_child = children[0]->getText(); first_child == "return") {
            return ReturnStatement{visit(children[1])};
        }

        return visitChildren(ctx);
    }

    auto Visitor::visitFunction(FscParser::FunctionContext *ctx) -> std::any
    {
        return Functions.add(ctx);
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
        const auto &children = ctx->children;

        for (auto &&child :
             children | std::views::drop(1) | std::views::take(ctx->children.size() - 2)) {
            auto result = visit(child);

            if (result.type() == typeid(ReturnStatement)) {
                return std::any_cast<ReturnStatement>(result).value;
            }
        }

        return std::any{};
    }

    auto Visitor::visitExpr(FscParser::ExprContext *ctx) -> std::any
    {
        const auto &children = ctx->children;

        if (children.at(0)->getText() == "(") {
            return visit(children[1]);
        }

        if (ctx->NAME() != nullptr) {
            return ProgramsStack.get(ctx->getText()).value; /* Handle as variable */
        }

        if (ctx->INT() != nullptr) {
            return FscValue{convertInt(ctx->getText()), Int32::hash};
        }

        if (ctx->FLOAT() != nullptr) {
            return FscValue{convertFloat(ctx->getText()), Float::hash};
        }

        if (ctx->ADD() != nullptr) {
            return binaryOperation("__add__", children);
        }

        if (ctx->SUB() != nullptr) {
            return binaryOperation("__sub__", children);
        }

        if (ctx->MUL() != nullptr) {
            return binaryOperation("__mul__", children);
        }

        if (ctx->DIV() != nullptr) {
            return binaryOperation("__div__", children);
        }

        return std::any{};
    }

    auto Visitor::binaryOperation(const std::string &function_name,
                                  const std::vector<antlr4::tree::ParseTree *> &children)
            -> std::any
    {
        const auto lhs = std::any_cast<FscValue>(visit(children[0]));
        const auto rhs = std::any_cast<FscValue>(visit(children[2]));

        auto function = Functions.get(function_name, {createArgument(lhs), createArgument(rhs)});
        const auto &args = function.getArguments();

        ProgramsStack.pushScope();
        ProgramsStack.addVariable(args[0].name, lhs);
        ProgramsStack.addVariable(args[1].name, rhs);

        auto result = function.invoke(*this);

        ProgramsStack.popScope();

        return result;
    }

    auto Visitor::callMain() -> void
    {
        ProgramsStack.pushScope();

        auto function = Functions.get("main", {});
        auto result = function.invoke(*this);

        ProgramsStack.popScope();

        if (result.type == Int32::hash) {
            fmt::print("{}\n", std::any_cast<int32_t>(result.value));
        } else if (result.type == Float::hash) {
            fmt::print("{}\n", std::any_cast<float>(result.value));
        }
    }
}// namespace fsc
