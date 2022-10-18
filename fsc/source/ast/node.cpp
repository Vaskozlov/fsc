#include "ast/function_node.hpp"
#include <ranges>

using namespace std::string_view_literals;

namespace fsc {
    const std::unordered_map<BinaryExpressionType, std::string_view> BinaryExpressionsStr{
            {BinaryExpressionType::ADD, "+"sv}, {BinaryExpressionType::SUB, "-"sv},
            {BinaryExpressionType::MUL, "*"sv}, {BinaryExpressionType::DIV, "/"sv},
            {BinaryExpressionType::MOD, "%"sv},
    };

    static inline auto operator*(const std::string_view &str, const std::size_t repeat)
            -> std::string
    {
        auto ret = std::string{};
        ret.reserve(str.size() * repeat);

        for (size_t i = 0; i != repeat; ++i) {
            ret += str;
        }

        return ret;
    }

    auto AstNode::getPrintingPrefix(const std::string &prefix, const bool is_left) -> std::string
    {
        return prefix + (is_left ? "\u251c\u2500\u2500" : "\u2514\u2500\u2500");
    }

    auto AstNode::expandPrefix(const std::string &prefix, const bool is_left,
                               const size_t extra_expansion) -> std::string
    {
        constexpr auto default_printing_shift = "   "sv;
        auto result = prefix + (is_left ? "\u2502   " : "    ");

        result.append(default_printing_shift * extra_expansion);
        return result;
    }

    auto Program::print(const std::string &prefix, const bool is_left) const -> void
    {
        for (auto &node : nodes | std::views::take(nodes.size() - 1)) {
            node->print(expandPrefix(prefix, is_left, 1), true);
        }

        if (!nodes.empty()) {
            auto &node = nodes.back();
            node->print(expandPrefix(prefix, is_left, 1), true);
        }
    }

    auto Body::print(const std::string &prefix, const bool is_left) const -> void
    {
        for (auto &node : nodes | std::views::take(nodes.size() - 1)) {
            node->print(expandPrefix(prefix, is_left, 1), true);
        }

        if (!nodes.empty()) {
            auto &node = nodes.back();
            node->print(expandPrefix(prefix, is_left, 1), true);
        }
    }

    auto FunctionCall::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}Call {}\n", getPrintingPrefix(prefix, is_left), function.getName());

        for (auto &arg : arguments | std::views::take(arguments.size() - 1)) {
            arg->print(expandPrefix(prefix, is_left, 1), true);
        }

        if (!arguments.empty()) {
            auto &node = arguments.back();
            node->print(expandPrefix(prefix, is_left, 1), false);
        }
    }

    auto ReturnStatement::print(const std::string &prefix, const bool /*is_left*/) const -> void
    {
        fmt::print("{}Return\n", getPrintingPrefix(prefix, false));
        expression->print(expandPrefix(prefix, false, 1), false);
    }

    auto ValueExpression::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), value.toString());
    }

    auto VariableExpression::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}{}: {}\n", getPrintingPrefix(prefix, is_left), name,
                   FscValue::getTypename(getValueType()));
    }

    auto BinaryExpression::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left),
                   BinaryExpressionsStr.at(getBinaryExpressionType()));

        lhs->print(expandPrefix(prefix, is_left, 1), true);
        rhs->print(expandPrefix(prefix, is_left, 1), false);
    }
}// namespace fsc
