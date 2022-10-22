#ifndef FSC_FUNCTION_HPP
#define FSC_FUNCTION_HPP

#include "FscParser.h"
#include "FscVisitor.h"
#include "ast/node.hpp"
#include "builtin/types.hpp"
#include <functional>
#include <map>
#include <ranges>
#include <string>
#include <variant>

namespace fsc {
    enum struct ParameterCategory : size_t { IN, INOUT, OUT };
    const extern std::map<std::string, ParameterCategory, std::less<>> ParameterCategories;

    class FunctionArgument {
    public:
        friend constexpr auto operator==(const FunctionArgument &lhs, const size_t rhs) noexcept
        {
            return lhs.type == rhs;
        }

        friend constexpr auto operator==(const FunctionArgument &lhs,
                                         const FunctionArgument &rhs) noexcept
        {
            return lhs.type == rhs.type;
        }

        std::string name;
        size_t type;
        ParameterCategory category;
        std::shared_ptr<AstNode> initializer{nullptr};
    };

    [[nodiscrd]] inline auto createArgument(const FscValue &value) -> FunctionArgument
    {
        return FunctionArgument{{}, value.type, ParameterCategory::INOUT, nullptr};
    }


    [[nodiscrd]] inline auto createArgument(const size_t type) -> FunctionArgument
    {
        return FunctionArgument{{}, type, ParameterCategory::INOUT, nullptr};
    }

    class Function {
    private:
        using BuiltinFunction = std::function<FscValue(const std::vector<FunctionArgument> &)>;
        using FscFunction = std::shared_ptr<AstNode>;

        template<class... Ts>
        class Overload : public Ts... {
        public:
            using Ts::operator()...;
        };

        template<class... Ts>
        Overload(Ts...) -> Overload<Ts...>;

    public:
        explicit Function(const FscParser::FunctionContext *function_context, FscVisitor &visitor);

        Function(std::string name_, const size_t return_type_, BuiltinFunction builtin_function_,
                 std::vector<FunctionArgument> arguments_);

        auto operator==(const std::vector<FunctionArgument> &args) const
        {
            return arguments == args;
        }

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getReturnType() const noexcept -> size_t
        {
            return returnType;
        }

        [[nodiscard]] auto getArguments() const noexcept -> const std::vector<FunctionArgument> &
        {
            return arguments;
        }

        [[nodiscard]] auto invoke() const -> FscValue;

    private:
        auto setReturnType(const std::vector<antlr4::tree::ParseTree *> &children) -> void;
        auto processArguments(const FscParser::ParametersContext *parameters_context) -> void;

        static auto
        processArgument(const FscParser::Argument_definitionContext *argument_definition)
                -> FunctionArgument;

        std::string name;
        std::vector<FunctionArgument> arguments;
        size_t returnType{Auto::hash};
        std::variant<BuiltinFunction, FscFunction> body;
    };
}// namespace fsc

#endif /* FSC_FUNCTION_HPP */
