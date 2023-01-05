#include "ast/value/variable_definition.hpp"
#include "type/type.hpp"
#include "visibility.hpp"
#include "visitor.hpp"

namespace fsc::ast
{
    using namespace std::string_view_literals;

    VariableDefinition::VariableDefinition(
        std::string variable_name, VariableFlags variable_flags, ccl::Id type_id,
        NodePtr variable_initializer)
      : NodeWrapper{std::move(variable_name), type_id, variable_flags}
      , initializer{std::move(variable_initializer)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::VARIABLE_DEFINITION);
    }

    VariableDefinition::VariableDefinition(
        std::string variable_name, VariableFlags variable_flags, NodePtr variable_initializer)
      : VariableDefinition{
            std::move(variable_name), variable_flags, variable_initializer->getValueType(),
            std::move(variable_initializer)}
    {}

    VariableDefinition::VariableDefinition(
        Visitor &visitor, FscParser::Variable_definitionContext *ctx)
      : VariableDefinition{
            readName(ctx), readFlags(ctx), readType(ctx), readInitializer(visitor, ctx)}
    {}

    VariableDefinition::VariableDefinition(
        Visitor &visitor, FscParser::Auto_variable_definitionContext *ctx)
      : VariableDefinition{readName(ctx), readFlags(ctx), readInitializer(visitor, ctx)}
    {}

    auto VariableDefinition::analyze() const -> void
    {
        if (initializer != nullptr && getValueType() != initializer->getValueType()) {
            throw std::runtime_error(
                "unable to assign variable, because type of variable does not match with the "
                "initializer return type");
        }

        if (initializer != nullptr) {
            initializer->analyze();
        }
    }

    auto VariableDefinition::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Definition of {}\n", getPrintingPrefix(prefix, is_left), getName());

        if (initializer != nullptr) {
            initializer->print(expandPrefix(prefix, is_left), false);
        }
    }

    auto VariableDefinition::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        const auto type_name = FscType::getTypeName(getValueType());

        if (isMemberOfClass()) {
            genVisibility(getVisibility(), output);
        }

        if (isConstant()) {
            output << "const ";
        }

        output << "auto ";

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

    auto VariableDefinition::readType(FscParser::Variable_definitionContext *ctx) -> ccl::Id
    {
        const auto type_name = ctx->children.at(4)->getText();
        return FscType::getTypeId(type_name);
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
        if (auto *expr = ccl::as<FscParser::ExprContext *>(ctx->children.back()); expr != nullptr) {
            return visitor.visitAsNode(ctx->children.back());
        }

        return nullptr;
    }
}// namespace fsc::ast
