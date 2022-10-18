#ifndef FSC_NODE_HPP
#define FSC_NODE_HPP

#include "builtin/types.hpp"
#include <any>
#include <memory>
#include <vector>

namespace fsc {
    enum struct AstNodeType : size_t { NONE, ROOT, VALUE, VARIABLE, FUNCTION, BINARY_EXPRESSION };
    enum struct BinaryExpressionType : size_t { ADD, SUB, MUL, DIV, MOD };

    class AstNode {
    public:
        explicit AstNode(const AstNodeType type_) : nodeType(type_)
        {}

        AstNode(const AstNode &) = default;
        AstNode(AstNode &&) noexcept = default;
        virtual ~AstNode() = default;

        auto operator=(const AstNode &) -> AstNode & = default;
        auto operator=(AstNode &&) noexcept -> AstNode & = default;

        [[nodiscard]] auto type() const noexcept -> AstNodeType
        {
            return nodeType;
        }

        [[nodiscard]] auto is(const AstNodeType type) const noexcept -> bool
        {
            return nodeType == type;
        }

        template<std::derived_from<AstNode> T>
        [[nodiscard]] auto as() const -> T &
        {
            if (T::classof() != type()) {
                throw std::invalid_argument("Unable to convert AstNode");
            }

            return static_cast<T &>(*this);
        }

    private:
        AstNodeType nodeType;
    };

    class Program : public AstNode {
    public:
        Program() : AstNode(classof())
        {}

        auto addNode(std::unique_ptr<AstNode> node) -> void
        {
            nodes.emplace_back(std::move(node));
        }

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::ROOT;
        }

    private:
        std::vector<std::unique_ptr<AstNode>> nodes;
    };

    class ValueExpression : public AstNode {
    public:
        explicit ValueExpression(const FscValue &value_) : AstNode(classof()), value(value_)
        {}

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::VALUE;
        }

        [[nodiscard]] auto getValue() noexcept -> std::any &
        {
            return value.value;
        }

        [[nodiscard]] auto getValue() const noexcept -> const std::any &
        {
            return value.value;
        }

        [[nodiscard]] auto getValueType() const noexcept -> size_t
        {
            return value.type;
        }

    private:
        FscValue value;
    };

    class VariableExpression : public AstNode {
    public:
        explicit VariableExpression(const std::string &name_) : AstNode(classof()), name(name_)
        {}

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::VARIABLE;
        }

    private:
        std::string name;
    };

    class BinaryExpression : public AstNode {
    public:
        BinaryExpression(std::unique_ptr<AstNode> lhs_, const BinaryExpressionType expr_type,
                         std::unique_ptr<AstNode> rhs_)
            : AstNode(classof()), lhs(std::move(lhs_)), rhs(std::move(rhs_)),
              binaryExpressionType(expr_type)
        {}

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::BINARY_EXPRESSION;
        }

        [[nodiscard]] auto getLhs() noexcept -> std::unique_ptr<AstNode> &
        {
            return lhs;
        }

        [[nodiscard]] auto getRhs() noexcept -> std::unique_ptr<AstNode> &
        {
            return rhs;
        }

        [[nodiscard]] auto getBinaryExpressionType() const noexcept -> BinaryExpressionType
        {
            return binaryExpressionType;
        }

    private:
        std::unique_ptr<AstNode> lhs;
        std::unique_ptr<AstNode> rhs;
        BinaryExpressionType binaryExpressionType;
    };
}// namespace fsc

#endif /* FSC_NODE_HPP */
