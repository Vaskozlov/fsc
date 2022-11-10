#ifndef FSC_CLASS_HPP
#define FSC_CLASS_HPP

#include "ast/basic_node.hpp"
#include "ast/body.hpp"

namespace fsc::ast {
    class Class : public Body {
        ccl::Map<std::string, TypeId> constructionMemberVariables;
        std::string name;

    public:
        Class(std::string name_);

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        auto addNode(ccl::SharedPtr<Node> node) -> void final;

        [[nodiscard]] auto getName() const -> const std::string &
        {
            return name;
        }

        [[nodiscard]] constexpr static auto classof() noexcept -> NodeType
        {
            return NodeType::CLASS;
        }
    };
}// namespace fsc::ast

#endif /* FSC_CLASS_HPP */
