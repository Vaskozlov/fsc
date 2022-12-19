#ifndef FSC_BASIC_NODE_HPP
#define FSC_BASIC_NODE_HPP

#include "codegen.hpp"
#include <ccl/ccl.hpp>
#include <concepts>
#include <stdexcept>
#include <typeinfo>

namespace fsc::ast
{
    enum struct SemicolonNeed : bool
    {
        NEED,
        DO_NOT_NEED
    };

    enum struct NodeType : ccl::Id
    {
        NONE,
        VALUE,
        VARIABLE,
        RETURN,
        FUNCTION,
        METHOD_CALL,
        FUNCTION_CALL,
        BODY,
        BINARY_OPERATOR,
        PROGRAM,
        CONVERSION,
        VARIABLE_DEFINITION,
        CLASS,
        MEMBER_VARIABLE,
        IF,
        IF_STMT,
        PARENTHESIZED,
    };

    template<NodeType TypeOfNode, SemicolonNeed NeedSemicolon, typename Base>
    class NodeWrapper;

    class Node
    {
    private:
        template<NodeType TypeOfNode, SemicolonNeed NeedSemicolon, typename Base>
        friend class NodeWrapper;

        NodeType nodeType;
        SemicolonNeed needSemicolon{SemicolonNeed::NEED};

    private:
        auto setNodeType(NodeType node_type) noexcept -> void;
        auto setSemicolonNeed(SemicolonNeed need_semicolon) noexcept -> void;

    protected:
        static auto getPrintingPrefix(const std::string &prefix, bool is_left) -> std::string;
        static auto
            expandPrefix(const std::string &prefix, bool is_left, const size_t extra_expansion = 0)
                -> std::string;

    public:
        explicit Node(NodeType node_type, SemicolonNeed need_semicolon) noexcept;

        Node(const Node &node) = default;
        Node(Node &&) noexcept = default;

        virtual ~Node() = default;

        auto operator=(const Node &node) -> Node & = default;
        auto operator=(Node &&) noexcept -> Node & = default;

        virtual auto print(const std::string &prefix = "", bool is_left = false) const -> void = 0;

        virtual auto codeGen(gen::CodeGenerator &output) const -> void = 0;

        [[nodiscard]] virtual auto getValueType() const noexcept(false) -> ccl::Id;

        [[nodiscard]] auto getNodeType() const noexcept -> NodeType
        {
            return nodeType;
        }

        [[nodiscard]] auto semicolonRequired() const noexcept -> SemicolonNeed
        {
            return needSemicolon;
        }

        [[nodiscard]] auto is(const NodeType type) const noexcept -> bool
        {
            return nodeType == type;
        }

        template<std::derived_from<Node> T>
        [[nodiscard]] auto as() noexcept(false) -> T &
        {
            if (T::classof() != getNodeType()) {
                throw std::bad_cast{};
            }

            return static_cast<T &>(*this);
        };

        template<std::derived_from<Node> T>
        [[nodiscard]] auto as() const noexcept(false) -> const T &
        {
            if (T::classof() != getNodeType()) {
                throw std::bad_cast{};
            }

            return static_cast<const T &>(*this);
        };

        CCL_DECL static auto classof() noexcept -> NodeType
        {
            return NodeType::NONE;
        }
    };

    template<NodeType TypeOfNode, SemicolonNeed NeedSemicolon, typename Base = Node>
    class NodeWrapper : public Base
    {
    private:
        static_assert(std::derived_from<Base, Node>);

    public:
        NodeWrapper() noexcept(std::is_nothrow_constructible_v<Base, NodeType>)
            requires(std::is_same_v<Base, Node>)
          : Base{classof(), NeedSemicolon}
        {}

        NodeWrapper() noexcept(std::is_nothrow_constructible_v<Base>)
            requires(!std::is_same_v<Base, Node>)
        {
            this->setNodeType(classof());
            this->setSemicolonNeed(NeedSemicolon);
        }

        template<typename... Ts>
        explicit NodeWrapper(Ts &&...args) noexcept(std::is_nothrow_constructible_v<Base, Ts...>)
          : Base{std::forward<Ts>(args)...}
        {
            this->setNodeType(classof());
            this->setSemicolonNeed(NeedSemicolon);
        }

        CCL_DECL static auto classof() noexcept -> NodeType
        {
            return TypeOfNode;
        }
    };

    using NodePtr = ccl::SharedPtr<Node>;
}// namespace fsc::ast

#endif /* FSC_BASIC_NODE_HPP */
