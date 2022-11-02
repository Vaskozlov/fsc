#include "ast/body.hpp"
#include <ranges>

namespace fsc::ast {
    auto Body::getValueType() const noexcept -> TypeId
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
            output.add(';');
        }

        output.popScope();
        output.newLine();
        output.closeCurly();
    }

    auto Body::codeGen(gen::CodeGenerator &output) const -> void
    {
        defaultBodyCodegen(output);
    }

    auto Body::defaultBodyPrint(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}Body\n", getPrintingPrefix(prefix, is_left));

        for (auto &node : nodes | std::views::take(nodes.size() - 1)) {
            node->print(expandPrefix(prefix, is_left), true);
        }

        if (!nodes.empty()) {
            auto &node = nodes.back();
            node->print(expandPrefix(prefix, is_left), false);
        }
    }

    auto Body::print(const std::string &prefix, const bool is_left) const -> void
    {
        defaultBodyPrint(prefix, is_left);
    }

    auto Body::addNode(std::shared_ptr<Node> node) -> void
    {
        emplaceNode(std::move(node));
    }
}// namespace fsc::ast
