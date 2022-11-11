#ifndef FSC_FUNCTION_CALL_HPP
#define FSC_FUNCTION_CALL_HPP

#include "ast/function.hpp"
#include <ccl/core/types.hpp>

namespace fsc::ast {
    class FunctionCall : public Node {
        ccl::SmallVector<NodePtr> arguments;
        ccl::SharedPtr<Function> function;

    public:
        FunctionCall(ccl::SharedPtr<Function> function_,
                     const ccl::SmallVector<NodePtr> &arguments_)
            : Node{classof()}, arguments{arguments_}, function{std::move(function_)}
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
