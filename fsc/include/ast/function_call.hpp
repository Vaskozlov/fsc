#ifndef FSC_FUNCTION_CALL_HPP
#define FSC_FUNCTION_CALL_HPP

#include "ast/basic_node.hpp"
#include "function/function.hpp"

namespace fsc::ast {
    class FunctionCall : public Node {
        ccl::SmallVector<ccl::SharedPtr<Node>, 4> arguments;
        func::Function function;

    public:
        FunctionCall(const func::Function &function_,
                     const ccl::SmallVector<ccl::SharedPtr<Node>, 4> &arguments_)
            : Node(classof()), arguments(arguments_), function(function_)
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        [[nodiscard]] constexpr static auto classof() noexcept -> NodeType
        {
            return NodeType::FUNCTION_CALL;
        }
    };
}// namespace fsc::ast

#endif /* FSC_FUNCTION_CALL_HPP */
