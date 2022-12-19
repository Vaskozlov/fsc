#ifndef FSC_METHOD_CALL_HPP
#define FSC_METHOD_CALL_HPP

#include "ast/basic_node.hpp"
#include "ccl/core/types.hpp"
#include "function_call.hpp"

namespace fsc::ast
{
    class MethodCall final : public NodeWrapper<NodeType::METHOD_CALL, SemicolonNeed::NEED, FunctionCall>
    {
    private:
        NodePtr expression;

    public:
        MethodCall(
            NodePtr expression_for_call, ccl::SharedPtr<Function> function_to_call,
            const ccl::SmallVector<NodePtr> &function_arguments);

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_METHOD_CALL_HPP */
