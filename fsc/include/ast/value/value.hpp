#ifndef FSC_VALUE_HPP
#define FSC_VALUE_HPP

#include "ast/analysis_report.hpp"
#include "type/type.hpp"
#include <ccl/core/types.hpp>

namespace fsc::ast
{
    class Value final : public NodeWrapper<NodeType::VALUE, SemicolonNeed::NEED>
    {
        ccl::UniquePtr<FscTypeInterface> value;

    public:
        explicit Value(ccl::UniquePtr<FscTypeInterface> t_value, BasicContextPtr node_context);

        auto analyze() -> AnalysisReport final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;

        [[nodiscard]] auto getValue() const -> const FscTypeInterface *
        {
            return value.get();
        }

        [[nodiscard]] auto getValueType() -> FscType final;
    };
}// namespace fsc::ast

#endif /* FSC_VALUE_HPP */
