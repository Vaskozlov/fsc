#include "ast/basic_node.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;

namespace fsc::ast
{
    static auto operator*(const std::string_view &str, const std::size_t repeat) -> std::string
    {
        auto ret = std::string{};
        ret.reserve(str.size() * repeat);

        CCL_UNROLL_N(4)
        for (auto i = 0ZU; i != repeat; ++i) {
            ret += str;
        }

        return ret;
    }

    Node::Node(NodeType node_type) noexcept
      : nodeType{node_type}
    {}

    auto Node::setNodeType(NodeType node_type) noexcept -> void
    {
        nodeType = node_type;
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

    auto Node::getValueType() const -> ccl::Id
    {
        throw std::runtime_error{"getValueType() is not implemented"};
    }
}// namespace fsc::ast
