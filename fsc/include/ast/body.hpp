#ifndef FSC_BODY_HPP
#define FSC_BODY_HPP

#include "ast/basic_node.hpp"

namespace fsc::ast
{
    class Body : public NodeWrapper<NodeType::BODY, SemicolonNeed::DO_NOT_NEED>
    {
        using iterator = ccl::Vector<NodePtr>::iterator;
        using const_iterator = ccl::Vector<NodePtr>::const_iterator;

        ccl::Vector<NodePtr> nodes;

    public:
        Body();

        [[nodiscard]] auto begin() const -> const_iterator
        {
            return nodes.begin();
        }

        [[nodiscard]] auto end() const -> const_iterator
        {
            return nodes.end();
        }

        auto codeGen(gen::CodeGenerator &output) const -> void override;

        auto print(const std::string &prefix, bool is_left) const -> void override;

        [[nodiscard]] auto getValueType() const -> ccl::Id final;

        virtual auto addNode(NodePtr node) -> void;

    protected:
        auto emplaceNode(NodePtr node) -> void
        {
            nodes.emplace_back(std::move(node));
        }

        auto defaultBodyCodegen(gen::CodeGenerator &output) const -> void;
        auto defaultBodyPrint(const std::string &prefix, bool is_left) const -> void;
    };
}// namespace fsc::ast

#endif /* FSC_BODY_HPP */
