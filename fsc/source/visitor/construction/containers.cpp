#include "ast/container/class.hpp"
#include "stack/stack.hpp"
#include <type/antlr-types.hpp>
#include <type/type.hpp>

namespace fsc
{
    using namespace ccl;
    namespace sv = std::views;

    static constexpr auto NewLineFilter(antlr4::tree::ParseTree *elem) -> bool
    {
        const auto text = elem->getText();
        return !text.empty() && text[0] != '\n';
    }

    auto Visitor::constructBody(BodyContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;
        auto body = makeShared<ast::Body>();

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
        auto name = children.at(1)->getText();
        auto *templates = ccl::as<TemplateContext *>(children.at(2));

        auto scope = ProgramStack.acquireStackScope(ScopeType::HARD);
        auto *body_context = as<BodyContext *>(children.back());

        auto constructed_class =
            makeShared<ast::Class>(std::move(name), *this, body_context, templates);
        FscType::registerFscClass(constructed_class);

        return constructed_class;
    }
}// namespace fsc
