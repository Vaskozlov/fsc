#include "ast/container/class.hpp"
#include "stack/stack.hpp"
#include <type/antlr-types.hpp>
#include <type/type.hpp>

namespace fsc
{
    using namespace ccl;
    namespace sv = std::views;

    template auto Visitor::constructBody<ast::Body>(BodyContext *ctx) -> ast::NodePtr;

    static constexpr auto NewLineFilter(antlr4::tree::ParseTree *elem) -> bool
    {
        const auto text = elem->getText();
        return !text.empty() && text[0] != '\n';
    };

    template<std::derived_from<ast::Body> BodyT, typename... Ts>
    auto Visitor::constructBody(BodyContext *ctx, Ts &&...args) -> ast::NodePtr
    {
        const auto &children = ctx->children;
        auto body = makeShared<BodyT>(std::forward<Ts>(args)...);
        auto id_for_class_scope = FscType{Void};

        if constexpr (BodyT::classof() == ast::NodeType::CLASS) {
            id_for_class_scope = FscType{body->getName()};
        }

        auto class_scope = ProgramStack.acquireClassScope(id_for_class_scope);
        auto stack_scope = ProgramStack.acquireStackScope(ScopeType::SOFT);
        auto modifiers =
            sv::drop(1) | views::dropBack(ctx->children, 2) | sv::filter(NewLineFilter);

        for (auto *child : children | modifiers) {
            body->addNode(visitAsNode(child));
        }

        return body;
    }

    auto Visitor::constructClass(ClassContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;
        const auto name = children.at(1)->getText();

        auto scope = ProgramStack.acquireStackScope(ScopeType::HARD);
        auto *body_context = as<BodyContext *>(children.back());

        return constructBody<ast::Class>(body_context, name);
    }
}// namespace fsc
