#include "ast/binary_operator.hpp"
#include "ast/class.hpp"
#include "ast/conversion.hpp"
#include "ast/return.hpp"
#include "ast/variable_definition.hpp"
#include "stack/stack.hpp"
#include "visitor.hpp"

using namespace std::literals;

namespace fsc {
    template<typename BodyT, typename... Ts>
    auto Visitor::constructBody(FscParser::BodyContext *ctx, Ts &&...args) -> ast::NodePtr
    {
        static_assert(std::derived_from<BodyT, ast::Body>);
        static constexpr auto new_line = [](auto *elem) {
            return elem->getText() != "\n";
        };

        const auto &children = ctx->children;
        auto body = ccl::makeShared<BodyT>(std::forward<Ts>(args)...);

        if constexpr (BodyT::classof() == ast::NodeType::CLASS) {
            ProgramStack.pushClassScope(FscType::getTypeId(body->getName()));
        }

        ProgramStack.pushScope(ScopeType::SOFT);

        for (auto *child : children | std::views::drop(1) | ccl::views::dropBack(ctx->children, 2) |
                                   std::views::filter(new_line)) {
            body->addNode(visitNode(child));
        }

        ProgramStack.popScope();

        if constexpr (BodyT::classof() == ast::NodeType::CLASS) {
            ProgramStack.popClassScope();
        }

        return body;
    }

    template auto Visitor::constructBody<ast::Body>(FscParser::BodyContext *ctx) -> ast::NodePtr;

    auto Visitor::constructVariableDefinition(FscParser::Variable_definitionContext *ctx)
            -> ast::NodePtr
    {
        auto flags = ast::VariableFlags{};
        const auto &children = ctx->children;
        const auto name = children[1]->getText();
        const auto type = children[3]->getText();
        const auto converted_type = FscType::getTypeId(type);
        const auto *expr = dynamic_cast<const FscParser::ExprContext *>(children.back());

        if (expr != nullptr) {
            return ccl::makeShared<ast::VariableDefinition>(flags, name, converted_type,
                                                            visitNode(children.back()));
        }

        return ccl::makeShared<ast::VariableDefinition>(flags, name, converted_type);
    }

    auto Visitor::constructAutoVariableDefinition(FscParser::Auto_variable_definitionContext *ctx)
            -> ast::NodePtr
    {
        auto flags = ast::VariableFlags{};
        const auto &children = ctx->children;
        const auto name = children[1]->getText();
        return ccl::makeShared<ast::VariableDefinition>(flags, name, visitNode(children.back()));
    }

    auto Visitor::processFunctionArguments(FscParser::Function_parameterContext *ctx)
            -> ccl::Pair<ccl::SmallVector<Argument>, ccl::SmallVector<ast::NodePtr>>
    {
        static constexpr auto comma_filter = [](auto *elem) {
            return elem->getText() != ",";
        };

        const auto &children = ctx->children;
        auto *argument_list =
                dynamic_cast<FscParser::Function_typed_arguments_listContext *>(children[1]);
        auto result = ccl::Pair<ccl::SmallVector<Argument>, ccl::SmallVector<ast::NodePtr>>{};
        auto &[arguments, nodes] = result;

        if (argument_list != nullptr) {
            for (auto *parameter : argument_list->children | std::views::filter(comma_filter)) {
                auto [argument, node] = constructFunctionArgument(
                        dynamic_cast<FscParser::Function_argumentContext *>(parameter));
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
        auto argument_node = visitNode(children.back());
        auto argument_type = argument_node->getValueType();
        return {{children.front()->getText(), argument_type, {}}, argument_node};
    }

    auto Visitor::constructClass(FscParser::ClassContext *const ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;
        const auto name = children[1]->getText();
        return constructBody<ast::Class>(dynamic_cast<FscParser::BodyContext *>(children.back()),
                                         name);
    }

    auto Visitor::constructConversion(FscParser::ExprContext *ctx) -> ast::NodePtr
    {
        auto expr_to_convert = visitNode(ctx->children[0]);
        auto target_type = ctx->children[2]->getText();
        return ccl::makeShared<ast::Conversion>(std::move(expr_to_convert),
                                                FscType::getTypeId(target_type));
    }

    auto Visitor::constructReturn(FscParser::StmtContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;

        return ccl::makeShared<ast::Return>(visitNode(children[1]));
    }

    auto Visitor::constructBinaryExpression(FscParser::ExprContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;

        auto lhs = visitNode(children[0]);
        auto rhs = visitNode(children[2]);

        return ccl::makeShared<ast::BinaryOperation>(children[1]->getText(), std::move(lhs),
                                                     std::move(rhs));
    }
}// namespace fsc
