#include "function/argument.hpp"
#include "function/functions_holder.hpp"
#include "type/builtin_types.hpp"
#include "type/type.hpp"

#define BUILTIN_BINARY_FUNCTION(NAME, RESULT, LHS, RHS)                                            \
    {                                                                                              \
        Void, NAME, FscType{RESULT},                                                               \
        {                                                                                          \
            {"lhs", FscType{LHS}, ArgumentCategory::IN},                                           \
                {"rhs", FscType{RHS}, ArgumentCategory::IN},                                       \
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
        Void, "__copy__", FscType{RESULT},                                                         \
        {                                                                                          \
            {"lhs", FscType{LHS}, ArgumentCategory::OUT},                                          \
                {"rhs", FscType{RHS}, ArgumentCategory::IN},                                       \
        }                                                                                          \
    }

#define BUILTIN_CONVERT(REPR, TO, FROM)                                                            \
    {                                                                                              \
        Void, #REPR, FscType{TO},                                                                  \
        {                                                                                          \
            {                                                                                      \
                "value", FscType                                                                   \
                {                                                                                  \
                    FROM                                                                           \
                }                                                                                  \
            }                                                                                      \
        }                                                                                          \
    }

namespace fsc::func
{
    using namespace ccl;

    static const auto AddFunctions = Vector<ast::Function>{
        BUILTIN_ADD(Int32, Int32, Int32), BUILTIN_ADD(Int64, Int64, Int64),
        BUILTIN_ADD(Float32, Float32, Float32), BUILTIN_ADD(Float64, Float64, Float64)};

    static const auto SubFunctions = Vector<ast::Function>{
        BUILTIN_SUB(Int32, Int32, Int32), BUILTIN_SUB(Int64, Int64, Int64),
        BUILTIN_SUB(Float32, Float32, Float32), BUILTIN_SUB(Float64, Float64, Float64)};

    static const auto MulFunctions = Vector<ast::Function>{
        BUILTIN_MUL(Int32, Int32, Int32),
        BUILTIN_MUL(Int64, Int64, Int64),
        BUILTIN_MUL(Float32, Float32, Float32),
        BUILTIN_MUL(Float64, Float64, Float64),
    };

    static const auto DivFunctions = Vector<ast::Function>{
        BUILTIN_DIV(Int32, Int32, Int32),
        BUILTIN_DIV(Int64, Int64, Int64),
        BUILTIN_DIV(Float32, Float32, Float32),
        BUILTIN_DIV(Float64, Float64, Float64),
    };

    static const auto LessFunctions = Vector<ast::Function>{
        BUILTIN_LESS(Bool, Int32, Int32),     BUILTIN_LESS(Bool, Int64, Int64),
        BUILTIN_LESS(Bool, Float32, Float32), BUILTIN_LESS(Bool, Float64, Float64),
        BUILTIN_LESS(Bool, String, String),
    };

    static const auto GreaterFunctions = Vector<ast::Function>{
        BUILTIN_GREATER(Bool, Int32, Int32),     BUILTIN_GREATER(Bool, Int64, Int64),
        BUILTIN_GREATER(Bool, Float32, Float32), BUILTIN_GREATER(Bool, Float64, Float64),
        BUILTIN_GREATER(Bool, String, String),
    };

    static const auto LessEqFunctions = Vector<ast::Function>{
        BUILTIN_LESS_EQ(Bool, Int32, Int32),     BUILTIN_LESS_EQ(Bool, Int64, Int64),
        BUILTIN_LESS_EQ(Bool, Float32, Float32), BUILTIN_LESS_EQ(Bool, Float64, Float64),
        BUILTIN_LESS_EQ(Bool, String, String),
    };

    static const auto GreaterEqFunctions = Vector<ast::Function>{
        BUILTIN_GREATER_EQ(Bool, Int32, Int32),     BUILTIN_GREATER_EQ(Bool, Int64, Int64),
        BUILTIN_GREATER_EQ(Bool, Float32, Float32), BUILTIN_GREATER_EQ(Bool, Float64, Float64),
        BUILTIN_GREATER_EQ(Bool, String, String),
    };

    static const auto LogicalAndFunctions = Vector<ast::Function>{
        BUILTIN_LOGICAL_AND(Bool, Bool, Bool),
    };

    static const auto LogicalOrFunctions = Vector<ast::Function>{
        BUILTIN_LOGICAL_OR(Bool, Bool, Bool),
    };

    static const auto EqualFunctions = Vector<ast::Function>{
        BUILTIN_EQUAL(Bool, Int32, Int32),
        BUILTIN_EQUAL(Bool, Int64, Int64),
        BUILTIN_EQUAL(Bool, Float32, Float32),
        BUILTIN_EQUAL(Bool, Float64, Float64),
    };

    static const auto NotEqualFunctions = Vector<ast::Function>{
        BUILTIN_NOT_EQUAL(Bool, Int32, Int32),
        BUILTIN_NOT_EQUAL(Bool, Int64, Int64),
        BUILTIN_NOT_EQUAL(Bool, Float32, Float32),
        BUILTIN_NOT_EQUAL(Bool, Float64, Float64),
    };

    static const auto AssignFunctions = Vector<ast::Function>{
        BUILTIN_ASSIGN(Int32, Int32, Int32),
        BUILTIN_ASSIGN(Int64, Int64, Int64),
        BUILTIN_ASSIGN(Float32, Float32, Float32),
        BUILTIN_ASSIGN(Float64, Float64, Float64),
    };

    static const auto Constructors = Vector<ast::Function>{
        BUILTIN_CONVERT(f32, Float32, Int32),   BUILTIN_CONVERT(f32, Float32, Float32),
        BUILTIN_CONVERT(f32, Float32, Int64),   BUILTIN_CONVERT(f32, Float32, UInt32),
        BUILTIN_CONVERT(f32, Float32, UInt64),  BUILTIN_CONVERT(f32, Float32, Float64),
        BUILTIN_CONVERT(f64, Float64, Float64), BUILTIN_CONVERT(f64, Float64, Int32),
        BUILTIN_CONVERT(f64, Float64, Int64),   BUILTIN_CONVERT(f64, Float64, UInt32),
        BUILTIN_CONVERT(f64, Float64, UInt64),  BUILTIN_CONVERT(f64, Float64, Float32),
        BUILTIN_CONVERT(i32, Int32, Int64),     BUILTIN_CONVERT(i32, Int32, Int32),
        BUILTIN_CONVERT(i32, Int32, UInt32),    BUILTIN_CONVERT(i32, Int32, UInt64),
        BUILTIN_CONVERT(i32, Int32, Float32),   BUILTIN_CONVERT(i32, Int32, Float64),
        BUILTIN_CONVERT(i64, Int64, Int32),     BUILTIN_CONVERT(i64, Int64, Int64),
        BUILTIN_CONVERT(i64, Int64, UInt32),    BUILTIN_CONVERT(i64, Int64, UInt64),
        BUILTIN_CONVERT(i64, Int64, Float32),   BUILTIN_CONVERT(i64, Int64, Float64),
        BUILTIN_CONVERT(u32, UInt32, Int32),    BUILTIN_CONVERT(u32, UInt32, UInt32),
        BUILTIN_CONVERT(u32, UInt32, Int64),    BUILTIN_CONVERT(u32, UInt32, UInt64),
        BUILTIN_CONVERT(u32, UInt32, Float32),  BUILTIN_CONVERT(u32, UInt32, Float64),
        BUILTIN_CONVERT(u64, UInt64, Int32),    BUILTIN_CONVERT(u64, UInt64, UInt64),
        BUILTIN_CONVERT(u64, UInt64, Int64),    BUILTIN_CONVERT(u64, UInt64, UInt32),
        BUILTIN_CONVERT(u64, UInt64, Float32),  BUILTIN_CONVERT(u64, UInt64, Float64),
    };

    static const auto InputFunctions = Vector<ast::Function>{
        {Void, "input", String, {}},
        {Void, "input", String, {{"message", String, ArgumentCategory::IN}}}};

    static const auto OutputFunctions = Vector<ast::Function>{
        {Void, "putchar", Void, {{"value", Int32, ArgumentCategory::IN}}},
        {Void, "print", Void, {{"fmt", String, ArgumentCategory::IN}}, {}, true},
    };

    static const auto FormatFunctions = Vector<ast::Function>{
        {Void, "format", Void, {Argument{"fmt", String, ArgumentCategory::IN}}, {}, true}};

    static const auto StringMethods =
        Vector<ast::Function>{{String, "size", UInt64, {}},   {String, "toI32", Int32, {}},
                              {String, "toI64", Int64, {}},   {String, "toU64", UInt64, {}},
                              {String, "toF32", Float32, {}}, {String, "toF64", Float64, {}}};


    static const auto MemoryAllocation = Vector<ast::Function>{
        {Void, "create", Template1, {{"first", Template1, ArgumentCategory::IN}}, {"T1"}}};

    FunctionsHolder Functions{
        Constructors,       AddFunctions,        SubFunctions,       MulFunctions,
        DivFunctions,       LessFunctions,       GreaterFunctions,   LessEqFunctions,
        GreaterEqFunctions, LogicalAndFunctions, LogicalOrFunctions, EqualFunctions,
        NotEqualFunctions,  AssignFunctions,     InputFunctions,     OutputFunctions,
        FormatFunctions,    StringMethods,       MemoryAllocation};
}// namespace fsc::func
