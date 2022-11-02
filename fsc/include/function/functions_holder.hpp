#ifndef FSC_FUNCTIONS_HPP
#define FSC_FUNCTIONS_HPP

#include "function/function.hpp"
#include <list>

namespace fsc::func {
    class FunctionsHolder {
        std::map<std::string, std::list<Function>, std::less<>> functions;

    public:
        FunctionsHolder() = default;
        FunctionsHolder(const std::initializer_list<Function> &functions_);

        auto registerFunction(const Function &function) -> void;

        auto get(const Signature &signature, CallRequirements call_requirements)
                -> const Function &;

        auto get(const std::string &name, const std::vector<Argument> &arguments,
                 CallRequirements call_requirements) -> const Function &
        {
            return get({name, arguments}, call_requirements);
        }
    };

    extern FunctionsHolder Functions;
}// namespace fsc::func

#endif /* FSC_FUNCTIONS_HPP */
