#ifndef FSC_RETURN_HPP
#define FSC_RETURN_HPP

#include "ast/basic_node.hpp"

namespace fsc::ast {
    class Return : public Node {
        ccl::SharedPtr<Node> value;

    public:
        explicit Return(ccl::SharedPtr<Node> value_) : Node(classof()), value(std::move(value_))
        {}

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] auto getValueType() const noexcept -> TypeId final
        {
            return value->getValueType();
        }

        [[nodiscard]] constexpr static auto classof() noexcept -> NodeType
        {
            return NodeType::RETURN;
        }
    };
}// namespace fsc::ast

#endif /* FSC_RETURN_HPP */
