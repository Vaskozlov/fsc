#ifndef FSC_FUNCTION_CALL_HPP
#define FSC_FUNCTION_CALL_HPP

#include "ast/function.hpp"
#include <ccl/core/types.hpp>

namespace fsc::ast
{
    class FunctionCall : public NodeWrapper<NodeType::FUNCTION_CALL, SemicolonNeed::NEED>
    {
        ccl::SmallVector<NodePtr> arguments;
        ccl::SharedPtr<Function> function;

    public:
        FunctionCall(
            ccl::SharedPtr<Function>
                function_to_call,
            const ccl::SmallVector<NodePtr> &function_arguments);

        auto print(const std::string &prefix, bool is_left) const -> void override;

        auto codeGen(gen::CodeGenerator &output) const -> void override;

        [[nodiscard]] auto getValueType() const -> ccl::Id final;

    protected:
        auto defaultFunctionCallPrint(const std::string &prefix, bool is_left) const -> void;
        auto defaultFunctionCallCodeGen(gen::CodeGenerator &output) const -> void;
    };
}// namespace fsc::ast

#endif /* FSC_FUNCTION_CALL_HPP */
