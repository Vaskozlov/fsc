#include "functions.hpp"
#include "stack.hpp"

namespace fsc {
    FunctionsHolder::FunctionsHolder(const std::initializer_list<Function> &functions_)
    {
        for (const auto &function : functions_) {
            functions[function.getName()].push_back(function);
        }
    }

    auto FunctionsHolder::add(const FscParser::FunctionContext *const function_context,
                              FscVisitor &visitor) -> Function &
    {
        auto function = Function(function_context, visitor);
        const auto name = function.getName();

        return functions[name].emplace_back(std::move(function));
    }

    auto FunctionsHolder::get(const std::string &name,
                              const std::vector<FunctionArgument> &arguments) -> const Function &
    {
        for (const auto &possible_alternatives = functions.at(name);
             const auto &function : possible_alternatives) {
            if (function.getArguments() == arguments) {
                return function;
            }
        }

        throw std::runtime_error("No matching function to call");
    }

    static auto constructF32FromI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        const auto &value = ProgramsStack.get(arguments[0].name).value.value;
        return FscValue{static_cast<float32>(std::any_cast<int32_t>(value))};
    }

    static auto constructF32FromI64(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        const auto &value = ProgramsStack.get(arguments[0].name).value.value;
        return FscValue{static_cast<float32>(std::any_cast<int64_t>(value))};
    }

    static auto constructF64FromI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        const auto &value = ProgramsStack.get(arguments[0].name).value.value;
        return FscValue{static_cast<float64>(std::any_cast<int32_t>(value))};
    }

    static auto constructF64FromI64(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        const auto &value = ProgramsStack.get(arguments[0].name).value.value;
        return FscValue{static_cast<float64>(std::any_cast<int64_t>(value))};
    }

    static auto sumI32AndI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        const auto &lhs = ProgramsStack.get(arguments[0].name).value.value;
        const auto &rhs = ProgramsStack.get(arguments[1].name).value.value;

        return FscValue{std::any_cast<int32_t>(lhs) + std::any_cast<int32_t>(rhs)};
    }

    static auto sumF32AndF32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        const auto &lhs = ProgramsStack.get(arguments[0].name).value.value;
        const auto &rhs = ProgramsStack.get(arguments[1].name).value.value;

        return FscValue{std::any_cast<float32>(lhs) + std::any_cast<float32>(rhs)};
    }

    static auto mulI32AndI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        const auto &lhs = ProgramsStack.get(arguments[0].name).value.value;
        const auto &rhs = ProgramsStack.get(arguments[1].name).value.value;

        return FscValue{std::any_cast<int32_t>(lhs) * std::any_cast<int32_t>(rhs)};
    }

    static auto mulF32AndF32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        const auto &lhs = ProgramsStack.get(arguments[0].name).value.value;
        const auto &rhs = ProgramsStack.get(arguments[1].name).value.value;

        return FscValue{std::any_cast<float32>(lhs) * std::any_cast<float32>(rhs)};
    }

    const static auto constructF32FromI32Arguments = {
            FunctionArgument{"value", Int32::hash, ParameterCategory::IN}};

    const static auto constructF32FromI64Arguments = {
            FunctionArgument{"value", Int64::hash, ParameterCategory::IN}};

    const static auto constructF64FromI32Arguments = {
            FunctionArgument{"value", Int32::hash, ParameterCategory::IN}};

    const static auto constructF64FromI64Arguments = {
            FunctionArgument{"value", Int64::hash, ParameterCategory::IN}};

    const static auto sumI32AndI32Arguments = {
            FunctionArgument{"lhs", Int32::hash, ParameterCategory::IN},
            FunctionArgument{"rhs", Int32::hash, ParameterCategory::IN}};

    const static auto sumF32AndF32Arguments = {
            FunctionArgument{"lhs", Float32::hash, ParameterCategory::IN},
            FunctionArgument{"rhs", Float32::hash, ParameterCategory::IN}};

    const static auto mulI32AndI32Arguments = {
            FunctionArgument{"lhs", Int32::hash, ParameterCategory::IN},
            FunctionArgument{"rhs", Int32::hash, ParameterCategory::IN}};

    const static auto mulF32AndF32Arguments = {
            FunctionArgument{"lhs", Float32::hash, ParameterCategory::IN},
            FunctionArgument{"rhs", Float32::hash, ParameterCategory::IN}};

    FunctionsHolder Functions{
            Function{"f32", Float32::hash, constructF32FromI32, constructF32FromI32Arguments},
            Function{"f32", Float32::hash, constructF32FromI64, constructF32FromI64Arguments},
            Function{"f64", Float64::hash, constructF64FromI32, constructF64FromI32Arguments},
            Function{"f64", Float64::hash, constructF64FromI64, constructF64FromI64Arguments},
            Function{"__add__", Int32::hash, sumI32AndI32, sumI32AndI32Arguments},
            Function{"__add__", Float32::hash, sumF32AndF32, sumF32AndF32Arguments},
            Function{"__mul__", Int32::hash, mulI32AndI32, mulI32AndI32Arguments},
            Function{"__mul__", Float32::hash, mulF32AndF32, mulF32AndF32Arguments}};
}// namespace fsc
