#include "ast/class.hpp"
#include "ast/function.hpp"
#include "ast/variable_definition.hpp"
#include "stack/stack.hpp"
#include <ranges>

namespace fsc::ast {
    using namespace std::string_view_literals;

    Class::Class(std::string name_) : Body{classof()}, name{std::move(name_)}
    {
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

    auto Class::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}Class: {}\n", getPrintingPrefix(prefix, is_left), name);
        defaultBodyPrint(expandPrefix(prefix, is_left), false);
    }

    auto Class::addNode(NodePtr node) -> void
    {
        if (node->is(NodeType::VARIABLE_DEFINITION)) {
            const auto &variable = node->as<ast::VariableDefinition>();
            FscType::addMemberVariable(FscType::getTypeId(name),
                                       ccl::makeShared<Variable>(variable.toVariable()));
        } else if (node->is(NodeType::FUNCTION)) {
            auto &function = node->as<ast::Function>();
            function.makeFunctionMember(FscType::getTypeId(name));
        }

        emplaceNode(std::move(node));
    }
}// namespace fsc::ast
