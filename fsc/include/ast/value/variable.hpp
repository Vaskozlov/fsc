#ifndef FSC_VARIABLE_HPP
#define FSC_VARIABLE_HPP

#include "ast/basic_node.hpp"
#include "type/type.hpp"
#include "visibility.hpp"
#include <ccl/lazy.hpp>

namespace fsc::ast
{
    struct VariableFlags
    {
        Visibility visibility{Visibility::FILE_PRIVATE};
        bool constant{false};
        bool reference{false};
        bool memberVariable{false};
        bool compileTimeAvailable{false};
    };

    class Variable : public NodeWrapper<NodeType::VARIABLE, SemicolonNeed::NEED>
    {
    private:
        std::string name{};
        ccl::Lazy<FscType> type;
        VariableFlags flags{};

    public:
        Variable(
            std::string variable_name, ccl::Lazy<FscType> &&fsc_type, VariableFlags variable_flags);

        auto analyze() -> void override;

        auto print(const std::string &prefix, bool is_left) const -> void override;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void override;

        auto memberize() noexcept -> void
        {
            flags.memberVariable = true;
        }

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getValueType() -> FscType final
        {
            return type.get();
        }

        [[nodiscard]] auto isMemberOfClass() const noexcept -> bool
        {
            return flags.memberVariable;
        }

        [[nodiscard]] auto isConstant() const noexcept -> bool
        {
            return flags.constant;
        }

        [[nodiscard]] auto isReference() const noexcept -> bool
        {
            return flags.reference;
        }

        [[nodiscard]] auto getVisibility() const noexcept -> Visibility
        {
            return flags.visibility;
        }
    };
}// namespace fsc::ast

#endif /* FSC_VARIABLE_HPP */
