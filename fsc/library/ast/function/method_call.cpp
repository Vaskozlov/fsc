#include "ast/function/method_call.hpp"
#include "ast/function/function_call.hpp"
#include "type/type.hpp"
#include <cmath>

namespace fsc::ast
{
    using namespace ccl;
    using namespace std::string_view_literals;

    MethodCall::MethodCall(
        NodePtr expression_for_call, std::string function_name,
        const ccl::SmallVector<Argument> &typed_arguments, FscType class_id,
        const SmallVector<NodePtr> &function_arguments, const ccl::SmallVector<FscType> &templates,
        BasicContextPtr node_context)
      : NodeWrapper{std::move(function_name), typed_arguments, class_id,
                    function_arguments,       templates,       node_context}
      , expression{std::move(expression_for_call)}
    {}

    auto MethodCall::analyze() -> void
    {
        expression->analyze();
        FunctionCall::analyze();
    }

    auto MethodCall::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print(
            "{}Method call {}\n", getPrintingPrefix(prefix, is_left),
            expression->getValueType().getName());
        FunctionCall::defaultPrint(expandPrefix(prefix, false), false);
    }

    auto MethodCall::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        output << *expression << '.';
        FunctionCall::defaultCodegen(output);
    }
};// namespace fsc::ast
