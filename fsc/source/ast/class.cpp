#include "ast/class.hpp"
#include "ast/function.hpp"
#include "ast/variable_definition.hpp"
#include "stack/stack.hpp"
#include <ast/basic_node.hpp>
#include <ranges>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    Class::Class(std::string name_)
      : name{std::move(name_)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::CLASS);

        if (FscType::exists(name)) {
            throw std::invalid_argument(fmt::format("{} already exists", name));
        }

        FscType::registerNewType(name, {.isTriviallyCopyable = false});
    }

    auto Class::codeGen(gen::CodeGenerator &output) const -> void
    {
        output.write("class "sv);
        output.write(name);
        defaultBodyCodegen(output);
        output.write(';');
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
        variable_definition.convertToMember();
        FscType::addMemberVariable(
            FscType::getTypeId(name), ccl::makeShared<Variable>(variable_definition.toVariable()));
    }

    auto Class::addFunction(ast::Function &function_declaration) -> void
    {
        function_declaration.makeFunctionMember(FscType::getTypeId(name));
    }
}// namespace fsc::ast
