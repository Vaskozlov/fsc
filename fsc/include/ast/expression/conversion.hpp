#ifndef FSC_CONVERSION_HPP
#define FSC_CONVERSION_HPP

#include "ast/basic_node.hpp"
#include "type/type.hpp"

namespace fsc::ast
{
    class Conversion final : public NodeWrapper<NodeType::CONVERSION, SemicolonNeed::NEED>
    {
        NodePtr value;
        FscType type;

    public:
        explicit Conversion(NodePtr value_to_convert, FscType fsc_type);

        auto analyze() -> void final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        [[nodiscard]] auto getValueType() -> FscType final;
    };
}// namespace fsc::ast

#endif /* FSC_CONVERSION_HPP */
