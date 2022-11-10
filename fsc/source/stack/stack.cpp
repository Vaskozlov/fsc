#include "stack/stack.hpp"
#include <fmt/format.h>

namespace fsc {
    auto Stack::get(const std::string &name) -> ast::Variable
    {
        if (scopes.empty()) {
            return getGlobal(name);
        }

        for (auto &scope : scopes) {
            if (scope.has(name)) {
                return scope.get(name);
            }

            if (scope.isHard()) {
                break;
            }
        }

        if (!classScopes.empty() && FscType::hasMemberVariables(classScopes.back(), name)) {
            return *FscType::getMemberVariable(classScopes.back(), name);
        }

        return getGlobal(name);
    }

    auto Stack::getGlobal(const std::string &name) -> const ast::Variable &
    {
        if (globalStorage.contains(name)) {
            return globalStorage.at(name);
        }

        throw std::runtime_error(fmt::format("Variable {} does not exist", name));
    }

    thread_local Stack ProgramStack{};
}// namespace fsc
