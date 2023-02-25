#include "function/argument.hpp"

#include "ast/function/magic_methods_table.hpp"
#include "function/functions_holder.hpp"
#include "type/builtin_types.hpp"
#include "type/type.hpp"

#define BUILTIN_EMPTY_CONSTRUCTOR(REPR, TYPE, TEMPLATES, INFO)                                     \
    {                                                                                              \
        FscType{TYPE}, #REPR, "", FscType{TYPE}, {}, INFO, TEMPLATES,                              \
            fsc::ast::MagicFunctionType::INIT                                                      \
    }

namespace fsc
{
    using namespace ccl;
    using namespace ast;
    using namespace ast::magic;

    constexpr static auto BinaryOperatorInfo = FunctionInfo{
        .NOEXCEPT = true,
        .IS_METHOD = false,
        .CONSTANT_METHOD = false,
        .BUILTIN_FUNCTION = true,
        .HAVE_PARAMETER_PACK = false,
        .NODISCARD = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr static auto StringInfoForToNumeric = FunctionInfo{
        .NOEXCEPT = false,
        .IS_METHOD = true,
        .CONSTANT_METHOD = true,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr static auto GetSizeInfo = FunctionInfo{
        .NOEXCEPT = true,
        .IS_METHOD = true,
        .CONSTANT_METHOD = true,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr static auto OperatorAtInfo = FunctionInfo{
        .NOEXCEPT = false,
        .IS_METHOD = true,
        .CONSTANT_METHOD = false,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr static auto MathFunctionInfo = FunctionInfo{
        .NOEXCEPT = false,
        .IS_METHOD = false,
        .CONSTANT_METHOD = false,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    static auto initializeNumericTypes() -> void
    {
        FscBool::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);

        FscInt32::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
        FscInt64::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);

        FscUInt32::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
        FscUInt64::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);

        FscFloat32::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
        FscFloat64::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
    }

    static auto initializeString() -> void
    {
        FscChar::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
        FscString::initialize({.isTriviallyCopyable = false}, CreationType::DEFAULT);
    }

    static auto initializeTemplates() -> void
    {
        VectorType::initialize({.templatesParametersCount = 1}, CreationType::DEFAULT);
        FscTemplate1::initialize({}, CreationType::TEMPLATE_HIDE_NAME);
    }

    static auto initializeTypes() -> void
    {
        VoidType::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
        AutoType::initialize({.isTriviallyCopyable = false}, CreationType::DEFAULT);

        initializeNumericTypes();
        initializeTemplates();
        initializeString();
    }

    static auto constructBuiltinBinaryExpression(
        MagicFunctionType function_type,
        FscType return_type,
        FscType lhs,
        FscType rhs) -> Function
    {
        const auto left_argument = Argument{"lhs", lhs, ArgumentCategory::IN};
        const auto right_argument = Argument{"rhs", rhs, ArgumentCategory::IN};

        return Function{Void,        MagicToFscName[function_type],   "",
                        return_type, {left_argument, right_argument}, BinaryOperatorInfo};
    }

    static auto
        constructAllBuiltinOperators(FscType type, InitializerList<FscType> extra_conversion)
            -> Vector<Function>
    {
        auto add = constructBuiltinBinaryExpression(MagicFunctionType::ADD, type, type, type);

        auto sub = constructBuiltinBinaryExpression(MagicFunctionType::SUB, type, type, type);

        auto mul = constructBuiltinBinaryExpression(MagicFunctionType::MUL, type, type, type);

        auto div = constructBuiltinBinaryExpression(MagicFunctionType::DIV, type, type, type);

        auto less = constructBuiltinBinaryExpression(MagicFunctionType::LESS, Bool, type, type);

        auto less_eq =
            constructBuiltinBinaryExpression(MagicFunctionType::LESS_EQ, Bool, type, type);

        auto greater =
            constructBuiltinBinaryExpression(MagicFunctionType::GREATER, Bool, type, type);

        auto greater_eq =
            constructBuiltinBinaryExpression(MagicFunctionType::GREATER_EQ, Bool, type, type);

        auto equal = constructBuiltinBinaryExpression(MagicFunctionType::EQUAL, Bool, type, type);

        auto not_equal =
            constructBuiltinBinaryExpression(MagicFunctionType::NOT_EQUAL, Bool, type, type);

        auto assign = constructBuiltinBinaryExpression(MagicFunctionType::ASSIGN, type, type, type);

        auto empty_constructor = Function{type, type.getName(),     "", type,
                                          {},   BinaryOperatorInfo, {}, MagicFunctionType::INIT};

        auto operators = Vector<Function>{
            std::move(add),       std::move(sub),        std::move(mul),
            std::move(div),       std::move(less),       std::move(less_eq),
            std::move(greater),   std::move(greater_eq), std::move(equal),
            std::move(not_equal), std::move(assign),     std::move(empty_constructor)};

        operators.reserve(operators.size() + extra_conversion.size());

        for (auto from : extra_conversion) {
            operators.emplace_back(Function{
                type,
                type.getName(),
                "",
                type,
                {Argument{"value_to_copy", from, ArgumentCategory::IN}},
                BinaryOperatorInfo,
                {},
                MagicFunctionType::INIT});
        }

        if (!type.getName().contains('f')) {
            operators.emplace_back(
                constructBuiltinBinaryExpression(MagicFunctionType::MOD, type, type, type));
        }

        return operators;
    }

    auto initializeCompilerBuiltin() -> void
    {
        static bool initialized = false;

        if (initialized) {
            return;
        }

        initializeTypes();

        auto i32_operators =
            constructAllBuiltinOperators(Int32, {Int32, UInt32, UInt64, Int64, Float32, Float64});

        auto i64_operators =
            constructAllBuiltinOperators(Int64, {Int32, UInt32, UInt64, Int64, Float32, Float64});

        auto u32_operators =
            constructAllBuiltinOperators(UInt32, {Int32, UInt32, UInt64, Int64, Float32, Float64});

        auto u64_operators =
            constructAllBuiltinOperators(UInt64, {Int32, UInt32, UInt64, Int64, Float32, Float64});

        auto f32_operators =
            constructAllBuiltinOperators(Float32, {Int32, UInt32, UInt64, Int64, Float32, Float64});

        auto f64_operators =
            constructAllBuiltinOperators(Float64, {Int32, UInt32, UInt64, Int64, Float32, Float64});

        auto logical_and = Vector<Function>{
            {Void,
             "__logical_and__",
             "",
             Bool,
             {Argument{"lhs", Bool, ArgumentCategory::IN},
              Argument{"rhs", Bool, ArgumentCategory::IN}},
             BinaryOperatorInfo}};

        auto logical_or = Vector<Function>{
            {Void,
             "__logical_or__",
             "",
             Bool,
             {Argument{"lhs", Bool, ArgumentCategory::IN},
              Argument{"rhs", Bool, ArgumentCategory::IN}},
             BinaryOperatorInfo}};

        auto constructors = Vector<Function>{
            BUILTIN_EMPTY_CONSTRUCTOR(bool, Bool, {}, BinaryOperatorInfo),
            BUILTIN_EMPTY_CONSTRUCTOR(char, Char, {}, BinaryOperatorInfo),
            BUILTIN_EMPTY_CONSTRUCTOR(String, String, {}, BinaryOperatorInfo),
            BUILTIN_EMPTY_CONSTRUCTOR(Vector, VectorTemplate, {Template1}, BinaryOperatorInfo)};

        auto math_functions = Vector<Function>{
            {Void,
             "sqrt",
             "std::sqrt",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "sqrt",
             "std::sqrt",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "log2",
             "std::log2",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "log2",
             "std::log2",
             Float64,
             {Argument{"log2", Float64, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "log",
             "std::log",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "log",
             "std::log",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "trunc",
             "std::trunc",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "trunc",
             "std::trunc",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "floor",
             "std::floor",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "floor",
             "std::floor",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "ceil",
             "std::ceil",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "ceil",
             "std::ceil",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "round",
             "std::round",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "round",
             "std::round",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "abs",
             "std::abs",
             Int32,
             {Argument{"value", Int32, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "abs",
             "std::abs",
             Int64,
             {Argument{"value", Int64, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "abs",
             "std::abs",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             MathFunctionInfo},
            {Void,
             "abs",
             "std::abs",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             MathFunctionInfo}};

        auto input = Vector<Function>{
            {Void, "input", "", String, {}, FunctionInfo{.NOEXCEPT = false}},
            {Void,
             "input",
             "",
             String,
             {{"message", String, ArgumentCategory::IN}},
             FunctionInfo{
                 .NOEXCEPT = false, .CONSTEXPR = false, .VISIBILITY = Visibility::PUBLIC}}};

        auto output = Vector<Function>{
            {Void,
             "putchar",
             "std::putchar",
             Void,
             {{"value", Int32, ArgumentCategory::IN}},
             FunctionInfo{.NOEXCEPT = true, .CONSTEXPR = false, .VISIBILITY = Visibility::PUBLIC}},
            {Void,
             "print",
             "",
             Void,
             {{"fmt", String, ArgumentCategory::IN}},
             FunctionInfo{
                 .NOEXCEPT = true,
                 .BUILTIN_FUNCTION = true,
                 .HAVE_PARAMETER_PACK = true,
                 .CONSTEXPR = false,
                 .VISIBILITY = Visibility::PUBLIC},
             {}},
        };

        auto format = Vector<Function>{
            {Void,
             "format",
             "",
             Void,
             {Argument{"fmt", String, ArgumentCategory::IN}},
             FunctionInfo{
                 .NOEXCEPT = false,
                 .BUILTIN_FUNCTION = true,
                 .HAVE_PARAMETER_PACK = true,
                 .CONSTEXPR = false,
                 .VISIBILITY = Visibility::PUBLIC},
             {}}};

        auto string_methods = Vector<Function>{
            {String, "size", "", UInt64, {}, GetSizeInfo},
            {String, "toI32", "", Int32, {}, StringInfoForToNumeric},
            {String, "toI64", "", Int64, {}, StringInfoForToNumeric},
            {String, "toU64", "", UInt64, {}, StringInfoForToNumeric},
            {String, "toF32", "", Float32, {}, StringInfoForToNumeric},
            {String, "toF64", "", Float64, {}, StringInfoForToNumeric},
            {String,
             "at",
             "",
             Char,
             {Argument{"index", UInt64, ArgumentCategory::IN}},
             OperatorAtInfo}};

        auto vector_methods = Vector<Function>{
            {VectorTemplate,
             "Vector",
             "",
             VectorTemplate,
             {Argument{"value", Template1, ArgumentCategory::IN}},
             FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = false,
                 .BUILTIN_FUNCTION = true,
                 .HAVE_PARAMETER_PACK = true,
                 .CONSTEXPR = true,
                 .VISIBILITY = Visibility::PUBLIC},
             {Template1},
             MagicFunctionType::INIT},
            {VectorTemplate, "size", "", UInt64, {}, GetSizeInfo},
            {VectorTemplate,
             "push_back",
             "",
             Void,
             {Argument{"value", Template1, ArgumentCategory::IN}},
             FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = false,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = true,
                 .VISIBILITY = Visibility::PUBLIC}},
            {VectorTemplate,
             "at",
             "",
             Template1,
             {Argument{"index", UInt64, ArgumentCategory::IN}},
             OperatorAtInfo}};

        auto memory_allocation = Vector<Function>{
            {Void,
             "construct",
             "",
             Template1,
             {{"number", UInt32, ArgumentCategory::IN}},
             FunctionInfo{
                 .NOEXCEPT = false, .BUILTIN_FUNCTION = true, .VISIBILITY = Visibility::PUBLIC},
             {Template1}}};

        func::Functions.registerFunctions(
            {i32_operators, i64_operators, u32_operators, u64_operators, f32_operators,
             f64_operators, math_functions, constructors, logical_and, logical_or, input, output,
             format, vector_methods, string_methods, memory_allocation});

        initialized = true;
    }

    namespace func
    {
        FunctionsHolder Functions{};
    }
}// namespace fsc
