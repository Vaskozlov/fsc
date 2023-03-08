#ifndef FSC_ANALYSIS_REPORT_HPP
#define FSC_ANALYSIS_REPORT_HPP

#include "ast/basic_node.hpp"

namespace fsc::ast
{
    class AnalysisReport
    {
        struct AnalysisHeader
        {
            ccl::Set<ccl::Id> readVariables;
            ccl::Set<ccl::Id> modifiedVariables;
            bool isNoexcept = true;
            bool isConstexpr = true;
        };

        ccl::Optional<AnalysisHeader> header{std::nullopt};

    public:
        [[nodiscard]] auto isNoexcept() const noexcept -> bool;
        [[nodiscard]] auto isConstexpr() const noexcept -> bool;
        [[nodiscard]] auto hasBeenRead(const Node *node) const noexcept -> bool;
        [[nodiscard]] auto hasBeenModified(const Node *node) const noexcept -> bool;

        auto updateConstexpr(bool is_constexpr) -> void;
        auto updateNoexcept(bool is_noexcept) -> void;
        auto addToRead(const NodePtr &node) -> void;
        auto addToModified(const NodePtr &node) -> void;

        auto merge(AnalysisReport &&other) -> void;

    private:
        auto initIfNull() -> void;
    };
}// namespace fsc::ast

#endif /* FSC_ANALYSIS_REPORT_HPP */
