#include "ast/function/method_call.hpp"
#include "ast/function/function_call.hpp"
#include "type/type.hpp"
#include <cmath>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    MethodCall::MethodCall(
        NodePtr expression_for_call, ccl::WeakPtr<Function> function_to_call,
        const ccl::SmallVector<NodePtr> &function_arguments)
      : NodeWrapper{std::move(function_to_call), function_arguments}
      , expression{std::move(expression_for_call)}
    {}

    auto MethodCall::analyze() const -> void
    {
        expression->analyze();
    }

    auto MethodCall::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print(
            "{}Method call {}\n", getPrintingPrefix(prefix, is_left),
            FscType::getTypeName(expression->getValueType()));
        defaultFunctionCallPrint(expandPrefix(prefix, false), false);
    }

    auto MethodCall::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        output << *expression << '.';
        defaultFunctionCallCodeGen(output);
    }
};// namespace fsc::ast
