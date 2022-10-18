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

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] auto getValue() -> FscValue final
        {
            std::vector<std::pair<std::string, FscValue>> new_arguments;

            for (size_t i = 0; i != function.getArguments().size(); ++i) {
                new_arguments.emplace_back(function.getArguments()[i].name,
                                           arguments[i]->getValue());
            }

            ProgramsStack.pushScope();

            for (const auto &[name, value] : new_arguments) {
                ProgramsStack.addVariable(name, value);
            }

            auto result = function.invoke();

            ProgramsStack.popScope();
            return result;
        }

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
