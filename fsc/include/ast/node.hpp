#ifndef FSC_NODE_HPP
#define FSC_NODE_HPP

#include "FscVisitor.h"
#include "builtin/types.hpp"
#include "stack.hpp"
#include <any>
#include <fmt/format.h>
#include <memory>
#include <vector>

namespace fsc {
    enum struct AstNodeType : size_t {
        NONE,
        ROOT,
        VALUE,
        VARIABLE,
        BODY,
        RETURN,
        FUNCTION_CALL,
        FUNCTION_DECLARATION,
        BINARY_EXPRESSION
    };

    enum struct BinaryExpressionType : size_t { ADD, SUB, MUL, DIV, MOD };

    extern const std::unordered_map<BinaryExpressionType, std::string_view> BinaryExpressionsStr;

    class AstNode {
    public:
        explicit AstNode(const AstNodeType type_) : nodeType(type_)
        {}

        AstNode(const AstNode &) = default;
        AstNode(AstNode &&) noexcept = default;
        virtual ~AstNode() = default;

        auto operator=(const AstNode &) -> AstNode & = default;
        auto operator=(AstNode &&) noexcept -> AstNode & = default;

        static auto getPrintingPrefix(const std::string &prefix, const bool is_left) -> std::string;
        static auto expandPrefix(const std::string &prefix, const bool is_left,
                                 const size_t extra_expansion) -> std::string;

        virtual auto print(const std::string &prefix = "", const bool is_left = false) const
                -> void = 0;

        [[nodiscard]] virtual auto getValue() -> FscValue
        {
            throw std::runtime_error("getValue() not implemented");
        }

        [[nodiscard]] virtual auto getValue() const -> FscValue
        {
            throw std::runtime_error("getValue() not implemented");
        }

        [[nodiscard]] virtual auto getValueType() const -> size_t
        {
            throw std::runtime_error("getValueType() not implemented");
        }

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

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        auto addNode(std::shared_ptr<AstNode> node) -> void
        {
            nodes.emplace_back(std::move(node));
        }

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::ROOT;
        }

    private:
        std::vector<std::shared_ptr<AstNode>> nodes;
    };

    class Body : public AstNode {
    public:
        Body() : AstNode(classof())
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] auto getValue() const -> FscValue final
        {
            for (const auto &node : nodes) {
                if (node->is(AstNodeType::RETURN)) {
                    return node->getValue();
                }
            }
        }

        [[nodiscard]] auto getValue() -> FscValue final
        {
            for (const auto &node : nodes) {
                if (node->is(AstNodeType::RETURN)) {
                    return node->getValue();
                }
            }
        }

        auto addNode(std::shared_ptr<AstNode> node) -> void
        {
            nodes.emplace_back(std::move(node));
        }

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::BODY;
        }

    private:
        std::vector<std::shared_ptr<AstNode>> nodes;
    };

    class ValueExpression : public AstNode {
    public:
        explicit ValueExpression(const FscValue &value_) : AstNode(classof()), value(value_)
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::VALUE;
        }

        [[nodiscard]] auto getValue() -> FscValue final
        {
            return value;
        }

        [[nodiscard]] auto getValue() const -> FscValue final
        {
            return value;
        }

        [[nodiscard]] auto getValueType() const -> size_t final
        {
            return value.type;
        }

    private:
        FscValue value;
    };

    class ReturnStatement : public AstNode {
    public:
        explicit ReturnStatement(std::shared_ptr<AstNode> expression_)
            : AstNode(classof()), expression(expression_)
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] auto getValue() -> FscValue final
        {
            return expression->getValue();
        }

        [[nodiscard]] auto getValue() const -> FscValue final
        {
            return expression->getValue();
        }

        [[nodiscard]] auto getValueType() const -> size_t final
        {
            return expression->getValueType();
        }

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::RETURN;
        }

    private:
        std::shared_ptr<AstNode> expression;
    };

    class VariableExpression : public AstNode {
    public:
        explicit VariableExpression(const std::string &name_) : AstNode(classof()), name(name_)
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] auto getValue() -> FscValue final
        {
            return ProgramsStack.get(name).value;
        }

        [[nodiscard]] auto getValue() const -> FscValue final
        {
            return ProgramsStack.get(name).value;
        }

        [[nodiscard]] auto getValueType() const -> size_t final
        {
            return ProgramsStack.get(name).value.type;
        }

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::VARIABLE;
        }

    private:
        std::string name;
    };

    class BinaryExpression : public AstNode {
    public:
        BinaryExpression(std::shared_ptr<AstNode> lhs_, const BinaryExpressionType expr_type,
                         std::shared_ptr<AstNode> rhs_)
            : AstNode(classof()), lhs(std::move(lhs_)), rhs(std::move(rhs_)),
              binaryExpressionType(expr_type)
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] static auto classof() noexcept -> AstNodeType
        {
            return AstNodeType::BINARY_EXPRESSION;
        }

        [[nodiscard]] auto getLhs() noexcept -> std::shared_ptr<AstNode> &
        {
            return lhs;
        }

        [[nodiscard]] auto getRhs() noexcept -> std::shared_ptr<AstNode> &
        {
            return rhs;
        }

        [[nodiscard]] auto getBinaryExpressionType() const noexcept -> BinaryExpressionType
        {
            return binaryExpressionType;
        }

    private:
        std::shared_ptr<AstNode> lhs;
        std::shared_ptr<AstNode> rhs;
        BinaryExpressionType binaryExpressionType;
    };
}// namespace fsc

#endif /* FSC_NODE_HPP */
