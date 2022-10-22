#include "stack.hpp"

namespace fsc {
    auto Stack::addGlobalVariable(const std::string &name, const FscValue &value) -> void
    {
        global_variables.try_emplace(name, name, value);
    }

    auto Stack::addVariable(const std::string &name, const FscValue &value) -> void
    {
        if (storage.empty()) {
            return addGlobalVariable(name, value);
        }

        if (storage.back().contains(name)) {
            throw std::runtime_error("Variable already exists");
        }

        storage.back().try_emplace(name, name, value);
    }

    auto Stack::get(const std::string &name) -> FscVariable &
    {
        if ((!storage.empty()) && storage.back().contains(name)) {
            return storage.back().at(name);
        }

        if (global_variables.contains(name)) {
            return global_variables.at(name);
        }

        throw std::runtime_error("Variable does not exist");
    }

    thread_local Stack ProgramsStack;
}// namespace fsc
