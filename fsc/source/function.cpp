#include "function.hpp"
#include <fmt/format.h>

namespace fsc {
    const std::map<std::string, ParameterCategory, std::less<>> ParameterCategories{
            {"in", ParameterCategory::IN},
            {"inout", ParameterCategory::INOUT},
            {"out", ParameterCategory::OUT},
    };

    Function::Function(const FscParser::FunctionContext *function_context, FscVisitor &visitor)
        : name{function_context->children.at(1)->getText()}
    {
        const auto &children = function_context->children;
        const auto parameters = children.at(2);

        setReturnType(children);
        processArguments(dynamic_cast<const FscParser::ParametersContext *>(parameters));

        ProgramsStack.pushScope();

        for (const auto &arg : arguments) {
            ProgramsStack.addVariable(arg.name, FscValue{{}, arg.type});
        }

        body = std::any_cast<std::shared_ptr<AstNode>>(
                visitor.visit(function_context->children.back()));

        ProgramsStack.popScope();
    }

    Function::Function(std::string name_, size_t return_type_, BuiltinFunction builtin_function_,
                       std::vector<FunctionArgument> arguments_)
        : name{std::move(name_)}, arguments{std::move(arguments_)},
          returnType{return_type_}, body{builtin_function_}
    {}

    auto Function::invoke() -> FscValue
    {
        auto result = FscValue{};

        std::visit(Overload{[this, &result](BuiltinFunction func) {
                                result = func(arguments);
                            },
                            [&result](FscFunction func) {
                                func->print("", false);
                                result = func->getValue();
                            }},
                   body);

        return result;
    }

    auto Function::setReturnType(const std::vector<antlr4::tree::ParseTree *> &children) -> void
    {
        if (children.size() > 4) {
            const auto type_name = children[4]->getText();

            FscValue::checkTypeExistence(type_name);
            returnType = FscValue::typeByName(type_name);
        }
    }

    auto Function::processArguments(const FscParser::ParametersContext *parameters_context) -> void
    {
        const auto &children = parameters_context->children;

        for (auto &child : children | std::views::drop(1) | std::views::take(children.size() - 2)) {
            auto *casted_child = dynamic_cast<FscParser::Typed_arguments_listContext *>(child);

            for (auto &arg : casted_child->children | std::views::filter([](const auto &elem) {
                                 return elem->getText() != ",";
                             })) {
                auto argument =
                        processArgument(dynamic_cast<FscParser::Argument_definitionContext *>(arg));
                arguments.push_back(std::move(argument));
            }
        }
    }

    auto Function::processArgument(const FscParser::Argument_definitionContext *argument_definition)
            -> FunctionArgument
    {
        const auto &children = argument_definition->children;

        const auto arg_name = children.at(0)->getText();
        const auto category = children.at(2)->getText();
        const auto type = children.at(3)->getText();

        FscValue::checkTypeExistence(type);

        return {arg_name, FscValue::typeByName(type), ParameterCategories.at(category),
                dynamic_cast<FscParser::ExprContext *>(children.back())};
    }

}// namespace fsc
