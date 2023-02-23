#include "ast/container/class.hpp"
#include "ast/function/function.hpp"
#include "ast/value/variable_definition.hpp"
#include "stack/stack.hpp"
#include "type/type.hpp"
#include <ccl/raii.hpp>
#include <ranges>

namespace fsc::ast
{
    using namespace ccl;
    using namespace std::string_view_literals;
    namespace sv = std::views;

    static constexpr auto CommaFilter(antlr4::tree::ParseTree *elem)
    {
        return elem->getText() != ",";
    }

    static constexpr auto NewLineFilter(antlr4::tree::ParseTree *elem) -> bool
    {
        const auto text = elem->getText();
        return !text.empty() && text[0] != '\n';
    }

    Class::Class(std::string class_name)
      : name{std::move(class_name)}
      , fscType{TypeManager::createNewType(name, {.isTriviallyCopyable = false})}
    {}

    auto Class::finishClass(
        Visitor &visitor, BodyContext *body_context, TemplateContext *template_context) -> void
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
            sv::drop(1) | views::dropBack(body_children, 2) | sv::filter(NewLineFilter);

        for (auto *child : body_children | modifiers) {
            addNode(visitor.visitAsNode(child));
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

        for (auto *function_template : children | sv::filter(CommaFilter)) {
            templates.emplace_back(TypeManager::createNewType(
                function_template->getText(), {}, CreationType::TEMPLATE_KEEP_NAME));
        }

        auto type_info = TypeManager::getInfoAboutType(fscType);
        type_info.templatesParametersCount = templates.size();

        TypeManager::updateTypeInfo(fscType, type_info);
    }

    auto Class::analyze() -> void
    {
        if (templates.empty()) {
            Body::defaultAnalyze();
        }
    }

    auto Class::analyzeOnConstruction() const -> void
    {
        const auto class_scope = ProgramStack.acquireClassScope(fscType);
        const auto stack_scope = ProgramStack.acquireStackScope(ScopeType::SOFT);
        Body::defaultAnalyze();
    }

    auto Class::codeGen(ccl::codegen::BasicCodeGenerator &output) -> void
    {
        generateTemplateParameters(output);

        output << "class " << name;
        Body::defaultCodegen(output);
        output << ';';
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
        defaultBodyPrint(expandPrefix(prefix, is_left), false);
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
