#include "ast/class.hpp"
#include "ast/body.hpp"
#include "ast/variable_definition.hpp"
#include "stack/stack.hpp"
#include <ranges>

namespace fsc::ast {
    using namespace std::string_view_literals;

    Class::Class(std::string name_) : Body(classof()), name(std::move(name_))
    {
        if (FscType::exists(name)) {
            throw std::invalid_argument(fmt::format("{} already exists", name));
        }

        FscType::registerNewType(name, {.isTriviallyCopyable = false});
    }

    auto Class::codeGen(gen::CodeGenerator &output) const -> void
    {
        output.add("class "sv);
        output.add(name);
        defaultBodyCodegen(output);
        output.add(';');
    }

    auto Class::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}Class\n", getPrintingPrefix(prefix, is_left));
        defaultBodyPrint(expandPrefix(prefix, is_left), false);
    }

    auto Class::addNode(std::shared_ptr<Node> node) -> void
    {
        if (node->is(NodeType::VARIABLE_DEFINITION)) {
            const auto &variable = node->as<ast::VariableDefinition>();
            FscType::addMemberVariable(FscType::getTypeId(name), variable.getName(),
                                       variable.getValueType());
        } else if (node->is(NodeType::FUNCTION)) {
        }

        emplaceNode(std::move(node));
    }
}// namespace fsc::ast
