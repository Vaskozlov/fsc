#include "functions.hpp"
#include "stack.hpp"

namespace fsc {
    FunctionsHolder::FunctionsHolder(const std::initializer_list<Function> &functions_)
    {
        for (const auto &function : functions_) {
            functions[function.getName()].push_back(function);
        }
    }

    auto FunctionsHolder::add(const FscParser::FunctionContext *function_context) -> Function &
    {
        auto function = Function(function_context);
        const auto name = function.getName();

        return functions[name].emplace_back(std::move(function));
    }

    auto FunctionsHolder::get(const std::string &name,
                              const std::vector<FunctionArgument> &arguments) -> const Function &
    {
        for (const auto &possible_alternatives = functions[name];
             const auto &function : possible_alternatives) {
            if (function.getArguments() == arguments) {
                return function;
            }
        }

        throw std::runtime_error("No matching function to call");
    }

    static auto constructF32FromI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto value = ProgramsStack.get(arguments[0].name);
        return {static_cast<float>(std::any_cast<int32_t>(value)), Int32::hash};
    }

    const static auto constructF32FromI32Arguments = {
            FunctionArgument{"value", Int32::hash, ParameterCategory::IN, nullptr}};

    static auto constructF32FromI64(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto value = ProgramsStack.get(arguments[0].name);
        return {static_cast<float>(std::any_cast<int64_t>(value)), Int64::hash};
    }

    const static auto constructF32FromI64Arguments = {
            FunctionArgument{"value", Int64::hash, ParameterCategory::IN, nullptr}};

    static auto constructF64FromI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto value = ProgramsStack.get(arguments[0].name);
        return {static_cast<double>(std::any_cast<int32_t>(value)), Int32::hash};
    }

    const static auto constructF64FromI32Arguments = {
            FunctionArgument{"value", Int32::hash, ParameterCategory::IN, nullptr}};

    static auto constructF64FromI64(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto value = ProgramsStack.get(arguments[0].name);
        return {static_cast<double>(std::any_cast<int64_t>(value)), Int64::hash};
    }

    const static auto constructF64FromI64Arguments = {
            FunctionArgument{"value", Int64::hash, ParameterCategory::IN, nullptr}};

    static auto sumI32AndF32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto lhs = ProgramsStack.get(arguments[0].name).value.value;
        auto rhs = ProgramsStack.get(arguments[1].name).value.value;

        return {static_cast<float>(std::any_cast<int32_t>(lhs)) + std::any_cast<float>(rhs),
                Float::hash};
    }

    const static auto sumI32AndF32Arguments = {
            FunctionArgument{"lhs", Int32::hash, ParameterCategory::IN, nullptr},
            FunctionArgument{"rhs", Float::hash, ParameterCategory::IN, nullptr}};

    static auto sumI32AndI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto lhs = ProgramsStack.get(arguments[0].name).value.value;
        auto rhs = ProgramsStack.get(arguments[1].name).value.value;

        return {std::any_cast<int32_t>(lhs) + std::any_cast<int32_t>(rhs), Int32::hash};
    }

    const static auto sumI32AndI32Arguments = {
            FunctionArgument{"lhs", Int32::hash, ParameterCategory::IN, nullptr},
            FunctionArgument{"rhs", Int32::hash, ParameterCategory::IN, nullptr}};

    static auto mulI32AndI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto lhs = ProgramsStack.get(arguments[0].name).value.value;
        auto rhs = ProgramsStack.get(arguments[1].name).value.value;

        return {std::any_cast<int32_t>(lhs) * std::any_cast<int32_t>(rhs), Int32::hash};
    }

    const static auto mulI32AndI32Arguments = {
            FunctionArgument{"lhs", Int32::hash, ParameterCategory::IN, nullptr},
            FunctionArgument{"rhs", Int32::hash, ParameterCategory::IN, nullptr}};

    static auto mulF32AndF32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto lhs = ProgramsStack.get(arguments[0].name).value.value;
        auto rhs = ProgramsStack.get(arguments[1].name).value.value;

        return {std::any_cast<float>(lhs) * std::any_cast<float>(rhs), Float::hash};
    }

    const static auto mulF32AndF32Arguments = {
            FunctionArgument{"lhs", Float::hash, ParameterCategory::IN, nullptr},
            FunctionArgument{"rhs", Float::hash, ParameterCategory::IN, nullptr}};

    FunctionsHolder Functions{
            Function{"f32", Float::hash, constructF32FromI32, constructF32FromI32Arguments},
            Function{"f32", Float::hash, constructF32FromI64, constructF32FromI64Arguments},
            Function{"f64", Float::hash, constructF64FromI32, constructF64FromI32Arguments},
            Function{"f64", Float::hash, constructF64FromI64, constructF64FromI64Arguments},
            Function{"__add__", Float::hash, sumI32AndF32, sumI32AndF32Arguments},
            Function{"__add__", Int32::hash, sumI32AndI32, sumI32AndI32Arguments},
            Function{"__mul__", Int32::hash, mulI32AndI32, mulI32AndI32Arguments},
            Function{"__mul__", Float::hash, mulF32AndF32, mulF32AndF32Arguments}};
}// namespace fsc
