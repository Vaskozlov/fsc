#include "ast/function.hpp"
#include "stack/stack.hpp"
#include <ranges>

using namespace std::string_view_literals;

namespace fsc::ast {
    Function::Function(const FscParser::FunctionContext *function_context, Visitor &visitor)
        : Node(classof()), name(function_context->children.at(2)->getText())
    {
        const auto &children = function_context->children;
        const auto &parameters = children.at(3);

        processAttributes(dynamic_cast<FscParser::Function_attibutesContext *>(children.front()));

        setReturnType(children);
        readArguments(dynamic_cast<const FscParser::ParametersContext *>(parameters), visitor);

        ProgramStack.pushScope(ScopeType::HARD);

        for (auto &&arg : arguments) {
            ProgramStack.addVariable(arg.toVariable());
        }

        function = visitor.visitNode(children.back());
        ProgramStack.popScope();
    }

    Function::Function(std::string_view name_, const TypeId return_type_,
                       ccl::InitializerList<Argument> arguments_,
                       CallRequirements call_requirements_)
        : Node(classof()), arguments(arguments_), name(name_), callRequirements(call_requirements_),
          returnType(return_type_)
    {}

    auto Function::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}Function: {}\n", getPrintingPrefix(prefix, is_left), name);
        function->print(expandPrefix(prefix, is_left));
    }

    auto Function::codeGen(gen::CodeGenerator &output) const -> void
    {
        if (isMember()) {
            output.newLine();

            switch (visibility) {
                case Visibility::PUBLIC:
                    output.write("public:"sv);
                    break;

                case Visibility::PROTECTED:
                    output.write("protected:"sv);
                    break;

                case Visibility::EXPORT:
                    throw std::logic_error("Export member function are not allowed");

                default:
                    output.write("private: "sv);
                    break;
            }

            output.newLine();
        }

        output.write(FscType::getTypeName(returnType));
        output.write(' ');
        output.write(name);

        output.write('(');
        genArguments(output);
        output.write(')');

        const auto *body = function.get();
        body->codeGen(output);
    }

    auto Function::genArguments(gen::CodeGenerator &output) const -> void
    {
        for (const auto &arg : arguments | ccl::views::dropBack(arguments)) {
            argumentToString(output, arg);
            output.write(", "sv);
        }

        if (!arguments.empty()) {
            argumentToString(output, arguments.back());
        }
    }

    auto Function::argumentToString(gen::CodeGenerator &output, const Argument &arg) const -> void
    {
        const auto &arg_name = arg.name;
        auto category = arg.category;
        const auto &type_name = FscType::getTypeName(arg.type);

        if (category == ArgumentCategory::IN && FscType::isTriviallyCopyable(arg.type)) {
            category = ArgumentCategory::COPY;
        }

        switch (category) {
            case ArgumentCategory::COPY:
                output.write(fmt::format("{} {}", type_name, arg_name));
                break;

            case ArgumentCategory::IN:
                output.write(fmt::format("const {} & {}", type_name, arg_name));
                break;

            case ArgumentCategory::OUT:
            case ArgumentCategory::INOUT:
                output.write(fmt::format("{} & {}", type_name, arg_name));
                break;

            default:
                std::unreachable();
        }

        if (defaultArguments.contains(arg_name)) {
            output.write(" = "sv);
            defaultArguments.at(arg_name)->codeGen(output);
        }
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
        static constexpr auto comma_filter = [](auto *elem) {
            return elem->getText() != ",";
        };

        const auto &children = parameters_context->children;
        auto drop_first_and_last = std::views::drop(1) | ccl::views::dropBack(children, 2);

        for (auto &child : children | drop_first_and_last) {
            auto *casted_child = dynamic_cast<FscParser::Typed_arguments_listContext *>(child);

            for (auto &arg : casted_child->children | std::views::filter(comma_filter)) {
                auto *argument_context = dynamic_cast<FscParser::ArgumentContext *>(arg);
                auto argument = processArgument(argument_context, visitor);
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
}// namespace fsc::ast
