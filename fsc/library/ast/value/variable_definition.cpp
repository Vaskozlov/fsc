#include "ast/value/variable_definition.hpp"
#include "exception.hpp"
#include "type/type.hpp"
#include "visibility.hpp"
#include "visitor.hpp"
#include <type/antlr-types.hpp>

namespace fsc::ast
{
    using namespace ccl;
    using namespace std::string_view_literals;

    VariableDefinition::VariableDefinition(
        std::string variable_name, Lazy<FscType> &&fsc_type, VariableFlags variable_flags,
        NodePtr variable_initializer)
      : NodeWrapper{std::move(variable_name), std::move(fsc_type), variable_flags}
      , initializer{std::move(variable_initializer)}
    {}

    VariableDefinition::VariableDefinition(
        std::string variable_name, FscType fsc_type, VariableFlags variable_flags,
        NodePtr variable_initializer)
      : VariableDefinition{
            std::move(variable_name), toLazy(fsc_type), variable_flags,
            std::move(variable_initializer)}
    {}

    VariableDefinition::VariableDefinition(
        std::string variable_name, NodePtr variable_initializer, VariableFlags variable_flags,
        Visitor &visitor, antlr4::ParserRuleContext *ctx)
      : VariableDefinition{
            std::move(variable_name), toLazy([variable_initializer, &visitor, ctx]() {
                try {
                    return variable_initializer->getValueType();
                } catch (const FscException &e) {
                    visitor.throwError(ctx, e.what());
                }
            }),
            variable_flags, std::move(variable_initializer)}
    {}

    VariableDefinition::VariableDefinition(Visitor &visitor, VariableDefinitionContext *ctx)
      : VariableDefinition{
            readName(ctx), Lazy{readType(ctx)}, readFlags(ctx), readInitializer(visitor, ctx)}
    {}

    VariableDefinition::VariableDefinition(Visitor &visitor, AutoVariableDefinitionContext *ctx)
      : VariableDefinition{
            readName(ctx), readInitializer(visitor, ctx), readFlags(ctx), visitor, ctx}
    {}

    auto VariableDefinition::analyze() -> void
    {
        if (initializer == nullptr) {
            return;
        }

        const auto value_type = getValueType();
        const auto initializer_type = initializer->getValueType();

        if (value_type != initializer_type) {
            throw FscException(
                "unable to assign variable, because type of variable does not match with the "
                "initializer return type");
        }

        initializer->analyze();
    }

    auto VariableDefinition::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Definition of {}\n", getPrintingPrefix(prefix, is_left), getName());

        if (initializer != nullptr) {
            initializer->print(expandPrefix(prefix, is_left), false);
        }
    }

    auto VariableDefinition::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        const auto type_name = getValueType().getName();

        if (isMemberOfClass()) {
            genVisibility(getVisibility(), output);
        }

        if (isConstant()) {
            output << "const ";
        }

        output << type_name << ' ';

        if (isReference()) {
            output << '&';
        }

        output << getName() << " = ";

        if (initializer != nullptr) {
            output << *initializer;
        } else {
            output << type_name << "()";
        }
    }

    auto VariableDefinition::readType(FscParser::Variable_definitionContext *ctx) -> FscType
    {
        const auto type_name = ctx->children.at(4)->getText();
        return FscType{type_name};
    }

    auto VariableDefinition::readName(auto *ctx) -> std::string
    {
        return ctx->children.at(2)->getText();
    }

    auto VariableDefinition::readFlags(auto *ctx) -> VariableFlags
    {
        auto flags = VariableFlags{};
        auto attributes = ccl::as<FscParser::Variable_attributesContext *>(ctx->children.at(0));
        auto declaration_type = ctx->children.at(1)->getText();

        if (declaration_type == "let") {
            flags.constant = true;
        }

        if (auto visibility = attributes->visibility(); visibility != nullptr) {
            flags.visibility = VisibilityByStr.at(visibility->getText());
        }

        return flags;
    }

    auto VariableDefinition::readInitializer(Visitor &visitor, auto *ctx) -> NodePtr
    {
        const auto *expr = ccl::as<ExpressionContext *>(ctx->children.back());

        if (expr != nullptr) {
            return visitor.visitAsNode(ctx->children.back());
        }

        return nullptr;
    }
}// namespace fsc::ast
