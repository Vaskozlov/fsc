#ifndef FSC_WHILE_HPP
#define FSC_WHILE_HPP

#include "ast/analysis_report.hpp"

namespace fsc::ast
{
    class While final : public NodeWrapper<NodeType::WHILE, SemicolonNeed::DO_NOT_NEED>
    {
    private:
        NodePtr condition;
        NodePtr body;

    public:
        While(NodePtr while_condition, NodePtr while_body);

        auto analyze() -> AnalysisReport final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;

        auto optimize(OptimizationLevel level) -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_WHILE_HPP */
