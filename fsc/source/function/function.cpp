#include "function/function.hpp"
#include "stack/stack.hpp"
#include <ccl/flatmap.hpp>
#include <ranges>

using namespace std::string_view_literals;

namespace fsc::func {
    Function::Function(std::string name_, const TypeId return_type_,
                       ccl::InitializerList<Argument> arguments_,
                       CallRequirements call_requirements)
        : signature{std::move(name_), arguments_}, returnType{return_type_},
          callRequirements{call_requirements}
    {}

    Function::Function(const FscParser::FunctionContext *function_context, Visitor &visitor)
        : signature{function_context->children[2]->getText(), {}}
    {
        const auto &children = function_context->children;
        const auto &parameters = children.at(3);

        processAttributes(dynamic_cast<FscParser::Function_attibutesContext *>(children.front()));

        setReturnType(children);
        readArguments(dynamic_cast<const FscParser::ParametersContext *>(parameters), visitor);

        ProgramStack.pushScope(ScopeType::HARD);

        for (auto &&arg : signature.arguments) {
            ProgramStack.addVariable(arg.toVariable());
        }

        function = visitor.visitNode(children.back());
        ProgramStack.popScope();
    }

    auto Function::setReturnType(const std::vector<antlr4::tree::ParseTree *> &nodes) -> void
    {
        auto length = nodes.size();

        if (nodes[length - 4]->getText() == "->"sv) {
            const auto type_name = nodes[length - 3]->getText();

            FscType::checkTypeExistence(type_name);
            returnType = FscType::getTypeId(type_name);
        }
    }

    auto Function::readArguments(const FscParser::ParametersContext *parameters_context,
                                 Visitor &visitor) -> void
    {
        static constexpr auto comma_filter = [](const auto &elem) {
            return elem->getText() != ",";
        };

        auto &arguments = signature.arguments;
        const auto &children = parameters_context->children;
        auto drop_first_and_last = std::views::drop(1) | ccl::views::dropBack(children, 2);

        for (auto &child : children | drop_first_and_last) {
            auto *casted_child = dynamic_cast<FscParser::Typed_arguments_listContext *>(child);

            for (auto &arg : casted_child->children | std::views::filter(comma_filter)) {
                auto *argument_context = dynamic_cast<FscParser::ArgumentContext *>(arg);
                Argument argument = processArgument(argument_context, visitor);
                arguments.push_back(std::move(argument));
            }
        }
    }

    auto Function::processArgument(const FscParser::ArgumentContext *argument_context,
                                   Visitor &visitor) -> Argument
    {
        const auto &children = argument_context->children;
        auto *argument_definition =
                dynamic_cast<FscParser::Argument_definitionContext *>(children.front());
        auto argument = defineArgument(argument_definition);
        auto *argument_initializer = dynamic_cast<FscParser::ExprContext *>(children.back());

        if (argument_initializer != nullptr) {
            defaultArguments.emplace(argument.name, visitor.visitNode(argument_initializer));
        }

        return argument;
    }

    auto Function::processAttributes(FscParser::Function_attibutesContext *ctx) -> void
    {
        if (ctx->visibility() != nullptr) {
            visibility = VisibilityByStr.at(ctx->visibility()->getText());
        }
    }

    auto Function::defineArgument(const FscParser::Argument_definitionContext *argument_definition)
            -> Argument
    {
        const auto &children = argument_definition->children;

        const auto category = children.at(0)->getText();
        const auto type_name = children.at(1)->getText();
        const auto arg_name = children.at(2)->getText();

        FscType::checkTypeExistence(type_name);

        return {arg_name, FscType::getTypeId(type_name), ArgumentCategories.at(category)};
    }
}// namespace fsc::func
