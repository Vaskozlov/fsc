#include "ast/function/method_call.hpp"
#include "ast/function/function_call.hpp"
#include "type/type.hpp"

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

    auto MethodCall::analyze() -> AnalysisReport
    {
        auto expression_analysis = expression->analyze();
        expression_analysis.merge(FunctionCall::analyze());
        return expression_analysis;
    }

    auto MethodCall::getValueType() -> FscType
    {
        return TypeManager::getInstantiatedTemplate(
            expression->getValueType(), FunctionCall::getValueType());
    }

    auto MethodCall::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print(
            "{}Method call {}\n", getPrintingPrefix(prefix, is_left),
            expression->getValueType().getName());
        FunctionCall::defaultPrint(expandPrefix(prefix, is_left), false);
    }

    auto MethodCall::optimize(OptimizationLevel level) -> void
    {
        expression->optimize(level);
        FunctionCall::optimize(level);
    }

    auto MethodCall::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        auto function = getFunction();

        if (function->getName() == "__at__") {
            output << *expression << '[';
            FunctionCall::generateIndexOperator(output);
        } else {
            output << *expression << '.';
            FunctionCall::defaultCodegen(output);
        }
    }
};// namespace fsc::ast
