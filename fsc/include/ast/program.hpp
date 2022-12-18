#ifndef FSC_PROGRAM_HPP
#define FSC_PROGRAM_HPP

#include "ast/body.hpp"
#include <ast/basic_node.hpp>

namespace fsc::ast
{
    class Program : public NodeWrapper<NodeType::PROGRAM, SemicolonNeed::DO_NOT_NEED, Body>
    {
    public:
        Program();

        auto codeGen(gen::CodeGenerator &output) const -> void final;
        auto print(const std::string &prefix, bool is_left) const -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_PROGRAM_HPP */
