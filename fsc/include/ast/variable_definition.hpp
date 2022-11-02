#ifndef FSC_VARIABLE_DEFINITION_HPP
#define FSC_VARIABLE_DEFINITION_HPP

#include "ast/basic_node.hpp"

namespace fsc::ast {
    class VariableDefinition : public Node {
        std::string name;
        std::optional<std::shared_ptr<Node>> initializer{std::nullopt};
        TypeId typeId;

    public:
        explicit VariableDefinition(std::string name_, const TypeId type_id_,
                                    std::shared_ptr<Node> initializer_)
            : Node(classof()), name(std::move(name_)), initializer(std::move(initializer_)),
              typeId(type_id_)
        {}

        explicit VariableDefinition(std::string name_, const TypeId type_id_)
            : Node(classof()), name(std::move(name_)), typeId(type_id_)
        {}

        explicit VariableDefinition(std::string name_, std::shared_ptr<Node> initializer_)
            : Node(classof()), name(std::move(name_)), initializer(std::move(initializer_)),
              typeId((*initializer)->getValueType())
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        [[nodiscard]] auto getName() const -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getValueType() const noexcept -> TypeId final
        {
            return typeId;
        }

        [[nodiscard]] static auto classof() noexcept -> NodeType
        {
            return NodeType::VARIABLE_DEFINITION;
        }
    };
}// namespace fsc::ast

#endif /* FSC_VARIABLE_DEFINITION_HPP */
