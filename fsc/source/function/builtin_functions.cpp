#include "function/argument.hpp"
#include "function/functions_holder.hpp"
#include "type/builtin_types.hpp"
#include <ccl/ccl.hpp>

#define BUILTIN_BINARY_FUNCTION(NAME, RESULT, LHS, RHS)                                            \
    {                                                                                              \
        0, NAME, RESULT::typeId,                                                                   \
        {                                                                                          \
            {"lhs", LHS::typeId, ArgumentCategory::IN},                                            \
                {"rhs", RHS::typeId, ArgumentCategory::IN},                                        \
        }                                                                                          \
    }

#define BUILTIN_ADD(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__add__", RESULT, LHS, RHS)
#define BUILTIN_SUB(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__sub__", RESULT, LHS, RHS)
#define BUILTIN_MUL(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__mul__", RESULT, LHS, RHS)
#define BUILTIN_DIV(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__div__", RESULT, LHS, RHS)
#define BUILTIN_LOGICAL_AND(RESULT, LHS, RHS)                                                      \
    BUILTIN_BINARY_FUNCTION("__logical_and__", RESULT, LHS, RHS)
#define BUILTIN_LOGICAL_OR(RESULT, LHS, RHS)                                                       \
    BUILTIN_BINARY_FUNCTION("__logical_or__", RESULT, LHS, RHS)
#define BUILTIN_EQUAL(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__equal__", RESULT, LHS, RHS)
#define BUILTIN_NOT_EQUAL(RESULT, LHS, RHS)                                                        \
    BUILTIN_BINARY_FUNCTION("__not_equal__", RESULT, LHS, RHS)

#define BUILTIN_LESS(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__less__", RESULT, LHS, RHS)
#define BUILTIN_GREATER(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__greater__", RESULT, LHS, RHS)
#define BUILTIN_LESS_EQ(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__less_eq__", RESULT, LHS, RHS)
#define BUILTIN_GREATER_EQ(RESULT, LHS, RHS)                                                       \
    BUILTIN_BINARY_FUNCTION("__greater_eq__", RESULT, LHS, RHS)

#define BUILTIN_ASSIGN(RESULT, LHS, RHS)                                                           \
    {                                                                                              \
        0, "__copy__", RESULT::typeId,                                                             \
        {                                                                                          \
            {"lhs", LHS::typeId, ArgumentCategory::OUT},                                           \
                {"rhs", RHS::typeId, ArgumentCategory::IN},                                        \
        }                                                                                          \
    }

namespace fsc::func
{
    static const auto AddFunctions = ccl::Vector<ast::Function>{
        BUILTIN_ADD(Int32, Int32, Int32), BUILTIN_ADD(Int64, Int64, Int64),
        BUILTIN_ADD(Float32, Float32, Float32), BUILTIN_ADD(Float64, Float64, Float64)};

    static const auto SubFunctions = ccl::Vector<ast::Function>{
        BUILTIN_SUB(Int32, Int32, Int32), BUILTIN_SUB(Int64, Int64, Int64),
        BUILTIN_SUB(Float32, Float32, Float32), BUILTIN_SUB(Float64, Float64, Float64)};

    static const auto MulFunctions = ccl::Vector<ast::Function>{
        BUILTIN_MUL(Int32, Int32, Int32),
        BUILTIN_MUL(Int64, Int64, Int64),
        BUILTIN_MUL(Float32, Float32, Float32),
        BUILTIN_MUL(Float64, Float64, Float64),
    };

    static const auto DivFunctions = ccl::Vector<ast::Function>{
        BUILTIN_DIV(Int32, Int32, Int32),
        BUILTIN_DIV(Int64, Int64, Int64),
        BUILTIN_DIV(Float32, Float32, Float32),
        BUILTIN_DIV(Float64, Float64, Float64),
    };

    static const auto LessFunctions = ccl::Vector<ast::Function>{
        BUILTIN_LESS(Bool, Int32, Int32),     BUILTIN_LESS(Bool, Int64, Int64),
        BUILTIN_LESS(Bool, Float32, Float32), BUILTIN_LESS(Bool, Float64, Float64),
        BUILTIN_LESS(Bool, String, String),
    };

