#ifndef FSC_IF_HPP
#define FSC_IF_HPP

#include "ast/basic_node.hpp"
#include <ccl/flatmap.hpp>

namespace fsc::ast
{
    enum struct IfType : ccl::u16
    {
        IF,
        ELIF,
        ELSE
    };

    class If final : public NodeWrapper<NodeType::IF, SemicolonNeed::DO_NOT_NEED>
    {
    private:
        NodePtr condition;
        NodePtr body;
        IfType ifType;

    public:
        If(IfType if_type, NodePtr if_condition, NodePtr if_body) noexcept;

        [[nodiscard]] auto getIfType() const noexcept -> IfType
        {
            return ifType;
        }

        auto analyze() const -> void final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_IF_HPP */
