#include "ast/program.hpp"
#include "visitor.hpp"

namespace fsc
{
    auto Visitor::constructProgram(FscParser::ProgramContext *ctx) -> void
    {
        const auto &children = ctx->children;

        for (auto *child : children) {
            auto result = visit(child);

            if (result.type() == typeid(ast::NodePtr)) {
                program.addNode(castToNode(result));
            }
        }
    }
}// namespace fsc
