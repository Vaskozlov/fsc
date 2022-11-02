#ifndef FSC_STACK_HPP
#define FSC_STACK_HPP

#include "ast/variable.hpp"
#include "type/type.hpp"
#include <deque>
#include <map>

namespace fsc {
    enum struct ScopeType : bool { SOFT, HARD };

    class Stack {
        using ScopeStorage = std::map<std::string, ast::Variable>;

        class Scope {
            ScopeStorage storage;
            ScopeType scopeType;

        public:
            explicit Scope(const ScopeType scope_type_) : scopeType(scope_type_)
            {}

            [[nodiscard]] auto isHard() const noexcept -> bool
            {
                return scopeType == ScopeType::HARD;
            }

            [[nodiscard]] auto has(const std::string &name) const -> bool
            {
                return storage.contains(name);
            }

            [[nodiscard]] auto get(const std::string &name) -> const ast::Variable &
            {
                return storage.at(name);
            }

            [[nodiscard]] auto add(const ast::Variable &value) -> void
            {
                storage.insert({value.getName(), value});
            }
        };

        static inline ScopeStorage globalStorage;
        std::vector<TypeId> classScopes;
        std::deque<Scope> scopes;

    public:
        auto pushScope(ScopeType scope_type) -> void
        {
            scopes.push_front(Scope{scope_type});
        }

        auto popScope() -> void
        {
            scopes.pop_front();
        }

        auto pushClassScope(TypeId type_id)
        {
            classScopes.push_back(type_id);
        }

        auto popClassScope() -> void
        {
            classScopes.pop_back();
        }

        auto addVariable(const ast::Variable &value)
        {
            if (scopes.empty()) {
                globalStorage.emplace(value.getName(), value);
                return;
            }

            scopes.back().add(value);
        }

        [[nodiscard]] auto get(const std::string &name) -> ast::Variable;
        [[nodiscard]] static auto getGlobal(const std::string &name) -> const ast::Variable &;
    };

    extern thread_local Stack ProgramStack;
}// namespace fsc

#endif /* FSC_STACK_HPP */
