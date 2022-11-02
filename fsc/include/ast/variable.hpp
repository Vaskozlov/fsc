#ifndef FSC_VARIABLE_HPP
#define FSC_VARIABLE_HPP

#include "ast/basic_node.hpp"
#include "type/type.hpp"

namespace fsc::ast {
    class Variable : public Node {
        std::string name;
        TypeId typeId;

    public:
        Variable(std::string name_, const TypeId type_id_)
            : Node(classof()), name(std::move(name_)), typeId(type_id_)
        {}

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final
        {
            output.add(name);
        }

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
            return NodeType::VARIABLE;
        }
    };
}// namespace fsc::ast

#endif /* FSC_VARIABLE_HPP */
