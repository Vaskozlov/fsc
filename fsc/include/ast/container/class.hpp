#ifndef FSC_CLASS_HPP
#define FSC_CLASS_HPP

#include "ast/container/body.hpp"
#include "ast/function/function.hpp"
#include "ast/value/variable_definition.hpp"
#include "type/type.hpp"
#include <ccl/raii.hpp>

namespace fsc::ast
{
    class Class final : public NodeWrapper<NodeType::CLASS, SemicolonNeed::DO_NOT_NEED, Body>
    {
        ccl::Map<std::string, FscType> constructionMemberVariables;
        ccl::SmallVector<FscType> templates;
        std::string name;
        FscType fscType{Void};

    public:
        explicit Class(std::string class_name);

        auto finishClass(BodyContext *body_context, TemplateContext *template_context) -> void;

        auto analyze() -> AnalysisReport final;

        auto analyzeOnConstruction() const -> AnalysisReport;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto addNode(NodePtr node) -> void final;

        [[nodiscard]] auto getType() const noexcept -> FscType
        {
            return fscType;
        }

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getTemplates() const noexcept -> const ccl::SmallVector<FscType> &
        {
            return templates;
        }

    private:
        auto parseTemplates(TemplateContext *template_context) -> void;

        auto addVariable(ast::VariableDefinition &variable_definition) -> void;
        auto addFunction(ast::Function &function_declaration) -> void;

        auto generateTemplateParameters(ccl::codegen::BasicCodeGenerator &output) const -> void;

        auto unmapTemplates() const -> void;
    };
}// namespace fsc::ast

#endif /* FSC_CLASS_HPP */
