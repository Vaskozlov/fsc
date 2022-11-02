#include "function/functions_holder.hpp"
#include "type/builtin_types.hpp"
#include <algorithm>
#include <fmt/format.h>

namespace fsc::func {
    FunctionsHolder::FunctionsHolder(const std::initializer_list<Function> &functions_)
    {
        for (const auto &function : functions_) {
            registerFunction(function);
        }
    }

    void FunctionsHolder::registerFunction(const Function &function)
    {
        auto &functions_with_similar_name = functions[function.getName()];

        if (std::ranges::find(functions_with_similar_name, function) !=
            functions_with_similar_name.end()) {
            throw std::runtime_error(
                    fmt::format("Function with name {} already exists", function.getName()));
        }

        functions_with_similar_name.push_back(function);
    }

    auto FunctionsHolder::get(const Signature &signature, CallRequirements call_requirements)
            -> const Function &
    {
        const auto &functions_with_similar_name = functions[signature.name];
        auto function = std::find(functions_with_similar_name.begin(),
                                  functions_with_similar_name.end(), signature);

        if (function == functions_with_similar_name.end()) {
            throw std::runtime_error(
                    fmt::format("Function with name {} not found", signature.name));
        }

        if (call_requirements == CallRequirements::IMPLICIT &&
            function->getCallRequirements() == CallRequirements::EXPLICIT) {
            throw std::runtime_error(
                    fmt::format("Function {} has to be called explicitly", signature.name));
        }

        return *function;
    }

    FunctionsHolder Functions{{"__add__",
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
}// namespace fsc::func
