#ifndef FSC_STACK_HPP
#define FSC_STACK_HPP

#include "ast/variable.hpp"
#include "type/type.hpp"
#include <deque>
#include <map>

namespace fsc
{
    enum struct ScopeType : bool
    {
        SOFT,
        HARD
    };

    class Stack
    {
        using ScopeStorage = ccl::Map<std::string, ast::Variable>;

        class Scope
        {
            ScopeStorage storage;
            ScopeType scopeType;

        public:
            explicit Scope(const ScopeType scope_type_)
              : scopeType{scope_type_}
            {}

            [[nodiscard]] auto isHard() const noexcept -> bool
            {
                return ScopeType::HARD == scopeType;
            }

            [[nodiscard]] auto has(const std::string &name) const -> bool
            {
                return storage.contains(name);
            }

            [[nodiscard]] auto get(const std::string &name) const -> const ast::Variable &
            {
                return storage.at(name);
            }

            [[nodiscard]] auto add(const ast::Variable &value) -> void
            {
                storage.insert({value.getName(), value});
            }
        };

        static inline ScopeStorage globalStorage;
        ccl::SmallVector<ccl::Id> classScopes;
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

        auto pushClassScope(ccl::Id type_id) -> void
        {
            classScopes.push_back(type_id);
        }

        auto popClassScope() -> void
        {
            classScopes.pop_back();
        }

        [[nodiscard]] auto getCurrentClassScope() const -> ccl::Id
        {
            if (classScopes.empty()) {
                return ccl::Id{};
            }

            return classScopes.back();
        }

        auto addVariable(const ast::Variable &value) -> void;
        [[nodiscard]] auto get(const std::string &name) const -> ast::Variable;
        [[nodiscard]] static auto getGlobal(const std::string &name) -> const ast::Variable &;

    private:
        [[nodiscard]] auto isMemberVariable(const std::string &name) const -> bool;
    };

    extern thread_local Stack ProgramStack;
}// namespace fsc

#endif /* FSC_STACK_HPP */
