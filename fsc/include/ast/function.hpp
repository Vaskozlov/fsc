#ifndef FSC_AST_FUNCTION_HPP
#define FSC_AST_FUNCTION_HPP

#include "ast/basic_node.hpp"
#include "function/function.hpp"
#include <ranges>

namespace fsc::ast {
    class Function : public Node {
        func::Function function;

    public:
        explicit Function(const func::Function &function_) : Node(classof()), function(function_)
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        [[nodiscard]] static auto classof() noexcept -> NodeType
        {
            return NodeType::FUNCTION;
        }

    private:
        auto genArguments(gen::CodeGenerator &output) const -> void;
        auto argumentToString(gen::CodeGenerator &output, const func::Argument &arg) const -> void;
    };
}// namespace fsc::ast

#endif /* FSC_AST_FUNCTION_HPP */
