#include "function/argument.hpp"

#include "function/functions_holder.hpp"
#include "type/builtin_types.hpp"
#include "type/type.hpp"

#define BUILTIN_BINARY_FUNCTION(NAME, RESULT, LHS, RHS, INFO)                                      \
    {                                                                                              \
        Void, NAME, FscType{RESULT},                                                               \
            {                                                                                      \
                {"lhs", FscType{LHS}, ArgumentCategory::IN},                                       \
                {"rhs", FscType{RHS}, ArgumentCategory::IN},                                       \
            },                                                                                     \
            INFO                                                                                   \
    }

#define BUILTIN_ADD(RESULT, LHS, RHS, INFO)                                                        \
    BUILTIN_BINARY_FUNCTION("__add__", RESULT, LHS, RHS, INFO)
#define BUILTIN_SUB(RESULT, LHS, RHS, INFO)                                                        \
    BUILTIN_BINARY_FUNCTION("__sub__", RESULT, LHS, RHS, INFO)
#define BUILTIN_MUL(RESULT, LHS, RHS, INFO)                                                        \
    BUILTIN_BINARY_FUNCTION("__mul__", RESULT, LHS, RHS, INFO)
#define BUILTIN_DIV(RESULT, LHS, RHS, INFO)                                                        \
    BUILTIN_BINARY_FUNCTION("__div__", RESULT, LHS, RHS, INFO)
#define BUILTIN_LOGICAL_AND(RESULT, LHS, RHS, INFO)                                                \
    BUILTIN_BINARY_FUNCTION("__logical_and__", RESULT, LHS, RHS, INFO)
#define BUILTIN_LOGICAL_OR(RESULT, LHS, RHS, INFO)                                                 \
    BUILTIN_BINARY_FUNCTION("__logical_or__", RESULT, LHS, RHS, INFO)
#define BUILTIN_EQUAL(RESULT, LHS, RHS, INFO)                                                      \
    BUILTIN_BINARY_FUNCTION("__equal__", RESULT, LHS, RHS, INFO)
#define BUILTIN_NOT_EQUAL(RESULT, LHS, RHS, INFO)                                                  \
    BUILTIN_BINARY_FUNCTION("__not_equal__", RESULT, LHS, RHS, INFO)

#define BUILTIN_LESS(RESULT, LHS, RHS, INFO)                                                       \
    BUILTIN_BINARY_FUNCTION("__less__", RESULT, LHS, RHS, INFO)
#define BUILTIN_GREATER(RESULT, LHS, RHS, INFO)                                                    \
    BUILTIN_BINARY_FUNCTION("__greater__", RESULT, LHS, RHS, INFO)
#define BUILTIN_LESS_EQ(RESULT, LHS, RHS, INFO)                                                    \
    BUILTIN_BINARY_FUNCTION("__less_eq__", RESULT, LHS, RHS, INFO)
#define BUILTIN_GREATER_EQ(RESULT, LHS, RHS, INFO)                                                 \
    BUILTIN_BINARY_FUNCTION("__greater_eq__", RESULT, LHS, RHS, INFO)

#define BUILTIN_ASSIGN(RESULT, LHS, RHS, INFO)                                                     \
    {                                                                                              \
        Void, "__copy__", FscType{RESULT},                                                         \
            {                                                                                      \
                {"lhs", FscType{LHS}, ArgumentCategory::OUT},                                      \
                {"rhs", FscType{RHS}, ArgumentCategory::IN},                                       \
            },                                                                                     \
            INFO                                                                                   \
    }

#define BUILTIN_CONVERT(REPR, TO, FROM, INFO)                                                      \
    {                                                                                              \
        Void, #REPR, FscType{TO}, {{"value", FscType{FROM}}}, INFO                                 \
    }

#define BUILTIN_EMPTY_CONSTRUCTOR(REPR, TYPE, TEMPLATES, INFO)                                     \
    {                                                                                              \
        FscType{TYPE}, #REPR, FscType{TYPE}, {}, INFO, TEMPLATES,                                  \
            fsc::ast::MagicFunctionType::INIT                                                      \
    }

