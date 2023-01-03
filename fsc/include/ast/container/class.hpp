#ifndef FSC_CLASS_HPP
#define FSC_CLASS_HPP

#include "ast/container/body.hpp"
#include "ast/function/function.hpp"
#include "ast/value/variable_definition.hpp"

namespace fsc::ast
{
    class Class : public NodeWrapper<NodeType::CLASS, SemicolonNeed::DO_NOT_NEED, Body>
    {
        ccl::Map<std::string, ccl::Id> constructionMemberVariables;
        std::string name;

    public:
        explicit Class(std::string name_);

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto addNode(NodePtr node) -> void final;

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return name;
        }

    private:
        auto addVariable(ast::VariableDefinition &variable_definition) -> void;
        auto addFunction(ast::Function &function_declaration) -> void;
    };
}// namespace fsc::ast

#endif /* FSC_CLASS_HPP */
