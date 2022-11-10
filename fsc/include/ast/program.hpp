#ifndef FSC_PROGRAM_HPP
#define FSC_PROGRAM_HPP

#include "ast/body.hpp"

namespace fsc::ast {
    class Program : public Body {
    public:
        Program() : Body(classof())
        {}

        auto codeGen(gen::CodeGenerator &output) const -> void final;
        auto print(const std::string &prefix, const bool is_left) const -> void final;

        [[nodiscard]] constexpr static auto classof() noexcept -> NodeType
        {
            return NodeType::PROGRAM;
        }
    };
}// namespace fsc::ast

#endif /* FSC_PROGRAM_HPP */
