#ifndef FSC_BASIC_NODE_HPP
#define FSC_BASIC_NODE_HPP

#include "codegen.hpp"
#include <ccl/ccl.hpp>

namespace fsc {
    using TypeId = size_t;
}

namespace fsc::ast {
    CCL_ENUM(NodeType, size_t, NONE, ROOT, VALUE, VARIABLE, RETURN, FUNCTION, FUNCTION_CALL, BODY,
             BINARY_OPERATOR, PROGRAM, CONVERSION, VARIABLE_DEFINITION, CLASS);

    class Node {
        NodeType nodeType;

    protected:
        static auto getPrintingPrefix(const std::string &prefix, const bool is_left) -> std::string;
        static auto expandPrefix(const std::string &prefix, const bool is_left,
                                 const size_t extra_expansion = 0) -> std::string;

    public:
        explicit Node(const NodeType node_type) : nodeType{node_type}
        {}

        Node(const Node &node) = default;
        Node(Node &&) noexcept = default;

        virtual ~Node() = default;

        auto operator=(const Node &node) -> Node & = default;
        auto operator=(Node &&) noexcept -> Node & = default;

        virtual auto print(const std::string &prefix = "", const bool is_left = false) const
                -> void = 0;

        virtual auto codeGen(gen::CodeGenerator &output) const -> void = 0;

        [[nodiscard]] virtual auto getValueType() const noexcept -> TypeId
        {
            throw std::runtime_error("getValueType() is not implemented");
        }

        [[nodiscard]] auto getNodeType() const noexcept -> NodeType
        {
            return nodeType;
        }

        [[nodiscard]] auto is(const NodeType type) const noexcept -> bool
        {
            return nodeType == type;
        }

        template<std::derived_from<Node> T>
        [[nodiscard]] auto as() noexcept -> T &
        {
            if (T::classof() != getNodeType()) {
                throw std::invalid_argument("Unable to convert AstNode");
            }

            return static_cast<T &>(*this);
        };

        template<std::derived_from<Node> T>
        [[nodiscard]] auto as() const noexcept -> const T &
        {
            if (T::classof() != getNodeType()) {
                throw std::invalid_argument("Unable to convert AstNode");
            }

            return static_cast<const T &>(*this);
        };

        [[nodiscard]] constexpr static auto classof() noexcept -> NodeType
        {
            return NodeType::NONE;
        }
    };

    using NodePtr = ccl::SharedPtr<Node>;
}// namespace fsc::ast

#endif /* FSC_BASIC_NODE_HPP */
