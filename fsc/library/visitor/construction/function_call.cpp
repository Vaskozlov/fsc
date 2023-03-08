#include "ast/function/function_call.hpp"
#include "ast/function/method_call.hpp"
#include "ast/value/variable.hpp"
#include "filter.hpp"
#include "FscParser.h"
#include "visitor.hpp"

using namespace ccl;
namespace sv = std::views;

auto fsc::Visitor::parseFunction(FunctionCallContext *ctx) -> std::
    tuple<std::string, SmallVector<FscType>, SmallVector<Argument>, SmallVector<ast::NodePtr>>
{
    const auto &children = ctx->children;
    const auto name = children.at(0)->getText();
    auto *args = children.at(2);
    auto [arguments, values] = processFunctionArguments(as<FunctionParameterContext *>(args));

    auto templates = SmallVector<FscType>{};
    auto *template_context = as<TemplateContext *>(children.at(1));

    if (!template_context->children.empty()) {
        const auto &templates_children = template_context->children.at(1)->children;

        for (auto *function_template : templates_children | filter::comma) {
            templates.emplace_back(function_template->getText());
        }
    }

    return std::make_tuple(name, std::move(templates), std::move(arguments), std::move(values));
}

auto fsc::Visitor::constructFunctionCall(FunctionCallContext *ctx) -> ast::NodePtr
{
    return preparerToCatchError(
        [this, ctx]() {
            auto [name, templates, arguments, values] = parseFunction(ctx);

            auto function_call = makeShared<ast::Node, ast::FunctionCall>(
                name, arguments, Void, values, templates, ctx);
            function_call->setContext(ctx);
            return function_call;
        },
        ctx);
}

auto fsc::Visitor::constructMethodCall(ExpressionContext *ctx) -> ast::NodePtr
{
    auto *function_call_context = as<FunctionCallContext *>(ctx->children.at(1)->children.at(1));

    auto expression = visitAsNode(ctx->children.at(0));
    auto [name, templates, arguments, values] = parseFunction(function_call_context);

    return makeShared<ast::Node, ast::MethodCall>(
        expression, name, arguments, expression->getValueType(), values, templates, ctx);
}


auto fsc::Visitor::processFunctionArguments(FunctionParameterContext *ctx)
    -> Pair<SmallVector<Argument>, SmallVector<ast::NodePtr>>
{
    const auto &children = ctx->children;
    auto *argument_list = as<FunctionTypedArgumentsListContext *>(children.at(1));
    auto result = Pair<SmallVector<Argument>, SmallVector<ast::NodePtr>>{};
    auto &[arguments, nodes] = result;

    if (argument_list != nullptr) {
        for (auto *parameter : argument_list->children | filter::comma) {
            auto [argument, node] =
                constructFunctionArgument(as<FunctionArgumentContext *>(parameter));
            arguments.push_back(argument);
            nodes.push_back(std::move(node));
        }
    }

    return result;
}

auto fsc::Visitor::constructFunctionArgument(FunctionArgumentContext *argument_context)
    -> Pair<Argument, ast::NodePtr>
{
    const auto &children = argument_context->children;
    auto argument_node = visitAsNode(children.back());
    auto argument_type = argument_node->getValueType();
    return {{children.front()->getText(), argument_type, {}}, argument_node};
}
