#ifndef FSC_STACK_HPP
#define FSC_STACK_HPP

#include "builtin/types.hpp"
#include <list>
#include <map>

namespace fsc {
    struct FscVariable {
        std::string name;
        FscValue value;
        bool is_constant = false;
        bool is_reference = false;
    };

    class Stack {
    private:
        using storage_t = std::list<std::map<std::string, FscVariable>>;

    public:
        auto pushScope() -> void
        {
            storage.emplace_back();
        }

        auto popScope() -> void
        {
            storage.pop_back();
        }

        auto get(const std::string &name) -> FscVariable &;
        auto addVariable(const std::string &name, const FscValue &value) -> void;
        static auto addGlobalVariable(const std::string &name, const FscValue &value) -> void;

    private:
        static inline std::map<std::string, FscVariable> global_variables;

        storage_t storage;
    };

    thread_local extern Stack ProgramsStack;
}// namespace fsc

#endif /* FSC_STACK_HPP */
