#ifndef FSC_METHOD_CALL_HPP
#define FSC_METHOD_CALL_HPP

#include "ast/basic_node.hpp"
#include "ast/function/function_call.hpp"
#include <ccl/ccl.hpp>

namespace fsc::ast
{
    class MethodCall final
      : public NodeWrapper<NodeType::METHOD_CALL, SemicolonNeed::NEED, FunctionCall>
    {
    private:
        NodePtr expression;

    public:
        MethodCall(
            NodePtr expression_for_call, std::string function_name,
            const ccl::Vector<Argument> &typed_arguments, FscType class_id,
            const ccl::Vector<NodePtr> &function_arguments, const ccl::Vector<FscType> &templates,
            BasicContextPtr node_context);

        auto analyze() -> AnalysisReport final;

        [[nodiscard]] auto getValueType() -> FscType final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto optimize(OptimizationLevel level) -> void final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_METHOD_CALL_HPP */
