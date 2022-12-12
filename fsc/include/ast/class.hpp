#ifndef FSC_CLASS_HPP
#define FSC_CLASS_HPP

#include "ast/body.hpp"
#include "ast/variable_definition.hpp"
#include <ast/basic_node.hpp>
#include <ast/function.hpp>

namespace fsc::ast
{
    class Class : public NodeWrapper<NodeType::CLASS, Body>
    {
        ccl::Map<std::string, ccl::Id> constructionMemberVariables;
        std::string name;

    public:
        explicit Class(std::string name_);

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto addNode(NodePtr node) -> void final;

        [[nodiscard]] auto getName() const -> const std::string &
        {
            return name;
        }

    private:
        auto addVariable(ast::VariableDefinition &variable_definition) -> void;
        auto addFunction(ast::Function &function_declaration) -> void;
    };
}// namespace fsc::ast

#endif /* FSC_CLASS_HPP */
