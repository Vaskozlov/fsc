#include "function.hpp"
#include <fmt/format.h>

namespace fsc {
    const std::map<std::string, ParameterCategory> ParameterCategories{
            {"in", ParameterCategory::IN},
            {"inout", ParameterCategory::INOUT},
            {"out", ParameterCategory::OUT},
    };

    Function::Function(FscParser::FunctionContext *function_context)
        : name{function_context->children.at(1)->getText()},
          body{dynamic_cast<FscFunction>(function_context->children.back())}
    {
        const auto &children = function_context->children;
        auto parameters = children.at(2);

        setReturnType(children);
        processArguments(dynamic_cast<FscParser::ParametersContext *>(parameters));
    }

    Function::Function(std::string name_, size_t return_type_, BuiltinFunction builtin_function_,
                       std::vector<FunctionArgument> arguments_)
        : name{std::move(name_)}, arguments{std::move(arguments_)},
          return_type{return_type_}, body{builtin_function_}
    {}

    auto Function::invoke(FscVisitor &visitor) -> FscValue
    {
        auto result = FscValue{};

        std::visit(overload{[this, &result](BuiltinFunction func) {
                                result = func(arguments);
                            },
                            [&visitor, &result](FscFunction func) {
                                result = std::any_cast<FscValue>(visitor.visit(func));
                            }},
                   body);

        return result;
    }

    auto Function::setReturnType(const std::vector<antlr4::tree::ParseTree *> &children) -> void
    {
        if (children.size() > 4) {
            auto type_name = children[4]->getText();

            FscValue::checkTypeExistence(type_name);
            return_type = FscValue::typeByName(type_name);
        }
    }

    auto Function::processArguments(FscParser::ParametersContext *parameters_context) -> void
    {
        const auto &children = parameters_context->children;

        for (auto &child: children | std::views::drop(1) | std::views::take(children.size() - 2)) {
            auto *casted_child = dynamic_cast<FscParser::Typed_arguments_listContext *>(child);

            for (auto &arg: casted_child->children | std::views::filter([](const auto &elem) {
                                return elem->getText() != ",";
                            })) {
                auto argument =
                        processArgument(dynamic_cast<FscParser::Argument_definitionContext *>(arg));
                arguments.push_back(std::move(argument));
            }
        }
    }

    auto Function::processArgument(FscParser::Argument_definitionContext *argument_definition)
            -> FunctionArgument
    {
        const auto &children = argument_definition->children;

        auto arg_name = children.at(0)->getText();
        auto category = children.at(2)->getText();
        auto type = children.at(3)->getText();

        FscValue::checkTypeExistence(type);

        return {arg_name, FscValue::typeByName(type), ParameterCategories.at(category),
                dynamic_cast<FscParser::ExprContext *>(children.back())};
    }

}// namespace fsc
