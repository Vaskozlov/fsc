#include "ast/function/function.hpp"
#include "ast/function/magic_methods_table.hpp"
#include "ast/value/variable.hpp"
#include "function/argument.hpp"
#include "function/functions_holder.hpp"
#include "stack/stack.hpp"
#include "type/builtin_types.hpp"
#include "type/type.hpp"
#include "visibility.hpp"
#include <Parser.h>
#include <ranges>

using namespace fsc::ast::magic;
using namespace std::string_view_literals;

namespace fsc::ast
{
    static constexpr auto CommaFilter(antlr4::tree::ParseTree *elem)
    {
        return elem->getText() != ",";
    }

    Function::Function() = default;

    Function::Function(
        ccl::Id class_id, std::string_view function_name, ccl::Id return_type,
        ccl::InitializerList<Argument> function_arguments, bool ends_with_parameter_pack)
      : arguments{function_arguments}
      , name{function_name}
      , returnType{return_type}
      , classId{class_id}
      , endsWithParameterPack{ends_with_parameter_pack}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::FUNCTION);
    }

    auto Function::finishConstruction(
        const FscParser::FunctionContext *function_context, Visitor &visitor, ccl::Id class_id)
        -> void
    {
        const auto &children = function_context->children;
        const auto &parameters = children.at(3);

        classId = class_id;
        name = children.at(2)->getText();

        processAttributes(ccl::as<FscParser::Function_attibutesContext *>(children.front()));
        setReturnType(children);
        readArguments(ccl::as<const FscParser::ParametersContext *>(parameters), visitor);

        processMagicMethod();
        func::Functions.registerFunction(shared_from_this());

        auto function_scope = visitor.acquireFunctionScope(getReturnType());
        auto stack_scope = ProgramStack.acquireStackScope(ScopeType::HARD);

        for (const auto &arg : arguments) {
            ProgramStack.addVariable(ccl::makeShared<ast::Variable>(arg.toVariable()));
        }

        function = visitor.visitAsNode(children.back());

        if (returnType == Auto::typeId) {
            returnType = visitor.getCurrentFunctionReturnType();
        }
    }

    auto Function::operator==(SignatureView other) const noexcept -> bool
    {
        const auto is_constructor =
            (other.classId == 0 && getMagicType() == MagicFunctionType::INIT);

        if (arguments.size() > std::size(other.arguments)) {
            return false;
        }

        const auto first_arguments_equal = std::ranges::equal(
            arguments.cbegin(), arguments.cend(), other.arguments.cbegin(),
            other.arguments.cbegin() + ccl::as<std::ptrdiff_t>(arguments.size()));

        if (!first_arguments_equal) {
            return false;
        }

        auto arguments_equal = first_arguments_equal;

        if (std::size(other.arguments) > arguments.size()) {
            arguments_equal = endsWithParameterPack;
        }

        return (arguments_equal && ((classId == other.classId) || is_constructor)) &&
               name == other.name;
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
            addConstexprModifier(output);
            output << fmt::format("{}", name);
            break;

        case MagicFunctionType::ADD:
        case MagicFunctionType::SUB:
        case MagicFunctionType::MUL:
        case MagicFunctionType::DIV:
        case MagicFunctionType::MOD:
            addNodiscardModifier(output);
            addConstexprModifier(output);
            output << fmt::format(
                "{} operator{}", FscType::getTypeName(returnType), MagicToRepr.at(magicType));
            break;

        default:
            addNodiscardModifier(output);
            addConstexprModifier(output);

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
        if (classId != 0) {
            if (name == "__init__") {
                processInitMethod();
            } else if (name == "__del__") {
                processDelMethod();
            } else if (SpecialFunctionsMagic.contains(name)) {
                processBinaryOperatorMethod(SpecialFunctionsMagic[name]);
            }
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

    auto Function::processBinaryOperatorMethod(MagicFunctionType binary_operator) noexcept(false)
        -> void
    {
        magicType = binary_operator;
        name = MagicToFscName.at(binary_operator);

        if (arguments.size() != 1) {
            throw std::runtime_error("You are allowed to pass one argument to binary magic method");
        }
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
        const auto &argument_name = arg.getName();
        output << arg;

        if (defaultArguments.contains(argument_name)) {
            output << " = " << *defaultArguments.at(argument_name);
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
        const auto &children = parameters_context->children;
        auto drop_first_and_last = std::views::drop(1) | ccl::views::dropBack(children, 2);

        for (auto &child : children | drop_first_and_last) {
            auto *casted_child = ccl::as<FscParser::Typed_arguments_listContext *>(child);

            for (auto &arg : casted_child->children | std::views::filter(CommaFilter)) {
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

    auto Function::addNodiscardModifier(gen::CodeGenerator &output) const -> void
    {
        if (returnType != Void::typeId && name != "main") {
            output << "[[nodiscard]] ";
        }
    }

    auto Function::addConstexprModifier(gen::CodeGenerator &output) const -> void
    {
        if (name != "main") {
            output << "constexpr ";
        }
    }
}// namespace fsc::ast
