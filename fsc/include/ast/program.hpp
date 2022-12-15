#ifndef FSC_PROGRAM_HPP
#define FSC_PROGRAM_HPP

#include "ast/body.hpp"

namespace fsc::ast
{
    class Program : public NodeWrapper<NodeType::PROGRAM, Body>
    {
    public:
        Program()
        {
            CCL_ASSERT(getNodeType() == NodeType::PROGRAM);
        }

        auto codeGen(gen::CodeGenerator &output) const -> void final;
        auto print(const std::string &prefix, bool is_left) const -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_PROGRAM_HPP */
