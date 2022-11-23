#include "ast/function.hpp"
#include "stack/stack.hpp"
#include <function/argument.hpp>
#include <ranges>
#include <type/type.hpp>

using namespace std::string_view_literals;

namespace fsc::ast {
    Function::Function(const FscParser::FunctionContext *function_context_, Visitor &visitor_,
                       TypeId class_id_)
        : Node{classof()}, name{function_context_->children.at(2)->getText()}, classId(class_id_)
    {
        const auto &children = function_context_->children;
        const auto &parameters = children.at(3);

        processAttributes(ccl::as<FscParser::Function_attibutesContext *>(children.front()));
        setReturnType(children);
        readArguments(ccl::as<const FscParser::ParametersContext *>(parameters), visitor_);

        processMagicMethod();

        ProgramStack.pushScope(ScopeType::HARD);

        for (auto &&arg : arguments) {
            ProgramStack.addVariable(arg.toVariable());
        }

        function = visitor_.visitNode(children.back());
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

        switch (magicType) {
            case MagicFunctionType::INIT:
                output.write(fmt::format("{}", name));
                break;

            default:
                output.write(fmt::format("{} {}", FscType::getTypeName(returnType), name));
                break;
        }

        output.write('(');
        genArguments(output);
        output.write(')');

        const auto *body = function.get();
        body->codeGen(output);
    }

    auto Function::processMagicMethod() -> void
    {
        if (name == "__init__" && classId != 0) {
            processInitMethod();
        }
    }

    auto Function::processInitMethod() -> void
    {
        magicType = MagicFunctionType::INIT;
        name = FscType::getTypeName(classId);

        if (returnType != 0) {
            throw std::runtime_error("You are not allowed to set return type of __init__ method");
        }

        returnType = classId;
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

        const auto needs_to_be_constant = category == ArgumentCategory::IN;
        const auto need_to_be_passed_by_reference =
                ccl::lor(category == ArgumentCategory::OUT, category == ArgumentCategory::INOUT);

        output.write(fmt::format("{}{} {}{}", type_name, needs_to_be_constant ? "const " : "",
                                 need_to_be_passed_by_reference ? "&" : "", arg_name));

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
            auto *casted_child = ccl::as<FscParser::Typed_arguments_listContext *>(child);

            for (auto &arg : casted_child->children | std::views::filter(comma_filter)) {
                auto *argument_context = ccl::as<FscParser::ArgumentContext *>(arg);
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
                ccl::as<FscParser::Argument_definitionContext *>(children.front());
        auto argument = defineArgument(argument_definition);
        auto *argument_initializer = ccl::as<FscParser::ExprContext *>(children.back());

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
