#ifndef FSC_FUNCTION_HPP
#define FSC_FUNCTION_HPP

#include "FscParser.h"
#include "FscVisitor.h"
#include "builtin/types.hpp"
#include <map>
#include <ranges>
#include <string>
#include <variant>

namespace fsc {
    enum struct ParameterCategory : size_t { IN, INOUT, OUT };

    const extern std::map<std::string, ParameterCategory> ParameterCategories;

    struct FunctionArgument {
        auto operator==(size_t other) const noexcept
        {
            return type == other;
        }

        auto operator==(const FunctionArgument &other) const noexcept
        {
            return type == other.type;
        }

        std::string name;
        size_t type;
        ParameterCategory category;
        FscParser::ExprContext *default_initializer{nullptr};
    };

    inline auto createArgument(const FscValue &value) -> FunctionArgument
    {
        return FunctionArgument{{}, value.type, ParameterCategory::INOUT, nullptr};
    }

    class Function {
    private:
        using BuiltinFunction = FscValue (*)(const std::vector<FunctionArgument> &);
        using FscFunction = FscParser::BodyContext *;

        template<class... Ts>
        struct overload : Ts... {
            using Ts::operator()...;
        };

        template<class... Ts>
        overload(Ts...) -> overload<Ts...>;

    public:
        explicit Function(FscParser::FunctionContext *function_context);

        Function(std::string name_, size_t return_type_, BuiltinFunction builtin_function_,
                 std::vector<FunctionArgument> arguments_);

        auto operator==(const std::vector<FunctionArgument> &args) const
        {
            return arguments == args;
        }

        auto getName() const noexcept -> const std::string &
        {
            return name;
        }

        auto getReturnType() const noexcept -> size_t
        {
            return return_type;
        }

        auto getArguments() const noexcept -> const std::vector<FunctionArgument> &
        {
            return arguments;
        }

        auto invoke(FscVisitor &visitor) -> FscValue;

    private:
        auto setReturnType(const std::vector<antlr4::tree::ParseTree *> &children) -> void;
        auto processArguments(FscParser::ParametersContext *parameters_context) -> void;

        static auto processArgument(FscParser::Argument_definitionContext *argument_definition)
                -> FunctionArgument;

        std::string name;
        std::vector<FunctionArgument> arguments;
        size_t return_type{Auto::hash};
        std::variant<BuiltinFunction, FscFunction> body;
    };
}// namespace fsc

#endif /* FSC_FUNCTION_HPP */
