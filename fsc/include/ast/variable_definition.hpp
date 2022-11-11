#ifndef FSC_VARIABLE_DEFINITION_HPP
#define FSC_VARIABLE_DEFINITION_HPP

#include "ast/variable.hpp"

namespace fsc::ast {
    class VariableDefinition : public Variable {
        NodePtr initializer{};

    public:
        explicit VariableDefinition(VariableFlags flags_, std::string name_, const TypeId type_id_,
                                    NodePtr initializer_)
            : Variable{std::move(name_), type_id_, std::move(flags_), classof()},
              initializer{std::move(initializer_)}
        {}

        explicit VariableDefinition(VariableFlags flags_, std::string name_, const TypeId type_id_)
            : Variable{std::move(name_), type_id_, std::move(flags_), classof()}
        {}

        explicit VariableDefinition(VariableFlags flags_, std::string name_, NodePtr initializer_)
            : Variable{std::move(name_), initializer_->getValueType(), std::move(flags_),
                       classof()},
              initializer{std::move(initializer_)}
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        [[nodiscard]] auto toVariable() const -> const Variable &
        {
            return static_cast<const Variable &>(*this);
        }

        [[nodiscard]] constexpr static auto classof() noexcept -> NodeType
        {
            return NodeType::VARIABLE_DEFINITION;
        }
    };
}// namespace fsc::ast

#endif /* FSC_VARIABLE_DEFINITION_HPP */
