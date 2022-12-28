#include "ast/function/function.hpp"
#include "function/functions_holder.hpp"
#include "stack/stack.hpp"
#include "visitor.hpp"

namespace fsc
{
    auto Visitor::constructFunction(FscParser::FunctionContext *ctx) -> ast::NodePtr
    {
        auto function =
            ccl::makeShared<ast::Function>(ctx, *this, ProgramStack.getCurrentClassScope());
        func::Functions.registerFunction(function);
        return function;
    }
}// namespace fsc
