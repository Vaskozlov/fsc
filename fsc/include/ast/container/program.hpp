#ifndef FSC_PROGRAM_HPP
#define FSC_PROGRAM_HPP

#include "ast/container/body.hpp"

namespace fsc::ast
{
    class Program final : public NodeWrapper<NodeType::PROGRAM, SemicolonNeed::DO_NOT_NEED, Body>
    {
    public:
        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;
        auto print(const std::string &prefix, bool is_left) const -> void final;
    };
}// namespace fsc::ast

#endif /* FSC_PROGRAM_HPP */
