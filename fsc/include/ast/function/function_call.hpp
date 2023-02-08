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
        ccl::WeakPtr<Function> function;

    public:
        FunctionCall(
            ccl::WeakPtr<Function>
                function_to_call,
            const ccl::SmallVector<NodePtr> &function_arguments,
            const ccl::SmallVector<FscType> &templates);

        auto analyze() const -> void;

        auto print(const std::string &prefix, bool is_left) const -> void override;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void override;

        [[nodiscard]] auto getValueType() const -> FscType final;

    protected:
        auto defaultPrint(const std::string &prefix, bool is_left) const -> void;
        auto defaultCodegen(ccl::codegen::BasicCodeGenerator &output) const -> void;
    };
}// namespace fsc::ast

#endif /* FSC_FUNCTION_CALL_HPP */
