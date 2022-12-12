#ifndef FSC_FUNCTION_CALL_HPP
#define FSC_FUNCTION_CALL_HPP

#include "ast/function.hpp"
#include <ast/basic_node.hpp>
#include <ccl/core/types.hpp>

namespace fsc::ast
{
    class FunctionCall : public NodeWrapper<NodeType::FUNCTION_CALL>
    {
        ccl::SmallVector<NodePtr> arguments;
        ccl::SharedPtr<Function> function;

    public:
        FunctionCall(
            ccl::SharedPtr<Function>
                function_to_call,
            const ccl::SmallVector<NodePtr> &function_arguments);

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        [[nodiscard]] auto getValueType() const noexcept -> ccl::Id final
        {
            return function->getReturnType();
        }
    };
}// namespace fsc::ast

#endif /* FSC_FUNCTION_CALL_HPP */
