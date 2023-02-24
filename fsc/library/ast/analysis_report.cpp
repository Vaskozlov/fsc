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

    auto AnalysisReport::hasBeenRead(const NodePtr &node) const noexcept -> bool
    {
        const auto *variable = dynamic_cast<Variable *>(node.get());

        if (variable == nullptr) {
            return false;
        }

        return header.has_value() && header->readVariables.contains(variable->getUuid());
    }

    auto AnalysisReport::hasBeenModified(const NodePtr &node) const noexcept -> bool
    {
        const auto *variable = dynamic_cast<Variable *>(node.get());

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

    auto AnalysisReport::addToRead(const NodePtr &node) -> void
    {
        const auto *variable = dynamic_cast<Variable *>(node.get());

        if (variable == nullptr) {
            return;
        }

        initIfNull();

        header->readVariables.emplace(variable->getUuid());
    }

    auto AnalysisReport::addToModified(const NodePtr &node) -> void
    {
        const auto *variable = dynamic_cast<Variable *>(node.get());

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