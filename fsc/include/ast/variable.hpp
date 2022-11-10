#ifndef FSC_VARIABLE_HPP
#define FSC_VARIABLE_HPP

#include "ast/basic_node.hpp"
#include "visibility.hpp"

namespace fsc::ast {
    struct VariableFlags {
        bool constant : 1 = false;
        bool reference : 1 = false;
        bool memberVariable = false;
        bool compileTimeAvailable : 1 = false;
    };

    class Variable : public Node {
        std::string name;
        TypeId typeId;
        VariableFlags flags;

    public:
        Variable() = default;

        Variable(std::string name_, TypeId type_id_, VariableFlags flags_,
                 TypeId type_of_node_ = classof())
            : Node(type_of_node_), name(std::move(name_)), typeId(type_id_),
              flags(std::move(flags_))
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void override;

        auto codeGen(gen::CodeGenerator &output) const -> void override;

        [[nodiscard]] auto getName() const -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getValueType() const noexcept -> TypeId final
        {
            return typeId;
        }

        [[nodiscard]] constexpr static auto classof() noexcept -> NodeType
        {
            return NodeType::VARIABLE;
        }
    };
}// namespace fsc::ast

#endif /* FSC_VARIABLE_HPP */
