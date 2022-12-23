#include "ast/container/class.hpp"
#include "stack/stack.hpp"

namespace fsc
{
    template auto Visitor::constructBody<ast::Body>(FscParser::BodyContext *ctx) -> ast::NodePtr;

    static constexpr auto NewLineFilter(antlr4::tree::ParseTree *elem) -> bool
    {
        const auto text = elem->getText();
        return !text.empty() && text[0] != '\n';
    };

    template<typename BodyT, typename... Ts>
    auto Visitor::constructBody(FscParser::BodyContext *ctx, Ts &&...args) -> ast::NodePtr
    {
        static_assert(std::derived_from<BodyT, ast::Body>);

        const auto &children = ctx->children;
        auto body = ccl::makeShared<BodyT>(std::forward<Ts>(args)...);
        auto id_for_class_scope = ccl::as<size_t>(0);

        if constexpr (BodyT::classof() == ast::NodeType::CLASS) {
            id_for_class_scope = FscType::getTypeId(body->getName());
        }

        auto class_scope = ClassScope{id_for_class_scope, ProgramStack};
        auto stack_scope = StackScope{ScopeType::SOFT, ProgramStack};

        for (auto *child : children | std::views::drop(1) | ccl::views::dropBack(ctx->children, 2) |
                               std::views::filter(NewLineFilter)) {
            body->addNode(visitAsNode(child));
        }

        return body;
    }

    auto Visitor::constructClass(FscParser::ClassContext *const ctx) -> ast::NodePtr
    {
        const auto &children = ctx->children;
        const auto name = children[1]->getText();

        auto scope = StackScope{ScopeType::HARD, ProgramStack};
        auto body =
            constructBody<ast::Class>(ccl::as<FscParser::BodyContext *>(children.back()), name);

        return body;
    }
}// namespace fsc
