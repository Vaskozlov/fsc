#include "function/function.hpp"
#include "stack/stack.hpp"
#include <ranges>

namespace fsc::func {
    Function::Function(std::string name_, const TypeId return_type_,
                       const std::initializer_list<Argument> &arguments_,
                       CallRequirements call_requirements)
        : signature{std::move(name_), arguments_}, returnType{return_type_},
          callRequirements{call_requirements}
    {}

    Function::Function(const FscParser::FunctionContext *function_context, Visitor &visitor)
        : signature{function_context->children[1]->getText(), {}}
    {
        const auto &children = function_context->children;
        const auto parameters = children.at(2);

        setReturnType(children);
        readArguments(dynamic_cast<const FscParser::ParametersContext *>(parameters), visitor);

        ProgramStack.pushScope(ScopeType::HARD);

        for (const auto &arg : signature.arguments) {
            ProgramStack.addVariable(ast::Variable{arg.name, arg.type});
        }

        function = visitor.visitNode(children.back());
        ProgramStack.popScope();
    }

    auto Function::setReturnType(const std::vector<antlr4::tree::ParseTree *> &nodes) -> void
    {
        auto length = nodes.size();

        if (nodes[length - 4]->getText() == "->") {
            const auto type_name = nodes[length - 3]->getText();

            FscType::checkExistence(type_name);
            returnType = FscType::getTypeId(type_name);
        }
    }

    auto Function::readArguments(const FscParser::ParametersContext *parameters_context,
                                 Visitor &visitor) -> void
    {
        static constexpr auto comma_filter = [](const auto &elem) {
            return elem->getText() != ",";
        };

        const auto &children = parameters_context->children;
        auto &arguments = signature.arguments;

        for (auto &child : children | std::views::drop(1) | std::views::take(children.size() - 2)) {
            auto *casted_child = dynamic_cast<FscParser::Typed_arguments_listContext *>(child);

            for (auto &arg : casted_child->children | std::views::filter(comma_filter)) {
                auto argument =
                        processArgument(dynamic_cast<FscParser::ArgumentContext *>(arg), visitor);
                arguments.push_back(std::move(argument));
            }
        }
    }

    auto Function::processArgument(const FscParser::ArgumentContext *argument_context,
                                   Visitor &visitor) -> Argument
    {
        const auto &children = argument_context->children;
        auto argument =
                defineArgument(dynamic_cast<FscParser::Argument_definitionContext *>(children[0]));
        auto *argument_initializer = dynamic_cast<FscParser::ExprContext *>(children.back());

        if (argument_initializer != nullptr) {
            defaultArguments[argument.name] = visitor.visitNode(argument_initializer);
        }

        return argument;
    }

    auto Function::defineArgument(const FscParser::Argument_definitionContext *argument_definition)
            -> Argument
    {
        const auto &children = argument_definition->children;

        const auto category = children.at(0)->getText();
        const auto type = children.at(1)->getText();
        const auto arg_name = children.at(2)->getText();

        FscType::checkExistence(type);

        return {arg_name, FscType::getTypeId(type), ArgumentCategories.at(category)};
    }
}// namespace fsc::func
