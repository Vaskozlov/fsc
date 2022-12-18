#include "ast/basic_node.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;

namespace fsc::ast
{
    static auto operator*(std::string_view str, std::size_t repeat) -> std::string
    {
        auto result = std::string{};
        result.reserve(str.size() * repeat);

        CCL_UNROLL_N(4)
        for (auto i = ccl::as<size_t>(0); i != repeat; ++i) {
            result.append(str);
        }

        return result;
    }

    Node::Node(NodeType node_type, SemicolonNeed need_semicolon) noexcept
      : nodeType{node_type}
      , needSemicolon{need_semicolon}
    {}

    auto Node::setNodeType(NodeType node_type) noexcept -> void
    {
        nodeType = node_type;
    }

    auto Node::setSemicolonNeed(SemicolonNeed need_semicolon) noexcept -> void
    {
        needSemicolon = need_semicolon;
    }

    auto Node::getPrintingPrefix(const std::string &prefix, bool is_left) -> std::string
    {
        if (is_left) {
            return prefix + "\u251c\u2500\u2500";
        }

        return prefix + "\u2514\u2500\u2500";
    }

    auto Node::expandPrefix(const std::string &prefix, bool is_left, const size_t extra_expansion)
        -> std::string
    {
        static constexpr auto default_printing_shift = "   "sv;

        auto result = prefix + (is_left ? "\u2502   " : "    ");
        result.append(default_printing_shift * extra_expansion);

        return result;
    }

    auto Node::getValueType() const noexcept(false) -> ccl::Id
    {
        throw std::runtime_error{"getValueType() is not implemented"};
    }
}// namespace fsc::ast
