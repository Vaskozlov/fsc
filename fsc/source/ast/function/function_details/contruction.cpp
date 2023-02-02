#include "ast/function/function.hpp"
#include "function/functions_holder.hpp"
#include "stack/stack.hpp"
#include <type/type.hpp>

namespace fsc::ast
{
    using namespace ccl;
    namespace sv = std::views;

    static constexpr auto CommaFilter(antlr4::tree::ParseTree *elem)
    {
        return elem->getText() != ",";
    }

    Function::Function() = default;

    Function::Function(
        FscType class_type, std::string_view function_name, FscType return_type,
        InitializerList<Argument> function_arguments, bool ends_with_parameter_pack)
      : arguments{function_arguments}
      , name{function_name}
      , returnType{return_type}
      , classType{class_type}
      , endsWithParameterPack{ends_with_parameter_pack}
      , builtinFunction{true}
    {}

    auto Function::finishConstruction(
        const FunctionContext *function_context, Visitor &visitor, FscType class_type) -> void
    {
        functionContext = function_context;
        const auto &children = functionContext->children;
        auto *function_name = children.at(2);
        auto *function_attributes = ccl::as<FunctionAttributeContext *>(children.at(0));
        auto *function_templates = ccl::as<FunctionTemplateContext *>(children.at(3));
        const auto *parameters = ccl::as<ParametersContext *>(children.at(4));

        classType = class_type;
        name = function_name->getText();

        processAttributes(function_attributes);
        const auto templated_types = Raii{
            [this, function_templates]() {
                processTemplates(function_templates);
            },
            [this]() {
                for (const auto &template_name : templates) {
                    FscType::freeTemplateType(template_name);
                }
            }};

        setReturnType(children);
        readArguments(parameters, visitor);

        processMagicMethod();
        func::Functions.registerFunction(shared_from_this());

        completeBody(visitor);
    }

    auto Function::completeBody(Visitor &visitor) -> void
    {
        const auto &children = functionContext->children;
        const auto function_scope = visitor.acquireFunctionScope(getReturnType());
        const auto stack_scope = ProgramStack.acquireStackScope(ScopeType::HARD);

        for (const auto &arg : arguments) {
            ProgramStack.addVariable(makeShared<ast::Variable>(arg.toVariable()));
        }

        functionBody = visitor.visitAsNode(children.back());

        if (getReturnType() == Auto && templates.empty()) {
            returnType = visitor.getCurrentFunctionReturnType();
        }
    }

    auto Function::readArguments(
        const FscParser::ParametersContext *parameters_context,
        Visitor &visitor) -> void
    {
        const auto &children = parameters_context->children;
        auto drop_first_and_last = sv::drop(1) | ccl::views::dropBack(children, 2);

        for (auto *child : children | drop_first_and_last) {
            auto *casted_child = ccl::as<FscParser::Typed_arguments_listContext *>(child);

            for (auto *arg : casted_child->children | sv::filter(CommaFilter)) {
                auto *argument_context = ccl::as<FscParser::ArgumentContext *>(arg);
                auto argument = processArgument(argument_context, visitor);
                arguments.push_back(std::move(argument));
            }
        }
    }

    auto Function::processArgument(
        const FscParser::ArgumentContext *argument_context,
        Visitor &visitor) -> Argument
    {
        const auto &children = argument_context->children;
        auto *argument_definition =
            ccl::as<FscParser::Argument_definitionContext *>(children.front());
        auto argument = defineArgument(argument_definition);
        auto *argument_initializer = ccl::as<ExpressionContext *>(children.back());

        if (argument_initializer != nullptr) {
            defaultArguments.emplace(argument.getName(), visitor.visitAsNode(argument_initializer));
        }

        return argument;
    }

    auto Function::processTemplates(FunctionTemplateContext *ctx) -> void
    {
        if (ctx->children.empty()) {
            return;
        }

        const auto &children = ctx->children.at(1)->children;

        for (auto *function_template : children | sv::filter(CommaFilter)) {
            templates.emplace_back(function_template->getText());
            FscType::registerTemplate(function_template->getText());
        }
    }
}// namespace fsc::ast
