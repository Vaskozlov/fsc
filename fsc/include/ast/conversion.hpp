#ifndef FSC_CONVERSION_HPP
#define FSC_CONVERSION_HPP

#include "ast/basic_node.hpp"

namespace fsc::ast {
    class Conversion : public Node {
        std::shared_ptr<Node> value;
        TypeId typeId;

    public:
        explicit Conversion(std::shared_ptr<Node> value_, TypeId type_)
            : Node(classof()), value(std::move(value_)), typeId(type_)
        {}

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] auto getValueType() const noexcept -> TypeId final
        {
            return value->getValueType();
        }

        [[nodiscard]] static auto classof() noexcept -> NodeType
        {
            return NodeType::CONVERSION;
        }
    };
}// namespace fsc::ast

#endif /* FSC_CONVERSION_HPP */