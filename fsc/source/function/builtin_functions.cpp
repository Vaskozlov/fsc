#include "function/argument.hpp"
#include "function/functions_holder.hpp"
#include "type/builtin_types.hpp"

#define BUILTIN_BINARY_FUNCTION(NAME, RESULT, LHS, RHS)                                            \
    {                                                                                              \
        NAME, RESULT::typeId,                                                                      \
            {Argument{"lhs", LHS::typeId, ArgumentCategory::IN},                                   \
             Argument{"lhs", RHS::typeId, ArgumentCategory::IN}},                                  \
            CallRequirements::IMPLICIT                                                             \
    }

#define BUILTIN_ADD(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__add__", RESULT, LHS, RHS)
#define BUILTIN_MUL(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__mul__", RESULT, LHS, RHS)
#define BUILTIN_LOGICAL_AND(RESULT, LHS, RHS)                                                      \
    BUILTIN_BINARY_FUNCTION("__logical_and__", RESULT, LHS, RHS)
#define BUILTIN_EQUAL(RESULT, LHS, RHS) BUILTIN_BINARY_FUNCTION("__equal__", RESULT, LHS, RHS)
#define BUILTIN_NOT_EQUAL(RESULT, LHS, RHS)                                                        \
    BUILTIN_BINARY_FUNCTION("__not_equal__", RESULT, LHS, RHS)


namespace fsc::func
{
    FunctionsHolder Functions{
        BUILTIN_ADD(Int32, Int32, Int32),
        BUILTIN_ADD(Int64, Int64, Int64),
        BUILTIN_ADD(Float32, Float32, Float32),
        BUILTIN_ADD(Float64, Float64, Float64),
        BUILTIN_MUL(Int32, Int32, Int32),
        BUILTIN_MUL(Int64, Int64, Int64),
        BUILTIN_MUL(Float32, Float32, Float32),
        BUILTIN_MUL(Float64, Float64, Float64),
        BUILTIN_LOGICAL_AND(Bool, Bool, Bool),
        BUILTIN_EQUAL(Bool, Int32, Int32),
        BUILTIN_EQUAL(Bool, Int64, Int64),
        BUILTIN_EQUAL(Bool, Float32, Float32),
        BUILTIN_EQUAL(Bool, Float64, Float64),
        BUILTIN_NOT_EQUAL(Bool, Int32, Int32),
        BUILTIN_NOT_EQUAL(Bool, Int64, Int64),
        BUILTIN_NOT_EQUAL(Bool, Float32, Float32),
        BUILTIN_NOT_EQUAL(Bool, Float64, Float64),
        {"putchar",
         Void::typeId,
         {Argument{"value", Int32::typeId, ArgumentCategory::IN}},
         CallRequirements::EXPLICIT},
        {"print",
         Void::typeId,
         {Argument{"fmt", String::typeId, ArgumentCategory::IN}},
         CallRequirements::EXPLICIT,
         true},
        {"format",
         Void::typeId,
         {Argument{"fmt", String::typeId, ArgumentCategory::IN}},
         CallRequirements::EXPLICIT,
         true}};
}
