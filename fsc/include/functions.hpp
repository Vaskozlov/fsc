#ifndef FSC_FUNCTIONS_HPP
#define FSC_FUNCTIONS_HPP

#include "function.hpp"
#include <list>
#include <map>

namespace fsc {
    struct FunctionsHolder {
        FunctionsHolder() = default;

        FunctionsHolder(const std::initializer_list<Function> &functions_)
        {
            for (const auto &function: functions_) {
                functions[function.getName()].push_back(function);
            }
        }

        auto add(FscParser::FunctionContext *function_context) -> Function &
        {
            auto function = Function(function_context);
            auto name = function.getName();

            return functions[name].emplace_back(std::move(function));
        }

        auto get(const std::string &name, const std::vector<FunctionArgument> &arguments)
                -> const Function &
        {
            const auto &possible_alternatives = functions[name];

            for (const auto &function: possible_alternatives) {
                if (function.getArguments() == arguments) {
                    return function;
                }
            }

            throw std::runtime_error("No matching function to call");
        }

    private:
        std::map<std::string, std::list<Function>> functions;
    };

    extern FunctionsHolder Functions;
}// namespace fsc

#endif /* FSC_FUNCTIONS_HPP */
