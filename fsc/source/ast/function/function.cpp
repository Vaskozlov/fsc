#include "ast/function/function.hpp"
#include "ast/value/variable.hpp"
#include "function/argument.hpp"
#include "stack/stack.hpp"
#include "type/builtin_types.hpp"
#include "visibility.hpp"
#include <ccl/ccl.hpp>
#include <ranges>
#include <type/type.hpp>

using namespace std::string_view_literals;

namespace fsc::ast
{
    Function::Function(
        const FscParser::FunctionContext *function_context, Visitor &visitor, ccl::Id class_id)
      : name{function_context->children.at(2)->getText()}
      , classId{class_id}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::FUNCTION);

        const auto &children = function_context->children;
        const auto &parameters = children.at(3);

        processAttributes(ccl::as<FscParser::Function_attibutesContext *>(children.front()));
        setReturnType(children);
        readArguments(ccl::as<const FscParser::ParametersContext *>(parameters), visitor);

        processMagicMethod();

        auto function_scope = FunctionScope{getReturnType(), visitor};
        auto stack_scope = StackScope{ScopeType::HARD, ProgramStack};

        for (const auto &arg : arguments) {
            ProgramStack.addVariable(ccl::makeShared<ast::Variable>(arg.toVariable()));
        }

        function = visitor.visitAsNode(children.back());

        if (returnType == Auto::typeId) {
            returnType = visitor.getCurrentFunctionReturnType();
        }
    }

    Function::Function(
        std::string_view function_name, ccl::Id return_type,
        ccl::InitializerList<Argument> function_arguments, CallRequirements call_requirements,
        bool ends_with_parameter_pack)
      : arguments{function_arguments}
      , name{function_name}
      , callRequirements{call_requirements}
      , returnType{return_type}
      , endsWithParameterPack{ends_with_parameter_pack}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::FUNCTION);
    }

    auto Function::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Function: {}\n", getPrintingPrefix(prefix, is_left), name);
        function->print(expandPrefix(prefix, is_left));
    }

    auto Function::codeGen(gen::CodeGenerator &output) const -> void
    {
        if (isMember()) {
            genVisibility(visibility, output);
        }

        switch (magicType) {
        case MagicFunctionType::DEL:
        case MagicFunctionType::INIT:
            output << fmt::format("{}", name);
            break;

        default:
            output << fmt::format("{} {}", FscType::getTypeName(returnType), name);
            break;
        }

        output << '(';
        genArguments(output);
        output << ')';

        const auto *body = function.get();
        output << *body;
    }

    auto Function::processMagicMethod() -> void
    {
        if (name == "__init__" && classId != 0) {
            processInitMethod();
        } else if (name == "__del__" && classId != 0) {
            processDelMethod();
        }
    }

    auto Function::processInitMethod() noexcept(false) -> void
    {
        magicType = MagicFunctionType::INIT;
        name = FscType::getTypeName(classId);

        if (returnType != Auto::typeId) {
            throw std::runtime_error("You are not allowed to set return type of __init__ method");
        }

        returnType = classId;
    }

    auto Function::processDelMethod() noexcept(false) -> void
    {
        magicType = MagicFunctionType::DEL;
        name = fmt::format("~{}", FscType::getTypeName(classId));

        if (!arguments.empty()) {
            throw std::runtime_error(
                "You are not allowed to set pass any arguments to __del__ method");
        }

        if (returnType != Auto::typeId) {
            throw std::runtime_error("You are not allowed to set return type of __del__ method");
        }

        returnType = 0;
    }

    auto Function::genArguments(gen::CodeGenerator &output) const -> void
    {
        for (const auto &arg : arguments | ccl::views::dropBack(arguments)) {
            argumentToString(output, arg);
            output << ", ";
        }

        if (!arguments.empty()) {
            argumentToString(output, arguments.back());
        }
    }

    auto Function::argumentToString(gen::CodeGenerator &output, const Argument &arg) const -> void
    {
        const auto &arg_name = arg.getName();
        auto category = arg.getCategory();
        const auto &type_name = FscType::getTypeName(arg.getType());

        if (category == ArgumentCategory::IN && FscType::isTriviallyCopyable(arg.getType())) {
            category = ArgumentCategory::COPY;
        }

        const auto needs_to_be_constant = category == ArgumentCategory::IN;
        const auto need_to_be_passed_by_reference =
            category == ArgumentCategory::OUT || category == ArgumentCategory::INOUT;

        output << fmt::format(
            "{}{} {}{}", type_name, needs_to_be_constant ? "const " : "",
            need_to_be_passed_by_reference ? "&" : "", arg_name);

        if (defaultArguments.contains(arg_name)) {
            output << " = " << *defaultArguments.at(arg_name);
        }
    }

    auto Function::setReturnType(const std::vector<antlr4::tree::ParseTree *> &nodes) -> void
    {
        auto length = nodes.size();

        if (nodes.at(length - 4)->getText() == "->") {
            const auto type_name = nodes[length - 3]->getText();

            FscType::checkTypeExistence(type_name);
            returnType = FscType::getTypeId(type_name);
        } else {
            returnType = Auto::typeId;
        }
    }

    auto Function::readArguments(
        const FscParser::ParametersContext *parameters_context,
        Visitor &visitor) -> void
    {
        static constexpr auto comma_filter = [](auto *elem) { return elem->getText() != ","; };

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

    auto Function::processArgument(
        const FscParser::ArgumentContext *argument_context,
        Visitor &visitor) -> Argument
    {
        const auto &children = argument_context->children;
        auto *argument_definition =
            ccl::as<FscParser::Argument_definitionContext *>(children.front());
        auto argument = defineArgument(argument_definition);
        auto *argument_initializer = ccl::as<FscParser::ExprContext *>(children.back());

        if (argument_initializer != nullptr) {
            defaultArguments.emplace(argument.getName(), visitor.visitAsNode(argument_initializer));
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
