#include "ast/method_call.hpp"
#include <ast/basic_node.hpp>
#include <ast/function_call.hpp>
#include <cmath>
#include <type/type.hpp>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    MethodCall::MethodCall(
        NodePtr expression_for_call, ccl::SharedPtr<Function> function_to_call,
        const ccl::SmallVector<NodePtr> &function_arguments)
      : NodeWrapper{std::move(function_to_call), function_arguments}
      , expression{std::move(expression_for_call)}
    {}

    auto MethodCall::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print(
            "{}Method call {}\n", getPrintingPrefix(prefix, is_left),
            FscType::getTypeName(expression->getValueType()));
        defaultFunctionCallPrint(expandPrefix(prefix, false), false);
    }

    auto MethodCall::codeGen(gen::CodeGenerator &output) const -> void
    {
        output << '(' << *expression << ")."sv;
        defaultFunctionCallCodeGen(output);
    }
};// namespace fsc::ast
