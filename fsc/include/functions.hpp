#ifndef FSC_FUNCTIONS_HPP
#define FSC_FUNCTIONS_HPP

#include "function.hpp"
#include <list>
#include <map>

namespace fsc {
    class FunctionsHolder {
    public:
        FunctionsHolder() = default;

        FunctionsHolder(const std::initializer_list<Function> &functions_);

        auto add(const FscParser::FunctionContext *function_context, FscVisitor &visitor)
                -> Function &;
        auto get(const std::string &name, const std::vector<FunctionArgument> &arguments)
                -> const Function &;

    private:
        std::map<std::string, std::list<Function>, std::less<>> functions;
    };

    extern FunctionsHolder Functions;
}// namespace fsc

#endif /* FSC_FUNCTIONS_HPP */
