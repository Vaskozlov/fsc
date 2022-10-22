#ifndef FSC_FUNCTION_NODE_HPP
#define FSC_FUNCTION_NODE_HPP

#include "function.hpp"

namespace fsc {
    class FunctionCall : public AstNode {
    public:
        explicit FunctionCall(const Function &function_,
                              const std::initializer_list<std::shared_ptr<AstNode>> &arguments_)
            : AstNode(classof()), function(function_), arguments(arguments_)
        {}

        explicit FunctionCall(const Function &function_,
                              const std::vector<std::shared_ptr<AstNode>> &arguments_)
            : AstNode(classof()), function(function_), arguments(arguments_)
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] auto getValue() -> FscValue final;
        [[nodiscard]] auto getValueType() const -> size_t final
        {
            return function.getReturnType();
        }

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::FUNCTION_CALL;
        }

    private:
        Function function;
        std::vector<std::shared_ptr<AstNode>> arguments;
    };
}// namespace fsc

#endif /* FSC_FUNCTION_NODE_HPP */
