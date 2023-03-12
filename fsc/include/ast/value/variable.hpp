#ifndef FSC_VARIABLE_HPP
#define FSC_VARIABLE_HPP

#include "ast/value/value.hpp"
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

    class Variable
      : public NodeWrapper<NodeType::VARIABLE, SemicolonNeed::NEED>
      , public std::enable_shared_from_this<Variable>
    {
    private:
        static inline constinit std::atomic<ccl::Id> variableUuid{0};

        std::string name{};
        ccl::Lazy<FscType> type;
        VariableFlags flags{};
        ccl::SharedPtr<Value> storedValue;
        ccl::Id uuid{variableUuid++};

    public:
        Variable(
            BasicContextPtr ctx, std::string variable_name, ccl::Lazy<FscType> &&fsc_type,
            VariableFlags variable_flags);

        auto analyze() -> AnalysisReport override;

        auto print(const std::string &prefix, bool is_left) const -> void override;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void override;

        auto memberize() noexcept -> void
        {
            flags.memberVariable = true;
        }

        auto setValue(ccl::SharedPtr<Value> new_value) -> void
        {
            storedValue = std::move(new_value);
        }

        [[nodiscard]] auto getUuid() const noexcept -> ccl::Id
        {
            return uuid;
        }

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getValueType() -> FscType final
        {
            return type.get();
        }

        [[nodiscard]] auto getValueType() const -> FscType
        {
            return type.get();
        }

        [[nodiscard]] auto getStoredValue() const -> ccl::SharedPtr<Value>
        {
            return storedValue;
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
