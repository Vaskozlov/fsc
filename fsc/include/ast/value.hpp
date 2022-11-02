#ifndef FSC_VALUE_HPP
#define FSC_VALUE_HPP

#include "ast/basic_node.hpp"
#include "type/type.hpp"

namespace fsc::ast {
    class Value : public Node {
        std::shared_ptr<FscType> value;

    public:
        explicit Value(std::shared_ptr<FscType> value_) : Node(classof()), value(std::move(value_))
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        [[nodiscard]] auto getValueType() const noexcept -> TypeId final
        {
            return value->getId();
        }

        [[nodiscard]] static auto classof() noexcept -> NodeType
        {
            return NodeType::VALUE;
        }
    };
}// namespace fsc::ast

#endif /* FSC_VALUE_HPP */