    static const auto GreaterFunctions = ccl::Vector<ast::Function>{
        BUILTIN_GREATER(Bool, Int32, Int32),     BUILTIN_GREATER(Bool, Int64, Int64),
        BUILTIN_GREATER(Bool, Float32, Float32), BUILTIN_GREATER(Bool, Float64, Float64),
        BUILTIN_GREATER(Bool, String, String),
    };

    static const auto LessEqFunctions = ccl::Vector<ast::Function>{
        BUILTIN_LESS_EQ(Bool, Int32, Int32),     BUILTIN_LESS_EQ(Bool, Int64, Int64),
        BUILTIN_LESS_EQ(Bool, Float32, Float32), BUILTIN_LESS_EQ(Bool, Float64, Float64),
        BUILTIN_LESS_EQ(Bool, String, String),
    };

    static const auto GreaterEqFunctions = ccl::Vector<ast::Function>{
        BUILTIN_GREATER_EQ(Bool, Int32, Int32),     BUILTIN_GREATER_EQ(Bool, Int64, Int64),
        BUILTIN_GREATER_EQ(Bool, Float32, Float32), BUILTIN_GREATER_EQ(Bool, Float64, Float64),
        BUILTIN_GREATER_EQ(Bool, String, String),
    };

    static const auto LogicalAndFunctions = ccl::Vector<ast::Function>{
        BUILTIN_LOGICAL_AND(Bool, Bool, Bool),
    };

    static const auto LogicalOrFunctions = ccl::Vector<ast::Function>{
        BUILTIN_LOGICAL_OR(Bool, Bool, Bool),
    };

    static const auto EqualFunctions = ccl::Vector<ast::Function>{
        BUILTIN_EQUAL(Bool, Int32, Int32),
        BUILTIN_EQUAL(Bool, Int64, Int64),
        BUILTIN_EQUAL(Bool, Float32, Float32),
        BUILTIN_EQUAL(Bool, Float64, Float64),
    };

    static const auto NotEqualFunctions = ccl::Vector<ast::Function>{
        BUILTIN_NOT_EQUAL(Bool, Int32, Int32),
        BUILTIN_NOT_EQUAL(Bool, Int64, Int64),
        BUILTIN_NOT_EQUAL(Bool, Float32, Float32),
        BUILTIN_NOT_EQUAL(Bool, Float64, Float64),
    };

    static const auto AssignFunctions = ccl::Vector<ast::Function>{
        BUILTIN_ASSIGN(Int32, Int32, Int32),
        BUILTIN_ASSIGN(Int64, Int64, Int64),
        BUILTIN_ASSIGN(Float32, Float32, Float32),
        BUILTIN_ASSIGN(Float64, Float64, Float64),
    };

    static const auto InputFunctions = ccl::Vector<ast::Function>{
        {0, "input", String::typeId, {}},
        {0, "input", String::typeId, {{"message", String::typeId, ArgumentCategory::IN}}}};

    static const auto OutputFunctions = ccl::Vector<ast::Function>{
        {0, "putchar", Void::typeId, {{"value", Int32::typeId, ArgumentCategory::IN}}},
        {0, "print", Void::typeId, {{"fmt", String::typeId, ArgumentCategory::IN}}, true},
    };

    static const auto FormatFunctions = ccl::Vector<ast::Function>{
        {0, "format", Void::typeId, {Argument{"fmt", String::typeId, ArgumentCategory::IN}}, true}};

    static const auto StringMethods =
        ccl::Vector<ast::Function>{{String::typeId, "size", UInt64::typeId, {}},
                                   {String::typeId, "toI32", Int32::typeId, {}},
                                   {String::typeId, "toI64", Int64::typeId, {}},
                                   {String::typeId, "toU64", UInt64::typeId, {}},
                                   {String::typeId, "toF32", Float32::typeId, {}},
                                   {String::typeId, "toF64", Float64::typeId, {}}};

    FunctionsHolder Functions{AddFunctions,       SubFunctions,       MulFunctions,
                              DivFunctions,       LessFunctions,      GreaterFunctions,
                              LessEqFunctions,    GreaterEqFunctions, LogicalAndFunctions,
                              LogicalOrFunctions, EqualFunctions,     NotEqualFunctions,
                              AssignFunctions,    InputFunctions,     OutputFunctions,
                              FormatFunctions,    StringMethods};
}// namespace fsc::func
