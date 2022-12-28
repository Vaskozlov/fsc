#include "ast/function/function.hpp"
#include "function/functions_holder.hpp"
#include "stack/stack.hpp"
#include "visitor.hpp"
#include <function/argument.hpp>

namespace fsc
{
    auto Visitor::constructFunction(FscParser::FunctionContext *ctx) -> ast::NodePtr
    {
        auto function = ast::Function{ctx, *this, ProgramStack.getCurrentClassScope()};
        return func::Functions.get(
            Signature{function.getName(), function.getArguments(), function.getClassId()});
    }
}// namespace fsc
