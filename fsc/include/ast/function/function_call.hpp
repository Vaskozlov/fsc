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
            std::string function_name,
            const ccl::SmallVector<Argument> &typed_arguments,
            FscType class_id,
            const ccl::SmallVector<NodePtr> &function_arguments,
            const ccl::SmallVector<FscType> &templates, BasicContextPtr node_context);

        auto analyze() -> AnalysisReport;

        auto print(const std::string &prefix, bool is_left) const -> void override;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void override;

        [[nodiscard]] auto getValueType() -> FscType final;

    protected:
        auto attemptToAnalyze() -> AnalysisReport;

        auto defaultPrint(const std::string &prefix, bool is_left) const -> void;
        auto defaultCodegen(ccl::codegen::BasicCodeGenerator &output) -> void;
        auto getFunction() const -> ccl::SharedPtr<Function>;

        auto generateFunctionName(ccl::codegen::BasicCodeGenerator &output) -> void;
    };
}// namespace fsc::ast

#endif /* FSC_FUNCTION_CALL_HPP */
