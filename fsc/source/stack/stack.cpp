#include "stack/stack.hpp"
#include "ast/value/variable.hpp"
#include <fmt/format.h>
#include <ranges>

namespace fsc
{
    auto Stack::addVariable(ccl::SharedPtr<ast::Variable> value) -> void
    {
        if (scopes.empty()) {
            globalStorage.emplace(value->getName(), std::move(value));
            return;
        }

        scopes.back().add(value);
    }

    auto Stack::get(const std::string &name) const -> ast::Variable
    {
        for (const auto &scope : scopes | std::views::reverse) {
            if (scope.has(name)) {
                return *scope.get(name);
            }

            if (scope.isHard()) {
                break;
            }
        }

        if (isMemberVariable(name)) {
            return *FscType::getMemberVariable(classScopes.back(), name);
        }

        return *getGlobal(name);
    }

    auto Stack::getGlobal(const std::string &name) noexcept(false) -> ccl::SharedPtr<ast::Variable>
    {
        if (globalStorage.contains(name)) {
            return globalStorage.at(name);
        }

        throw std::runtime_error(fmt::format("Variable {} does not exist", name));
    }

    CCL_INLINE auto Stack::isMemberVariable(const std::string &name) const -> bool
    {
        if (!classScopes.empty() && name == "this") {
            return true;
        }

        return !classScopes.empty() && FscType::hasMemberVariables(classScopes.back(), name);
    }

    thread_local Stack ProgramStack{};
}// namespace fsc
