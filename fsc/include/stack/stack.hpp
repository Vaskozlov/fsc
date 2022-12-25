#ifndef FSC_STACK_HPP
#define FSC_STACK_HPP

#include "ast/value/variable.hpp"
#include "ccl/raii.hpp"
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
    private:
        using ScopeStorage = ccl::Map<std::string, ccl::SharedPtr<ast::Variable>>;

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

            [[nodiscard]] auto has(const std::string &name) const noexcept -> bool
            {
                return storage.contains(name);
            }

            [[nodiscard]] auto get(const std::string &name) const -> ccl::SharedPtr<ast::Variable>
            {
                return storage.at(name);
            }

            [[nodiscard]] auto add(ccl::SharedPtr<ast::Variable> value) -> void
            {
                storage.emplace(value->getName(), std::move(value));
            }
        };

        static inline ScopeStorage globalStorage;
        ccl::SmallVector<ccl::Id> classScopes;
        std::deque<Scope> scopes;

    public:
        [[nodiscard]] auto acquireStackScope(ScopeType scope_type) -> auto
        {
            return ccl::Raii{
                [this, scope_type]() { scopes.push_front(Scope{scope_type}); },
                [this]() { scopes.pop_front(); }};
        }

        [[nodiscard]] auto acquireClassScope(ccl::Id type_id) -> auto
        {
            return ccl::Raii{
                [this, type_id]() {
                    if (type_id != 0) {
                        classScopes.push_back(type_id);
                    }
                },
                [this, type_id]() {
                    if (type_id != 0) {
                        classScopes.pop_back();
                    }
                }};
        }

        [[nodiscard]] auto getCurrentClassScope() const -> ccl::Id
        {
            if (classScopes.empty()) {
                return ccl::Id{};
            }

            return classScopes.back();
        }

        auto addVariable(ccl::SharedPtr<ast::Variable> value) -> void;

        [[nodiscard]] auto get(const std::string &name) const -> ast::Variable;
        [[nodiscard]] static auto getGlobal(const std::string &name) noexcept(false)
            -> ccl::SharedPtr<ast::Variable>;

    private:
        [[nodiscard]] auto isMemberVariable(const std::string &name) const -> bool;
    };

    extern thread_local Stack ProgramStack;
}// namespace fsc

#endif /* FSC_STACK_HPP */
