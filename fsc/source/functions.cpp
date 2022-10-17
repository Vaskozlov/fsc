#include "functions.hpp"
#include "stack.hpp"

namespace fsc {
    auto constructF32FromI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto value = ProgramsStack.get(arguments[0].name);
        return {static_cast<float>(std::any_cast<int32_t>(value)), Int32::hash};
    }

    static auto constructF32FromI32Arguments = std::vector<FunctionArgument>{
            FunctionArgument{"value", Int32::hash, ParameterCategory::IN, nullptr}};

    auto constructF32FromI64(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto value = ProgramsStack.get(arguments[0].name);
        return {static_cast<float>(std::any_cast<int64_t>(value)), Int64::hash};
    }

    static auto constructF32FromI64Arguments = std::vector<FunctionArgument>{
            FunctionArgument{"value", Int64::hash, ParameterCategory::IN, nullptr}};

    auto constructF64FromI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto value = ProgramsStack.get(arguments[0].name);
        return {static_cast<double>(std::any_cast<int32_t>(value)), Int32::hash};
    }

    static auto constructF64FromI32Arguments = std::vector<FunctionArgument>{
            FunctionArgument{"value", Int32::hash, ParameterCategory::IN, nullptr}};

    auto constructF64FromI64(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto value = ProgramsStack.get(arguments[0].name);
        return {static_cast<double>(std::any_cast<int64_t>(value)), Int64::hash};
    }

    static auto constructF64FromI64Arguments = std::vector<FunctionArgument>{
            FunctionArgument{"value", Int64::hash, ParameterCategory::IN, nullptr}};

    auto sumI32AndF32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto lhs = ProgramsStack.get(arguments[0].name).value.value;
        auto rhs = ProgramsStack.get(arguments[1].name).value.value;

        return {static_cast<float>(std::any_cast<int32_t>(lhs)) + std::any_cast<float>(rhs),
                Float::hash};
    }

    static auto sumI32AndF32Arguments = std::vector<FunctionArgument>{
            FunctionArgument{"lhs", Int32::hash, ParameterCategory::IN, nullptr},
            FunctionArgument{"rhs", Float::hash, ParameterCategory::IN, nullptr}};

    auto sumI32AndI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto lhs = ProgramsStack.get(arguments[0].name).value.value;
        auto rhs = ProgramsStack.get(arguments[1].name).value.value;

        return {std::any_cast<int32_t>(lhs) + std::any_cast<int32_t>(rhs),
                Int32::hash};
    }

    static auto sumI32AndI32Arguments = std::vector<FunctionArgument>{
            FunctionArgument{"lhs", Int32::hash, ParameterCategory::IN, nullptr},
            FunctionArgument{"rhs", Int32::hash, ParameterCategory::IN, nullptr}};

    auto mulI32AndI32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto lhs = ProgramsStack.get(arguments[0].name).value.value;
        auto rhs = ProgramsStack.get(arguments[1].name).value.value;

        return {std::any_cast<int32_t>(lhs) * std::any_cast<int32_t>(rhs),
                Int32::hash};
    }

    static auto mulI32AndI32Arguments = std::vector<FunctionArgument>{
            FunctionArgument{"lhs", Int32::hash, ParameterCategory::IN, nullptr},
            FunctionArgument{"rhs", Int32::hash, ParameterCategory::IN, nullptr}};

    auto mulF32AndF32(const std::vector<FunctionArgument> &arguments) -> FscValue
    {
        auto lhs = ProgramsStack.get(arguments[0].name).value.value;
        auto rhs = ProgramsStack.get(arguments[1].name).value.value;

        return {std::any_cast<float>(lhs) * std::any_cast<float>(rhs),
                Float::hash};
    }

    static auto mulF32AndF32Arguments = std::vector<FunctionArgument>{
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
