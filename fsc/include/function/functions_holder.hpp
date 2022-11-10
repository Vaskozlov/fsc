#ifndef FSC_FUNCTIONS_HPP
#define FSC_FUNCTIONS_HPP

#include "function/function.hpp"
#include <list>

namespace fsc::func {
    class FunctionsHolder {
        ccl::Map<std::string, std::list<Function>> functions;

    public:
        FunctionsHolder() = default;
        FunctionsHolder(ccl::InitializerList<Function> functions_);

        auto registerFunction(const Function &function) -> void;

        auto get(const Signature &signature, CallRequirements call_requirements)
                -> const Function &;

        auto get(const std::string &name, const ccl::SmallVector<Argument, 4> &arguments,
                 CallRequirements call_requirements) -> const Function &
        {
            return get({name, arguments}, call_requirements);
        }
    };

    extern FunctionsHolder Functions;
}// namespace fsc::func

#endif /* FSC_FUNCTIONS_HPP */
