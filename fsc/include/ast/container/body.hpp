#ifndef FSC_BODY_HPP
#define FSC_BODY_HPP

#include "ast/analysis_report.hpp"
#include <ccl/codegen/basic_codegen.hpp>

namespace fsc::ast
{
    class Body : public NodeWrapper<NodeType::BODY, SemicolonNeed::DO_NOT_NEED>
    {
        ccl::Vector<NodePtr> nodes;
        ccl::Vector<NodePtr> variableDefinition;

    public:
        [[nodiscard]] auto begin() const noexcept -> auto
        {
            return nodes.begin();
        }

        [[nodiscard]] auto end() const noexcept -> auto
        {
            return nodes.end();
        }

        auto analyze() -> AnalysisReport override;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void override;

        auto print(const std::string &prefix, bool is_left) const -> void override;

        auto optimize(OptimizationLevel level) -> void override;

        [[nodiscard]] auto getValueType() -> FscType final;

        virtual auto addNode(NodePtr node) -> void;

    protected:
        auto emplaceNode(NodePtr node) -> void;

    private:
        auto analyzeReport(const AnalysisReport &report) const -> void;
    };
}// namespace fsc::ast

#endif /* FSC_BODY_HPP */
