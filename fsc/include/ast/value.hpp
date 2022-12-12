#ifndef FSC_VALUE_HPP
#define FSC_VALUE_HPP

#include "ast/basic_node.hpp"
#include "type/type.hpp"

namespace fsc::ast
{
    class Value : public NodeWrapper<NodeType::VALUE>
    {
        ccl::SharedPtr<FscType> value;

    public:
        explicit Value(ccl::SharedPtr<FscType> t_value);

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        [[nodiscard]] auto getValueType() const noexcept -> ccl::Id final
        {
            return value->getId();
        }
    };
}// namespace fsc::ast

#endif /* FSC_VALUE_HPP */
