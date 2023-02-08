#include "ast/function/function_call.hpp"
#include "ast/function/method_call.hpp"
#include "FscParser.h"
#include "function/functions_holder.hpp"
#include "visitor.hpp"
#include <ast/value/variable.hpp>
#include <type/antlr-types.hpp>

namespace fsc
{
    using namespace ccl;
    namespace sv = std::views;

    static constexpr auto CommaFilter(antlr4::tree::ParseTree *elem) -> bool
    {
        const auto text = elem->getText();
        return !text.empty() && text[0] != ',';
    }

    auto Visitor::parseFunction(FunctionCallContext *ctx) -> std::tuple<
        std::string, SmallVector<FscType>, SmallVector<Argument>, SmallVector<ast::NodePtr>>
    {
        const auto &children = ctx->children;
        const auto name = children.at(0)->getText();
        auto *args = children.at(2);
        auto [arguments, values] = processFunctionArguments(as<FunctionParameterContext *>(args));

        auto templates = SmallVector<FscType>{};
        auto *template_context = as<TemplateContext *>(children.at(1));

        if (!template_context->children.empty()) {
            const auto &templates_children = template_context->children.at(1)->children;

            for (auto *function_template : templates_children | sv::filter(CommaFilter)) {
                templates.emplace_back(function_template->getText());
            }
        }

        return std::make_tuple(name, std::move(templates), std::move(arguments), std::move(values));
    }

    auto Visitor::constructFunctionCall(FunctionCallContext *ctx) -> ast::NodePtr
    {
        auto [name, templates, arguments, values] = parseFunction(ctx);

        return makeShared<ast::Node, ast::FunctionCall>(
            func::Functions.get({name, arguments, Void}), values, templates);
    }

    auto Visitor::constructMethodCall(ExpressionContext *ctx) -> ast::NodePtr
    {
        auto *function_call_context =
            as<FunctionCallContext *>(ctx->children.at(1)->children.at(1));

        auto expression = visitAsNode(ctx->children.at(0));
        auto [name, templates, arguments, values] = parseFunction(function_call_context);

        return makeShared<ast::Node, ast::MethodCall>(
            expression, func::Functions.get({name, arguments, expression->getValueType()}), values, templates);
    }


    auto Visitor::processFunctionArguments(FunctionParameterContext *ctx)
        -> Pair<SmallVector<Argument>, SmallVector<ast::NodePtr>>
    {
        const auto &children = ctx->children;
        auto *argument_list = as<FunctionTypedArgumentsListContext *>(children[1]);
        auto result = Pair<SmallVector<Argument>, SmallVector<ast::NodePtr>>{};
        auto &[arguments, nodes] = result;

        if (argument_list != nullptr) {
            for (auto *parameter : argument_list->children | sv::filter(CommaFilter)) {
                auto [argument, node] =
                    constructFunctionArgument(as<FunctionArgumentContext *>(parameter));
                arguments.push_back(argument);
                nodes.push_back(std::move(node));
            }
        }

        return result;
    }

    auto Visitor::constructFunctionArgument(FunctionArgumentContext *argument_context)
        -> Pair<Argument, ast::NodePtr>
    {
        const auto &children = argument_context->children;
        auto argument_node = visitAsNode(children.back());
        auto argument_type = argument_node->getValueType();
        return {{children.front()->getText(), argument_type, {}}, argument_node};
    }
}// namespace fsc
