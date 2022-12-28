#include "ast/function/function_call.hpp"
#include "ast/function/method_call.hpp"
#include "FscParser.h"
#include "function/functions_holder.hpp"
#include "visitor.hpp"
#include <ast/value/variable.hpp>

namespace fsc
{
    static constexpr auto CommaFilter(antlr4::tree::ParseTree *elem) -> bool
    {
        const auto text = elem->getText();
        return !text.empty() && text[0] != ',';
    }

    auto Visitor::parseFunction(FscParser::Function_callContext *ctx)
        -> std::tuple<std::string, ccl::SmallVector<Argument>, ccl::SmallVector<ast::NodePtr>>
    {
        const auto &children = ctx->children;
        const auto name = children.at(0)->getText();
        auto *args = children.at(1);

        auto [arguments, values] =
            processFunctionArguments(ccl::as<FscParser::Function_parameterContext *>(args));
        return std::make_tuple(name, std::move(arguments), std::move(values));
    }

    auto Visitor::constructFunctionCall(FscParser::Function_callContext *ctx) -> ast::NodePtr
    {
        auto [name, arguments, values] = parseFunction(ctx);

        return ccl::makeShared<ast::Node, ast::FunctionCall>(
            func::Functions.get({name, arguments}), values);
    }

    auto Visitor::constructMethodCall(FscParser::ExprContext *ctx) -> ast::NodePtr
    {
        auto *function_call_context =
            ccl::as<FscParser::Function_callContext *>(ctx->children.at(1)->children.at(1));

        auto expression = visitAsNode(ctx->children.at(0));
        auto [name, arguments, values] = parseFunction(function_call_context);

        return ccl::makeShared<ast::Node, ast::MethodCall>(
            expression, func::Functions.get({name, arguments, expression->getValueType()}), values);
    }


    auto Visitor::processFunctionArguments(FscParser::Function_parameterContext *ctx)
        -> ccl::Pair<ccl::SmallVector<Argument>, ccl::SmallVector<ast::NodePtr>>
    {
        const auto &children = ctx->children;
        auto *argument_list =
            ccl::as<FscParser::Function_typed_arguments_listContext *>(children[1]);
        auto result = ccl::Pair<ccl::SmallVector<Argument>, ccl::SmallVector<ast::NodePtr>>{};
        auto &[arguments, nodes] = result;

        if (argument_list != nullptr) {
            for (auto *parameter : argument_list->children | std::views::filter(CommaFilter)) {
                auto [argument, node] = constructFunctionArgument(
                    ccl::as<FscParser::Function_argumentContext *>(parameter));
                arguments.push_back(argument);
                nodes.push_back(std::move(node));
            }
        }

        return result;
    }

    auto Visitor::constructFunctionArgument(FscParser::Function_argumentContext *argument_context)
        -> ccl::Pair<Argument, ast::NodePtr>
    {
        const auto &children = argument_context->children;
        auto argument_node = visitAsNode(children.back());
        auto argument_type = argument_node->getValueType();
        return {{children.front()->getText(), argument_type, {}}, argument_node};
    }
}// namespace fsc