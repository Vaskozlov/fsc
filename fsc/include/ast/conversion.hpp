#ifndef FSC_CONVERSION_HPP
#define FSC_CONVERSION_HPP

#include "ast/basic_node.hpp"

namespace fsc::ast
{
    class Conversion : public NodeWrapper<NodeType::CONVERSION>
    {
        NodePtr value;
        ccl::Id typeId;

    public:
        explicit Conversion(NodePtr value_to_convert, ccl::Id type_id);

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        [[nodiscard]] auto getValueType() const -> ccl::Id final;
    };
}// namespace fsc::ast

#endif /* FSC_CONVERSION_HPP */
