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
        BasicContextPtr ctx)
      : VariableDefinition{
            std::move(variable_name), toLazy([variable_initializer, ctx]() {
                try {
                    return variable_initializer->getValueType();
                } catch (const FscException &e) {
                    GlobalVisitor->throwError(ctx, e.what());
                }
            }),
            variable_flags, std::move(variable_initializer)}
    {}

    VariableDefinition::VariableDefinition(VariableDefinitionContext *ctx)
      : VariableDefinition{readName(ctx), Lazy{readType(ctx)}, readFlags(ctx), readInitializer(ctx)}
    {}

    VariableDefinition::VariableDefinition(AutoVariableDefinitionContext *ctx)
      : VariableDefinition{readName(ctx), readInitializer(ctx), readFlags(ctx), ctx}
    {}

    auto VariableDefinition::analyze() -> AnalysisReport
    {
        if (initializer == nullptr) {
            return {};
        }

        const auto value_type = getValueType();
        const auto initializer_type = initializer->getValueType();

        if (value_type != initializer_type) {
            GlobalVisitor->throwError(
                initializer->getContext().value(),
                "unable to assign variable, because type of variable does not match with the "
                "initializer return type");
        }

        return initializer->analyze();
    }

    auto VariableDefinition::optimize(OptimizationLevel level) -> void
    {
        if (initializer != nullptr) {
            initializer->optimize(level);
        }
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

        flags.constant = declaration_type == "let";
        
        if (auto visibility = attributes->visibility(); visibility != nullptr) {
            flags.visibility = VisibilityByStr.at(visibility->getText());
        }

        return flags;
    }

    auto VariableDefinition::readInitializer(auto *ctx) -> NodePtr
    {
        const auto *expr = ccl::as<ExpressionContext *>(ctx->children.back());

        if (expr != nullptr) {
            return GlobalVisitor->visitAsNode(ctx->children.back());
        }

        return nullptr;
    }
}// namespace fsc::ast
