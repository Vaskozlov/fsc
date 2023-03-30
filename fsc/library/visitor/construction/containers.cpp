#include "ast/container/class.hpp"
#include "filter.hpp"
#include "stack/stack.hpp"
#include "type/type.hpp"
#include <range/v3/view.hpp>
#include <type/antlr-types.hpp>

namespace fsc
{
    using namespace ccl;

    auto Visitor::constructBody(BodyContext *ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;
        auto body = makeShared<ast::Body>();

        const auto stack_scope = ProgramStack.acquireStackScope(ScopeType::SOFT);
        const auto modifiers =
            ranges::views::drop(1) | ranges::views::drop_last(1) | filter::newline;

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

        auto constructed_class = makeShared<ast::Class>(std::move(name));
        TypeManager::addFscClass(constructed_class);

        constructed_class->finishClass(body_context, templates);

        return constructed_class;
    }
}// namespace fsc