namespace fsc
{
    using namespace ccl;

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

    auto initializeCompilerBuiltin() -> void
    {
        static bool initialized = false;

        if (initialized) {
            return;
        }

        initializeTypes();
        constexpr auto info_for_binary_expressions = ast::FunctionInfo{
            .NOEXCEPT = true,
            .IS_METHOD = false,
            .CONSTANT_METHOD = false,
            .BUILTIN_FUNCTION = true,
            .HAVE_PARAMETER_PACK = false,
            .NODISCARD = true,
            .CONSTEXPR = true,
            .VISIBILITY = Visibility::PUBLIC};

        auto AddFunctions = Vector<ast::Function>{
            BUILTIN_ADD(Int32, Int32, Int32, info_for_binary_expressions),
            BUILTIN_ADD(Int64, Int64, Int64, info_for_binary_expressions),
            BUILTIN_ADD(Float32, Float32, Float32, info_for_binary_expressions),
            BUILTIN_ADD(Float64, Float64, Float64, info_for_binary_expressions)};

        auto SubFunctions = Vector<ast::Function>{
            BUILTIN_SUB(Int32, Int32, Int32, info_for_binary_expressions),
            BUILTIN_SUB(Int64, Int64, Int64, info_for_binary_expressions),
            BUILTIN_SUB(Float32, Float32, Float32, info_for_binary_expressions),
            BUILTIN_SUB(Float64, Float64, Float64, info_for_binary_expressions)};

        auto MulFunctions = Vector<ast::Function>{
            BUILTIN_MUL(Int32, Int32, Int32, info_for_binary_expressions),
            BUILTIN_MUL(Int64, Int64, Int64, info_for_binary_expressions),
            BUILTIN_MUL(Float32, Float32, Float32, info_for_binary_expressions),
            BUILTIN_MUL(Float64, Float64, Float64, info_for_binary_expressions),
        };

        // TODO: check zero division exception
        auto DivFunctions = Vector<ast::Function>{
            BUILTIN_DIV(Int32, Int32, Int32, info_for_binary_expressions),
            BUILTIN_DIV(Int64, Int64, Int64, info_for_binary_expressions),
            BUILTIN_DIV(Float32, Float32, Float32, info_for_binary_expressions),
            BUILTIN_DIV(Float64, Float64, Float64, info_for_binary_expressions),
        };

        auto LessFunctions = Vector<ast::Function>{
            BUILTIN_LESS(Bool, Int32, Int32, info_for_binary_expressions),
            BUILTIN_LESS(Bool, Int64, Int64, info_for_binary_expressions),
            BUILTIN_LESS(Bool, Float32, Float32, info_for_binary_expressions),
            BUILTIN_LESS(Bool, Float64, Float64, info_for_binary_expressions),
            BUILTIN_LESS(Bool, String, String, info_for_binary_expressions),
        };

        auto GreaterFunctions = Vector<ast::Function>{
            BUILTIN_GREATER(Bool, Int32, Int32, info_for_binary_expressions),
            BUILTIN_GREATER(Bool, Int64, Int64, info_for_binary_expressions),
            BUILTIN_GREATER(Bool, Float32, Float32, info_for_binary_expressions),
            BUILTIN_GREATER(Bool, Float64, Float64, info_for_binary_expressions),
            BUILTIN_GREATER(Bool, String, String, info_for_binary_expressions),
        };

        auto LessEqFunctions = Vector<ast::Function>{
            BUILTIN_LESS_EQ(Bool, Int32, Int32, info_for_binary_expressions),
            BUILTIN_LESS_EQ(Bool, Int64, Int64, info_for_binary_expressions),
            BUILTIN_LESS_EQ(Bool, Float32, Float32, info_for_binary_expressions),
            BUILTIN_LESS_EQ(Bool, Float64, Float64, info_for_binary_expressions),
            BUILTIN_LESS_EQ(Bool, String, String, info_for_binary_expressions),
        };

        auto GreaterEqFunctions = Vector<ast::Function>{
            BUILTIN_GREATER_EQ(Bool, Int32, Int32, info_for_binary_expressions),
            BUILTIN_GREATER_EQ(Bool, Int64, Int64, info_for_binary_expressions),
            BUILTIN_GREATER_EQ(Bool, Float32, Float32, info_for_binary_expressions),
            BUILTIN_GREATER_EQ(Bool, Float64, Float64, info_for_binary_expressions),
            BUILTIN_GREATER_EQ(Bool, String, String, info_for_binary_expressions),
        };

        auto LogicalAndFunctions = Vector<ast::Function>{
            BUILTIN_LOGICAL_AND(Bool, Bool, Bool, info_for_binary_expressions),
        };

        auto LogicalOrFunctions = Vector<ast::Function>{
            BUILTIN_LOGICAL_OR(Bool, Bool, Bool, info_for_binary_expressions),
        };

        auto EqualFunctions = Vector<ast::Function>{
            BUILTIN_EQUAL(Bool, Int32, Int32, info_for_binary_expressions),
            BUILTIN_EQUAL(Bool, Int64, Int64, info_for_binary_expressions),
            BUILTIN_EQUAL(Bool, Float32, Float32, info_for_binary_expressions),
            BUILTIN_EQUAL(Bool, Float64, Float64, info_for_binary_expressions),
        };

        auto NotEqualFunctions = Vector<ast::Function>{
            BUILTIN_NOT_EQUAL(Bool, Int32, Int32, info_for_binary_expressions),
            BUILTIN_NOT_EQUAL(Bool, Int64, Int64, info_for_binary_expressions),
            BUILTIN_NOT_EQUAL(Bool, Float32, Float32, info_for_binary_expressions),
            BUILTIN_NOT_EQUAL(Bool, Float64, Float64, info_for_binary_expressions),
        };

        auto AssignFunctions = Vector<ast::Function>{
            BUILTIN_ASSIGN(Int32, Int32, Int32, info_for_binary_expressions),
            BUILTIN_ASSIGN(Int64, Int64, Int64, info_for_binary_expressions),
            BUILTIN_ASSIGN(Float32, Float32, Float32, info_for_binary_expressions),
            BUILTIN_ASSIGN(Float64, Float64, Float64, info_for_binary_expressions),
        };

        auto Constructors = Vector<ast::Function>{
            BUILTIN_EMPTY_CONSTRUCTOR(i32, Int32, {}, info_for_binary_expressions),
            BUILTIN_EMPTY_CONSTRUCTOR(i64, Int64, {}, info_for_binary_expressions),
            BUILTIN_EMPTY_CONSTRUCTOR(u32, UInt32, {}, info_for_binary_expressions),
            BUILTIN_EMPTY_CONSTRUCTOR(u64, UInt64, {}, info_for_binary_expressions),
            BUILTIN_EMPTY_CONSTRUCTOR(f32, Float32, {}, info_for_binary_expressions),
            BUILTIN_EMPTY_CONSTRUCTOR(f64, Float64, {}, info_for_binary_expressions),
            BUILTIN_EMPTY_CONSTRUCTOR(bool, Bool, {}, info_for_binary_expressions),
            BUILTIN_EMPTY_CONSTRUCTOR(char, Char, {}, info_for_binary_expressions),
            BUILTIN_EMPTY_CONSTRUCTOR(String, String, {}, info_for_binary_expressions),
            BUILTIN_EMPTY_CONSTRUCTOR(
                Vector, VectorTemplate, {Template1}, info_for_binary_expressions),
            BUILTIN_CONVERT(f32, Float32, Int32, info_for_binary_expressions),
            BUILTIN_CONVERT(f32, Float32, Float32, info_for_binary_expressions),
            BUILTIN_CONVERT(f32, Float32, Int64, info_for_binary_expressions),
            BUILTIN_CONVERT(f32, Float32, UInt32, info_for_binary_expressions),
            BUILTIN_CONVERT(f32, Float32, UInt64, info_for_binary_expressions),
            BUILTIN_CONVERT(f32, Float32, Float64, info_for_binary_expressions),
            BUILTIN_CONVERT(f64, Float64, Float64, info_for_binary_expressions),
            BUILTIN_CONVERT(f64, Float64, Int32, info_for_binary_expressions),
            BUILTIN_CONVERT(f64, Float64, Int64, info_for_binary_expressions),
            BUILTIN_CONVERT(f64, Float64, UInt32, info_for_binary_expressions),
            BUILTIN_CONVERT(f64, Float64, UInt64, info_for_binary_expressions),
            BUILTIN_CONVERT(f64, Float64, Float32, info_for_binary_expressions),
            BUILTIN_CONVERT(i32, Int32, Int64, info_for_binary_expressions),
            BUILTIN_CONVERT(i32, Int32, Int32, info_for_binary_expressions),
            BUILTIN_CONVERT(i32, Int32, UInt32, info_for_binary_expressions),
            BUILTIN_CONVERT(i32, Int32, UInt64, info_for_binary_expressions),
            BUILTIN_CONVERT(i32, Int32, Float32, info_for_binary_expressions),
            BUILTIN_CONVERT(i32, Int32, Float64, info_for_binary_expressions),
            BUILTIN_CONVERT(i64, Int64, Int32, info_for_binary_expressions),
            BUILTIN_CONVERT(i64, Int64, Int64, info_for_binary_expressions),
            BUILTIN_CONVERT(i64, Int64, UInt32, info_for_binary_expressions),
            BUILTIN_CONVERT(i64, Int64, UInt64, info_for_binary_expressions),
            BUILTIN_CONVERT(i64, Int64, Float32, info_for_binary_expressions),
            BUILTIN_CONVERT(i64, Int64, Float64, info_for_binary_expressions),
            BUILTIN_CONVERT(u32, UInt32, Int32, info_for_binary_expressions),
            BUILTIN_CONVERT(u32, UInt32, UInt32, info_for_binary_expressions),
            BUILTIN_CONVERT(u32, UInt32, Int64, info_for_binary_expressions),
            BUILTIN_CONVERT(u32, UInt32, UInt64, info_for_binary_expressions),
            BUILTIN_CONVERT(u32, UInt32, Float32, info_for_binary_expressions),
            BUILTIN_CONVERT(u32, UInt32, Float64, info_for_binary_expressions),
            BUILTIN_CONVERT(u64, UInt64, Int32, info_for_binary_expressions),
            BUILTIN_CONVERT(u64, UInt64, UInt64, info_for_binary_expressions),
            BUILTIN_CONVERT(u64, UInt64, Int64, info_for_binary_expressions),
            BUILTIN_CONVERT(u64, UInt64, UInt32, info_for_binary_expressions),
            BUILTIN_CONVERT(u64, UInt64, Float32, info_for_binary_expressions),
            BUILTIN_CONVERT(u64, UInt64, Float64, info_for_binary_expressions),
        };

        auto InputFunctions = Vector<ast::Function>{
            {Void, "input", String, {}, ast::FunctionInfo{.NOEXCEPT = false}},
            {Void,
             "input",
             String,
             {{"message", String, ArgumentCategory::IN}},
             ast::FunctionInfo{
                 .NOEXCEPT = false, .CONSTEXPR = false, .VISIBILITY = Visibility::PUBLIC}}};

        auto OutputFunctions = Vector<ast::Function>{
            {Void,
             "putchar",
             Void,
             {{"value", Int32, ArgumentCategory::IN}},
             ast::FunctionInfo{
                 .NOEXCEPT = true, .CONSTEXPR = false, .VISIBILITY = Visibility::PUBLIC}},
            {Void,
             "print",
             Void,
             {{"fmt", String, ArgumentCategory::IN}},
             ast::FunctionInfo{
                 .NOEXCEPT = true,
                 .BUILTIN_FUNCTION = true,
                 .HAVE_PARAMETER_PACK = true,
                 .CONSTEXPR = false,
                 .VISIBILITY = Visibility::PUBLIC},
             {}},
        };

        auto FormatFunctions = Vector<ast::Function>{
            {Void,
             "format",
             Void,
             {Argument{"fmt", String, ArgumentCategory::IN}},
             ast::FunctionInfo{
                 .NOEXCEPT = false,
                 .BUILTIN_FUNCTION = true,
                 .HAVE_PARAMETER_PACK = true,
                 .CONSTEXPR = false,
                 .VISIBILITY = Visibility::PUBLIC},
             {}}};

        auto StringMethods = Vector<ast::Function>{
            {String,
             "size",
             UInt64,
             {},
             ast::FunctionInfo{
                 .NOEXCEPT = true,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = true,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = true,
                 .VISIBILITY = Visibility::PUBLIC}},
            {String,
             "toI32",
             Int32,
             {},
             ast::FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = true,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = false,
                 .VISIBILITY = Visibility::PUBLIC}},
            {String,
             "toI64",
             Int64,
             {},
             ast::FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = true,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = false,
                 .VISIBILITY = Visibility::PUBLIC}},
            {String,
             "toU64",
             UInt64,
             {},
             ast::FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = true,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = false,
                 .VISIBILITY = Visibility::PUBLIC}},
            {String,
             "toF32",
             Float32,
             {},
             ast::FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = true,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = false,
                 .VISIBILITY = Visibility::PUBLIC}},
            {String,
             "toF64",
             Float64,
             {},
             ast::FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = true,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = false,
                 .VISIBILITY = Visibility::PUBLIC}}};

        auto VectorMethods = Vector<ast::Function>{
            {VectorTemplate,
             "Vector",
             VectorTemplate,
             {Argument{"value", Template1, ArgumentCategory::IN}},
             ast::FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = false,
                 .BUILTIN_FUNCTION = true,
                 .HAVE_PARAMETER_PACK = true,
                 .CONSTEXPR = true,
                 .VISIBILITY = Visibility::PUBLIC},
             {Template1},
             ast::MagicFunctionType::INIT},
            {VectorTemplate,
             "size",
             UInt64,
             {},
             ast::FunctionInfo{
                 .NOEXCEPT = true,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = true,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = true,
                 .VISIBILITY = Visibility::PUBLIC}},
            {VectorTemplate,
             "push_back",
             Void,
             {Argument{"value", Template1, ArgumentCategory::IN}},
             ast::FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = false,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = true,
                 .VISIBILITY = Visibility::PUBLIC}},
            {VectorTemplate,
             "at",
             Template1,
             {Argument{"index", UInt64, ArgumentCategory::IN}},
             ast::FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = true,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = true,
                 .VISIBILITY = Visibility::PUBLIC}}};

        auto MemoryAllocation = Vector<ast::Function>{
            {Void,
             "construct",
             Template1,
             {{"number", UInt32, ArgumentCategory::IN}},
             ast::FunctionInfo{
                 .NOEXCEPT = false, .BUILTIN_FUNCTION = true, .VISIBILITY = Visibility::PUBLIC},
             {Template1}}};

        func::Functions.registerFunctions(
            {Constructors,       AddFunctions,        SubFunctions,       MulFunctions,
             DivFunctions,       LessFunctions,       GreaterFunctions,   LessEqFunctions,
             GreaterEqFunctions, LogicalAndFunctions, LogicalOrFunctions, EqualFunctions,
             NotEqualFunctions,  AssignFunctions,     InputFunctions,     OutputFunctions,
             FormatFunctions,    VectorMethods,       StringMethods,      MemoryAllocation});

        initialized = true;
    }

    namespace func
    {
        FunctionsHolder Functions{};
    }
}// namespace fsc
