#ifndef FSC_VARIABLE_DEFINITION_HPP
#define FSC_VARIABLE_DEFINITION_HPP

#include "ast/value/variable.hpp"
#include "visibility.hpp"
#include "visitor.hpp"

namespace fsc::ast
{
    class VariableDefinition final
      : public NodeWrapper<NodeType::VARIABLE_DEFINITION, SemicolonNeed::NEED, Variable>
    {
    private:
        NodePtr initializer{};

    public:
        VariableDefinition(
            std::string variable_name, ccl::Lazy<FscType> &&fsc_type, VariableFlags variable_flags,
            NodePtr variable_initializer);

        VariableDefinition(
            std::string variable_name, FscType fsc_type, VariableFlags variable_flags,
            NodePtr variable_initializer);

        VariableDefinition(
            std::string variable_name, NodePtr variable_initializer, VariableFlags variable_flags);

        VariableDefinition(Visitor &visitor, VariableDefinitionContext *ctx);

        VariableDefinition(Visitor &visitor, AutoVariableDefinitionContext *ctx);

        auto analyze() -> void final;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;

        [[nodiscard]] auto toVariable() const -> const Variable &
        {
            return ccl::as<const Variable &>(*this);
        }

    private:
        static auto readType(FscParser::Variable_definitionContext *ctx) -> FscType;
        static auto readName(auto *ctx) -> std::string;
        static auto readFlags(auto *ctx) -> VariableFlags;
        static auto readInitializer(Visitor &visitor, auto *ctx) -> NodePtr;
    };
}// namespace fsc::ast

#endif /* FSC_VARIABLE_DEFINITION_HPP */
