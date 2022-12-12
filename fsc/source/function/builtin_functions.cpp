#include "function/functions_holder.hpp"
#include "type/builtin_types_impl.hpp"

namespace fsc::func
{
    FunctionsHolder Functions{
        {"__add__",
         Int32::typeId,
         {Argument{"lhs", Int32::typeId, ArgumentCategory::IN},
          Argument{"lhs", Int32::typeId, ArgumentCategory::IN}},
         CallRequirements::IMPLICIT},
        {"__add__",
         Int64::typeId,
         {Argument{"lhs", Int64::typeId, ArgumentCategory::IN},
          Argument{"lhs", Int64::typeId, ArgumentCategory::IN}},
         CallRequirements::IMPLICIT},
        {"__add__",
         Float32::typeId,
         {Argument{"lhs", Float32::typeId, ArgumentCategory::IN},
          Argument{"lhs", Float32::typeId, ArgumentCategory::IN}},
         CallRequirements::IMPLICIT},
        {"__add__",
         Float64::typeId,
         {Argument{"lhs", Float64::typeId, ArgumentCategory::IN},
          Argument{"lhs", Float64::typeId, ArgumentCategory::IN}},
         CallRequirements::IMPLICIT},
        {"__logical_and__",
         Bool::typeId,
         {Argument{"lhs", Int32::typeId, ArgumentCategory::IN},
          Argument{"lhs", Int32::typeId, ArgumentCategory::IN}},
         CallRequirements::IMPLICIT},
        {"__logical_and__",
         Bool::typeId,
         {Argument{"lhs", Bool::typeId, ArgumentCategory::IN},
          Argument{"lhs", Bool::typeId, ArgumentCategory::IN}},
         CallRequirements::IMPLICIT}};
}
