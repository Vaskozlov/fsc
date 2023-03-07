#ifndef FSC_FUNCTION_CALL_HPP
#define FSC_FUNCTION_CALL_HPP

#include "ast/function/function.hpp"
#include <ccl/ccl.hpp>

namespace fsc::ast
{
    class FunctionCall : public NodeWrapper<NodeType::FUNCTION_CALL, SemicolonNeed::NEED>
    {
        ccl::SmallVector<NodePtr> arguments;
        ccl::SmallVector<FscType> functionCallTemplates;
        std::string functionName;
        ccl::SmallVector<Argument> typedArguments;
        FscType classId;
        FscType returnedType{Void};

    public:
        FunctionCall(
            std::string function_name, const ccl::SmallVector<Argument> &typed_arguments,
            FscType class_id, const ccl::SmallVector<NodePtr> &function_arguments,
            const ccl::SmallVector<FscType> &templates, BasicContextPtr node_context);

        auto analyze() -> AnalysisReport override;

        auto print(const std::string &prefix, bool is_left) const -> void override;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void override;

        auto optimize(OptimizationLevel level) -> void override;

        [[nodiscard]] auto getValueType() -> FscType override;

        [[nodiscard]] auto getFunctionName() const noexcept -> const std::string &
        {
            return functionName;
        }

    protected:
        auto attemptToAnalyze() -> AnalysisReport;

        auto generateIndexOperator(ccl::codegen::BasicCodeGenerator &output) -> void;
        [[nodiscard]] auto getFunction() const -> ccl::SharedPtr<Function>;

        auto generateFunctionName(ccl::codegen::BasicCodeGenerator &output) -> void;

    private:
        [[nodiscard]] auto argumentToString() const -> std::string;
    };
}// namespace fsc::ast

#endif /* FSC_FUNCTION_CALL_HPP */
