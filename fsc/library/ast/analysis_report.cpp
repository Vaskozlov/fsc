#include "ast/analysis_report.hpp"
#include "ast/value/variable_definition.hpp"

namespace fsc::ast
{
    auto AnalysisReport::isNoexcept() const noexcept -> bool
    {
        return !header.has_value() || header->isNoexcept;
    }

    auto AnalysisReport::isConstexpr() const noexcept -> bool
    {
        return !header.has_value() || header->isConstexpr;
    }

    auto AnalysisReport::hasBeenRead(const Node *node) const noexcept -> bool
    {
        const auto *variable = ccl::as<const Variable *>(node);

        if (variable == nullptr) {
            return false;
        }

        return header.has_value() && header->readVariables.contains(variable->getUuid());
    }

    auto AnalysisReport::hasBeenModified(const Node *node) const noexcept -> bool
    {
        const auto *variable = ccl::as<const Variable *>(node);

        if (variable == nullptr) {
            return false;
        }

        return header.has_value() && header->modifiedVariables.contains(variable->getUuid());
    }

    auto AnalysisReport::updateNoexcept(bool is_noexcept) -> void
    {
        initIfNull();
        header->isNoexcept &= is_noexcept;
    }

    auto AnalysisReport::updateConstexpr(bool is_constexpr) -> void
    {
        initIfNull();
        header->isConstexpr &= is_constexpr;
    }

    auto AnalysisReport::addToReadVariables(const NodePtr &node) -> void
    {
        const auto variable = std::dynamic_pointer_cast<Variable>(node);

        if (variable == nullptr) {
            return;
        }

        initIfNull();

        header->readVariables.emplace(variable->getUuid());
    }

    auto AnalysisReport::addToModifiedVariables(const NodePtr &node) -> void
    {
        const auto variable = std::dynamic_pointer_cast<Variable>(node);

        if (variable == nullptr) {
            return;
        }

        initIfNull();

        header->modifiedVariables.emplace(variable->getUuid());
    }

    auto AnalysisReport::merge(AnalysisReport &&other) -> void
    {
        if (!header.has_value()) {
            *this = std::move(other);
            return;
        }

        if (!other.header.has_value()) {
            return;
        }

        updateNoexcept(other.isNoexcept());
        updateConstexpr(other.isConstexpr());

        header->readVariables.merge(other.header->readVariables);
        header->modifiedVariables.merge(other.header->modifiedVariables);
    }

    auto AnalysisReport::initIfNull() -> void
    {
        if (!header.has_value()) {
            header = AnalysisHeader{};
        }
    }
}// namespace fsc::ast