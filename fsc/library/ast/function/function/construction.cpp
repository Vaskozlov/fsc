#include "ast/function/function.hpp"
#include "filter.hpp"
#include "function/functions_holder.hpp"
#include "stack/stack.hpp"
#include <range/v3/view.hpp>

namespace fsc::ast
{
    using namespace ccl;

    Function::Function(BasicContextPtr node_context)
      : NodeWrapper{node_context}
    {}

    Function::Function(
        FscType class_type, std::string_view function_name, std::string_view codegen_name,
        FscType return_type, InitializerList<Argument> function_arguments,
        FunctionInfo function_info, const ccl::Vector<FscType> &function_templates,
        MagicFunctionType magic, ccl::Optional<NodePtr> (*compile_time_function)())
      : arguments{function_arguments}
      , templates{function_templates}
      , comiletimeVersionOfBuiltinFunction{compile_time_function}
      , name{function_name}
      , codegenName{codegen_name}
      , functionInfo{function_info}
      , returnType{return_type}
      , classType{class_type}
      , magicType{magic}
    {}

    auto Function::finishConstruction(const FunctionContext *function_context, FscType class_type)
        -> void
    {
        functionContext = function_context;
        const auto &children = functionContext->children;
        auto *function_name = children.at(2);
        auto *function_attributes = ccl::as<FunctionAttributeContext *>(children.at(0));
        auto *function_templates = ccl::as<TemplateContext *>(children.at(3));
        const auto *parameters = ccl::as<ParametersContext *>(children.at(4));

        classType = class_type;
        name = function_name->getText();
        functionInfo.IS_METHOD = classType != Void;
        functionInfo.CONSTANT_METHOD = functionInfo.IS_METHOD;
        functionInfo.STATIC_METHOD = functionInfo.IS_METHOD;

        processAttributes(function_attributes);

        const auto templated_types = Raii{
            [this, function_templates]() {
                processTemplates(function_templates);
            },
            [this]() {
                for (const auto &function_template : templates) {
                    TypeManager::hideTemplate(function_template.getName());
                }
            }};

        setReturnType(children);
        readArguments(parameters);

        processMagicMethod();
        func::Functions.registerFunction(shared_from_this());

        if (classType != Void) {
            if (!templates.empty()) {
                GlobalVisitor->throwError(
                    ExceptionCriticality::PANIC, getContext().value(),
                    "methods are not allowed to have templates in current implementation");
            }

            completeBody();
        }
    }

    auto Function::completeBody() -> void
    {
        auto hash = hashTypes(templates);

        if (!analyzedHashes.contains(hash)) {
            const auto &children = functionContext->children;
            const auto function_scope = GlobalVisitor->acquireFunctionScope(getReturnType());
            const auto stack_scope = ProgramStack.acquireStackScope(ScopeType::HARD);

            for (const auto &arg : arguments) {
                ProgramStack.addVariable(makeShared<ast::Variable>(arg.toVariable()));
            }

            functionBody = GlobalVisitor->visitAsNode(children.back());

            if (getReturnType() == Auto && templates.empty()) {
                returnType = GlobalVisitor->getCurrentFunctionReturnType();
            }

            analyzedHashes.emplace(hash, returnType);
        } else {
            if (getReturnType() == Auto && templates.empty()) {
                returnType = analyzedHashes.at(hash);
            }
        }
    }

    auto Function::readArguments(const FscParser::ParametersContext *parameters_context) -> void
    {
        const auto &children = parameters_context->children;
        auto drop_first_and_last = ranges::views::drop(1) | ranges::views::drop_last(1);

        for (auto *child : children | drop_first_and_last) {
            auto *casted_child = ccl::as<FscParser::Typed_arguments_listContext *>(child);

            for (auto *arg : casted_child->children | filter::comma) {
                auto *argument_context = ccl::as<FscParser::ArgumentContext *>(arg);
                auto argument = processArgument(argument_context);
                arguments.push_back(std::move(argument));
            }
        }
    }

    auto Function::processArgument(const FscParser::ArgumentContext *argument_context) -> Argument
    {
        const auto &children = argument_context->children;
        auto *argument_definition =
            ccl::as<FscParser::Argument_definitionContext *>(children.front());
        auto argument = defineArgument(argument_definition);
        auto *argument_initializer = ccl::as<ExpressionContext *>(children.back());

        if (argument_initializer != nullptr) {
            defaultArguments.emplace(
                argument.getName(), GlobalVisitor->visitAsNode(argument_initializer));
        }

        return argument;
    }

    auto Function::processTemplates(TemplateContext *ctx) -> void
    {
        if (ctx->children.empty()) {
            return;
        }

        const auto &children = ctx->children.at(1)->children;

        for (auto *function_template : children | filter::comma) {
            templates.emplace_back(TypeManager::createNewType(
                function_template->getText(), {}, CreationType::TEMPLATE_KEEP_NAME));
        }
    }
}// namespace fsc::ast
