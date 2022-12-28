#include "ast/function/function.hpp"
#include "stack/stack.hpp"
#include "visitor.hpp"

namespace fsc
{
    auto Visitor::constructFunction(FscParser::FunctionContext *ctx) -> ast::NodePtr
    {
        auto function = ccl::makeShared<ast::Function>();
        function->finishConstruction(ctx, *this, ProgramStack.getCurrentClassScope());
        return function;
    }
}// namespace fsc
