#ifndef FSC_BODY_HPP
#define FSC_BODY_HPP

#include "ast/basic_node.hpp"

namespace fsc::ast {
    class Body : public Node {
        using iterator = std::vector<std::shared_ptr<Node>>::iterator;
        using const_iterator = std::vector<std::shared_ptr<Node>>::const_iterator;

        std::vector<std::shared_ptr<Node>> nodes;

    public:
        Body() : Node(classof())
        {}

        explicit Body(const NodeType type_) : Node(type_)
        {}

        [[nodiscard]] auto begin() const -> const_iterator
        {
            return nodes.begin();
        }

        [[nodiscard]] auto end() const -> const_iterator
        {
            return nodes.end();
        }

        auto codeGen(gen::CodeGenerator &output) const -> void override;

        auto print(const std::string &prefix, const bool is_left) const -> void override;

        [[nodiscard]] auto getValueType() const noexcept -> TypeId;

        virtual auto addNode(std::shared_ptr<Node> node) -> void;

        [[nodiscard]] static auto classof() noexcept -> NodeType
        {
            return NodeType::BODY;
        }

    protected:
        auto emplaceNode(std::shared_ptr<Node> node) -> void
        {
            nodes.emplace_back(std::move(node));
        }

        auto defaultBodyCodegen(gen::CodeGenerator &output) const -> void;
        auto defaultBodyPrint(const std::string &prefix, const bool is_left) const -> void;
    };
}// namespace fsc::ast

#endif /* FSC_BODY_HPP */
