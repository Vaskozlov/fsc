#ifndef FSC_VARIABLE_HPP
#define FSC_VARIABLE_HPP

#include "ast/basic_node.hpp"
#include "visibility.hpp"

namespace fsc::ast
{
    struct VariableFlags
    {
        Visibility visibility = Visibility::FILE_PRIVATE;
        bool constant = false;
        bool reference = false;
        bool memberVariable = false;
        bool compileTimeAvailable = false;
    };

    class Variable : public NodeWrapper<NodeType::VARIABLE, SemicolonNeed::NEED>
    {
        std::string name{};
        ccl::Id typeId{};
        VariableFlags flags{};

    public:
        Variable(std::string variable_name, ccl::Id type_id, VariableFlags variable_flags);

        auto print(const std::string &prefix, bool is_left) const -> void override;

        auto codeGen(gen::CodeGenerator &output) const -> void override;

        auto memberizeVariable() noexcept -> void
        {
            flags.memberVariable = true;
        }

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getValueType() const -> ccl::Id final
        {
            return typeId;
        }

        [[nodiscard]] auto isMemberOfClass() const noexcept -> bool
        {
            return flags.memberVariable;
        }

        [[nodiscard]] auto isConstant() const noexcept -> bool
        {
            return flags.constant;
        }

        [[nodiscard]] auto getVisibility() const noexcept -> Visibility
        {
            return flags.visibility;
        }
    };
}// namespace fsc::ast

#endif /* FSC_VARIABLE_HPP */
