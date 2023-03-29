#include "ast/container/class.hpp"
#include "ast/function/function.hpp"
#include "ast/value/variable_definition.hpp"
#include "filter.hpp"
#include "stack/stack.hpp"
#include "type/type.hpp"
#include <ccl/raii.hpp>
#include <range/v3/view.hpp>

namespace fsc::ast
{
    using namespace ccl;
    using namespace std::string_view_literals;
    namespace sv = std::views;

    Class::Class(std::string class_name)
      : name{std::move(class_name)}
      , fscType{TypeManager::createNewType(name, {.isTriviallyCopyable = false})}
    {}

    Class::Class(
        FscType fsc_type, std::string class_name, InitializerList<FscType> class_templates,
        const ccl::Map<std::string, FscType> &member_variables)
      : memberVariables{member_variables}
      , templates{class_templates}
      , name{std::move(class_name)}
      , fscType{fsc_type}
    {}

    auto Class::finishClass(BodyContext *body_context, TemplateContext *template_context) -> void
    {
        const auto templates_map = ccl::Raii{
            [this, template_context]() {
                parseTemplates(template_context);
            },
            [this]() {
                unmapTemplates();
            }};

        const auto &body_children = body_context->children;

        const auto id_for_class_scope = FscType{getName()};
        const auto class_scope = ProgramStack.acquireClassScope(id_for_class_scope);
        const auto stack_scope = ProgramStack.acquireStackScope(ScopeType::SOFT);

        const auto modifiers =
            ranges::views::drop(1) | ranges::views::drop_last(1) | filter::newline;

        for (auto *child : body_children | modifiers) {
            addNode(GlobalVisitor->visitAsNode(child));
        }
    }

    auto Class::unmapTemplates() const -> void
    {
        for (const auto &class_template : templates) {
            TypeManager::hideTemplate(class_template.getName());
        }
    }

    auto Class::parseTemplates(TemplateContext *template_context) -> void
    {
        if (template_context->children.empty()) {
            return;
        }

        const auto &children = template_context->children.at(1)->children;

        for (auto *function_template : children | filter::comma) {
            templates.emplace_back(TypeManager::createNewType(
                function_template->getText(), {}, CreationType::TEMPLATE_KEEP_NAME));
        }

        auto type_info = TypeManager::getInfoAboutType(fscType);
        type_info.templatesParametersCount = templates.size();

        TypeManager::updateTypeInfo(fscType, type_info);
    }

    auto Class::analyze() -> AnalysisReport
    {
        if (templates.empty()) {
            return Body::analyze();
        }

        return {};
    }

    auto Class::analyzeOnConstruction() -> AnalysisReport
    {
        const auto class_scope = ProgramStack.acquireClassScope(fscType);
        const auto stack_scope = ProgramStack.acquireStackScope(ScopeType::SOFT);
        return Body::analyze();
    }

    auto Class::codeGen(ccl::codegen::BasicCodeGenerator &output) -> void
    {
        auto stream_id = fscType.getId() * 2;
        output << codegen::setStream(stream_id);

        generateTemplateParameters(output);

        output << "class " << name;
        Body::codeGen(output);
        output << ';';
    }

    auto Class::optimize(OptimizationLevel level) -> void
    {
        Body::optimize(level);
    }

    auto Class::generateTemplateParameters(codegen::BasicCodeGenerator &output) const -> void
    {
        if (!templates.empty()) {
            fmt::format_to(
                output.getBackInserter(), "template<typename {}>\n",
                fmt::join(templates, ", typename "));
        }
    }

    auto Class::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Class: {}\n", getPrintingPrefix(prefix, is_left), name);
        Body::print(expandPrefix(prefix, is_left), false);
    }

    auto Class::addNode(NodePtr node) -> void
    {
        switch (node->getNodeType()) {
        case NodeType::VARIABLE_DEFINITION:
            addVariable(node->as<ast::VariableDefinition>());
            break;

        case NodeType::FUNCTION:
            addFunction(node->as<ast::Function>());
            break;

        default:
            break;
        }

        emplaceNode(std::move(node));
    }

    auto Class::addVariable(ast::VariableDefinition &variable_definition) -> void
    {
        variable_definition.memberize();

        FscType{name}.addMemberVariable(
            ccl::makeShared<Variable>(variable_definition.toVariable()));
    }

    auto Class::addFunction(ast::Function &function_declaration) -> void
    {
        function_declaration.memberize(FscType{name});
    }
}// namespace fsc::ast
