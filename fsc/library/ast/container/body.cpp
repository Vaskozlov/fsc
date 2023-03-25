#include "ast/container/body.hpp"
#include "ast/value/variable_definition.hpp"
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

    auto Body::analyze() -> AnalysisReport
    {
        auto report = AnalysisReport{};

        for (const auto &node : nodes) {
            report.merge(node->analyze());
        }

        analyzeReport(report);

        return report;
    }

    auto Body::analyzeReport(const AnalysisReport &report) const -> void
    {
        for (const auto &variable_definition_node : variableDefinition) {
            const auto *variable_definition =
                ccl::as<const VariableDefinition *>(variable_definition_node.get());

            if (!report.hasBeenModified(variable_definition) &&
                !variable_definition->isConstant() &&
                (!variable_definition->isMemberOfClass() ||
                 (variable_definition->isMemberOfClass() &&
                  variable_definition->getVisibility() == Visibility::PRIVATE))) {
                GlobalVisitor->throwError(
                    ccl::ExceptionCriticality::WARNING,
                    variable_definition->getContext().value(),
                    fmt::format("variable `{}` is never modified", variable_definition->getName()),
                    "consider making it constant");
            }
        }
    }

    auto Body::codeGen(codegen::BasicCodeGenerator &output) -> void
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

    auto Body::optimize(OptimizationLevel level) -> void
    {
        for (auto &node : nodes) {
            node->optimize(level);

            if (auto node_eval_result = node->eval(); node_eval_result.has_value()) {
                node = *node_eval_result;
            }
        }
    }

    auto Body::print(const std::string &prefix, bool is_left) const -> void
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

    auto Body::addNode(NodePtr node) -> void
    {
        emplaceNode(std::move(node));
    }

    auto Body::emplaceNode(NodePtr node) -> void
    {
        if (ccl::as<VariableDefinition *>(node.get()) != nullptr) {
            variableDefinition.emplace_back(node);
        }

        nodes.emplace_back(std::move(node));
    }
}// namespace fsc::ast
