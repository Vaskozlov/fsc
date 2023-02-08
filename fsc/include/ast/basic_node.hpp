#ifndef FSC_BASIC_NODE_HPP
#define FSC_BASIC_NODE_HPP

#include "type/antlr-types.hpp"
#include <ccl/ccl.hpp>
#include <ccl/codegen/basic_codegen.hpp>
#include <concepts>
#include <optional>
#include <ParserRuleContext.h>
#include <stdexcept>
#include <typeinfo>

namespace fsc
{
    class FscType;
    class FscTypeInterface;
}// namespace fsc

namespace fsc::ast
{
    extern std::string SourceFile;              // NOLINT
    extern ccl::Vector<std::string> SourceLines;// NOLINT

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
        CONSTRUCTOR,
        BODY,
        BINARY_OPERATOR,
        PROGRAM,
        CONVERSION,
        VARIABLE_DEFINITION,
        CLASS,
        MEMBER_VARIABLE,
        IF,
        IF_STMT,
        WHILE,
        PARENTHESIZED,
    };

    enum struct OptimizationLevel : ccl::Id
    {
        NONE,
        FAST
    };

    template<NodeType TypeOfNode, SemicolonNeed NeedSemicolon, typename Base>
    class NodeWrapper;

    class Node
    {
    private:
        template<NodeType TypeOfNode, SemicolonNeed NeedSemicolon, typename Base>
        friend class NodeWrapper;

        antlr4::Token *start{nullptr};
        antlr4::Token *stop{nullptr};
        NodeType nodeType;
        SemicolonNeed needSemicolon{SemicolonNeed::NEED};

        auto setNodeType(NodeType node_type) noexcept -> void;
        auto setSemicolonNeed(SemicolonNeed need_semicolon) noexcept -> void;

    protected:
        static auto getPrintingPrefix(const std::string &prefix, bool is_left) -> std::string;
        static auto
            expandPrefix(const std::string &prefix, bool is_left, size_t extra_expansion = 0)
                -> std::string;

    public:
        explicit Node(NodeType node_type, SemicolonNeed need_semicolon) noexcept;

        Node(const Node &node) = default;
        Node(Node &&) noexcept = default;

        virtual ~Node() = default;

        auto operator=(const Node &node) -> Node & = default;
        auto operator=(Node &&) noexcept -> Node & = default;

        virtual auto print(const std::string &prefix = "", bool is_left = false) const -> void = 0;

        virtual auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void = 0;

        virtual auto analyze() const -> void = 0;

        virtual auto optimize(OptimizationLevel /* unused */) -> void
        {}

        auto setStart(antlr4::Token *rule_start) noexcept -> void
        {
            start = rule_start;
        }

        auto setStop(antlr4::Token *rule_stop) noexcept -> void
        {
            stop = rule_stop;
        }

        [[nodiscard]] auto getStart() const noexcept -> ccl::Optional<antlr4::Token *>
        {
            if (start == nullptr) {
                return std::nullopt;
            }

            return start;
        }

        [[nodiscard]] auto getStop() const noexcept -> ccl::Optional<antlr4::Token *>
        {
            if (stop == nullptr) {
                return std::nullopt;
            }

            return stop;
        }

        auto reportAboutError(const std::exception &exception) const -> void;

        [[nodiscard]] virtual auto getValueType() const noexcept(false) -> FscType;

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

    auto operator<<(ccl::codegen::BasicCodeGenerator &generator, const Node &node)
        -> ccl::codegen::BasicCodeGenerator &;
}// namespace fsc::ast

#endif /* FSC_BASIC_NODE_HPP */
