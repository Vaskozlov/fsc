#include "stack/stack.hpp"
#include "ast/value/variable.hpp"
#include <ccl/ccl.hpp>
#include <ranges>

namespace fsc
{
    using namespace ccl;
    namespace sv = std::views;

    Stack::ScopeStorage Stack::globalStorage{};// NOLINT

    auto Stack::addVariable(SharedPtr<ast::Variable> value) -> void
    {
        if (scopes.empty()) {
            globalStorage.emplace(value->getName(), std::move(value));
            return;
        }

        scopes.front().add(value);
    }

    auto Stack::get(const std::string &name) const -> ast::Variable
    {
        for (const auto &scope : scopes) {
            if (scope.has(name)) {
                return *scope.get(name);
            }

            if (scope.isHard()) {
                break;
            }
        }

        if (isMemberVariable(name)) {
            return *ccl::as<ast::Variable *>(classScopes.back().getMemberVariable(name).get());
        }

        return *getGlobal(name);
    }

    auto Stack::getGlobal(const std::string &name) noexcept(false) -> SharedPtr<ast::Variable>
    {
        if (globalStorage.contains(name)) {
            return globalStorage.at(name);
        }

        throw FscException(fmt::format("Variable {} does not exist", name));
    }

    CCL_INLINE auto Stack::isMemberVariable(const std::string &name) const -> bool
    {
        if (!classScopes.empty() && name == "this") {
            return true;
        }

        return !classScopes.empty() && classScopes.back().hasMemberVariables(name);
    }

    Stack ProgramStack{};// NOLINT
}// namespace fsc
