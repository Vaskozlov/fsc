#include "ast/container/class.hpp"
#include "ast/function/function.hpp"
#include "ast/value/variable_definition.hpp"
#include "stack/stack.hpp"
#include <ranges>
#include <type/type.hpp>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    Class::Class(std::string class_name)
      : name{std::move(class_name)}
    {
        if (FscType::exists(name)) {
            throw std::invalid_argument(fmt::format("{} already exists", name));
        }

        FscType::registerNewType(name, {.isTriviallyCopyable = false});
    }

    auto Class::analyze() const -> void
    {
        defaultAnalyze();
    }

    auto Class::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        output << "class " << name;
        defaultBodyCodegen(output);
        output << ';';
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
