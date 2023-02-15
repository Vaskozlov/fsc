#ifndef FSC_CLASS_HPP
#define FSC_CLASS_HPP

#include "ast/container/body.hpp"
#include "ast/function/function.hpp"
#include "ast/value/variable_definition.hpp"
#include "type/type.hpp"
#include <ccl/raii.hpp>

namespace fsc::ast
{
    class Class : public NodeWrapper<NodeType::CLASS, SemicolonNeed::DO_NOT_NEED, Body>
    {
        ccl::Map<std::string, FscType> constructionMemberVariables;
        ccl::SmallVector<std::string> templates;
        std::string name;

    public:
        explicit Class(
            std::string class_name, Visitor &visitor, BodyContext *body_context,
            TemplateContext *template_context);

        auto analyze() -> void final;

        auto analyzeOnConstruction() const -> void;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto addNode(NodePtr node) -> void final;

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getTemplates() const noexcept -> const ccl::SmallVector<std::string> &
        {
            return templates;
        }

    private:
        auto parseTemplates(TemplateContext *template_context) -> void;

        auto addVariable(ast::VariableDefinition &variable_definition) -> void;
        auto addFunction(ast::Function &function_declaration) -> void;

        auto generateTemplateParameters(ccl::codegen::BasicCodeGenerator &output) const -> void;

        auto mapTemplates() const -> void;
        auto unmapTemplates() const -> void;
    };
}// namespace fsc::ast

#endif /* FSC_CLASS_HPP */
