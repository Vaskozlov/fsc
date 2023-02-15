#include "visitor.hpp"
#include <type/antlr-types.hpp>

namespace fsc
{
    auto Visitor::constructProgram(ProgramContext *ctx) -> void
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
