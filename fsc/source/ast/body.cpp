#include "ast/body.hpp"
#include <ranges>

namespace fsc::ast
{
    Body::Body()
    {
        CCL_ASSERT(getNodeType() == NodeType::BODY);
    }

    auto Body::getValueType() const -> ccl::Id
    {
        for (const auto &node : nodes) {
            if (node->is(NodeType::RETURN)) {
                return node->getValueType();
            }
        }

        return nodes.back()->getValueType();
    }

    auto Body::defaultBodyCodegen(gen::CodeGenerator &output) const -> void
    {
        output.openCurly();
        output.pushScope();

        for (const auto &node : nodes) {
            output.newLine();
            node->codeGen(output);
            output.write(';');
        }

        output.popScope();
        output.newLine();
        output.closeCurly();
    }

    auto Body::codeGen(gen::CodeGenerator &output) const -> void
    {
        defaultBodyCodegen(output);
    }

    auto Body::defaultBodyPrint(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);
        fmt::print("{}Body\n", getPrintingPrefix(prefix, is_left));

        for (auto &node : nodes | ccl::views::dropBack(nodes, 1)) {
            node->print(expanded_prefix, true);
        }

        if (!nodes.empty()) {
            auto &node = nodes.back();
            node->print(expanded_prefix, false);
        }
    }

    auto Body::print(const std::string &prefix, bool is_left) const -> void
    {
        defaultBodyPrint(prefix, is_left);
    }

    auto Body::addNode(NodePtr node) -> void
    {
        emplaceNode(std::move(node));
    }
}// namespace fsc::ast
