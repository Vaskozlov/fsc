#include "ast/container/body.hpp"
#include "type/type.hpp"
#include <ranges>

namespace fsc::ast
{
    using namespace ccl;

    auto Body::getValueType() -> FscType
    {
        for (const auto &node : nodes) {
            if (node->is(NodeType::RETURN)) {
                return node->getValueType();
            }
        }

        return nodes.back()->getValueType();
    }

    auto Body::defaultCodegen(codegen::BasicCodeGenerator &output) -> void
    {
        using namespace codegen;

        auto first_node_passed = false;
        output << '{' << push_scope;

        for (const auto &node : nodes) {
            if (node->semicolonRequired() == SemicolonNeed::DO_NOT_NEED && !first_node_passed) {
                output << endl;
            }

            output << endl << *node;

            if (node->semicolonRequired() == SemicolonNeed::NEED) {
                output << ';';
            }

            first_node_passed = true;
        }

        output << pop_scope << endl << '}';
    }

    auto Body::analyze() -> void
    {
        Body::defaultAnalyze();
    }

    auto Body::defaultAnalyze() const -> void
    {
        for (const auto &node : nodes) {
            node->analyze();
        }
    }

    auto Body::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        Body::defaultCodegen(output);
    }

    auto Body::defaultBodyPrint(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);
        fmt::print("{}Body\n", getPrintingPrefix(prefix, is_left));

        for (const auto &node : nodes | ccl::views::dropBack(nodes, 1)) {
            node->print(expanded_prefix, true);
        }

        if (!nodes.empty()) {
            const auto &node = nodes.back();
            node->print(expanded_prefix, false);
        }
    }

    auto Body::print(const std::string &prefix, bool is_left) const -> void
    {
        Body::defaultBodyPrint(prefix, is_left);
    }

    auto Body::addNode(NodePtr node) -> void
    {
        emplaceNode(std::move(node));
    }
}// namespace fsc::ast
