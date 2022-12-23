#ifndef FSC_STACK_HPP
#define FSC_STACK_HPP

#include "ast/value/variable.hpp"
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
        friend class StackScope;
        friend class ClassScope;

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

    public:
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

    class StackScope
    {
    private:
        Stack &scope;

    public:
        StackScope(ScopeType scope_type, Stack &stack_scope)
          : scope{stack_scope}
        {
            scope.pushScope(scope_type);
        }

        ~StackScope()
        {
            scope.popScope();
        }
    };

    class ClassScope
    {
    private:
        Stack &scope;
        ccl::Id classId;

    public:
        ClassScope(ccl::Id class_id, Stack &stack_scope)
          : scope{stack_scope}
          , classId{class_id}
        {
            if (classId != 0) {
                scope.pushClassScope(class_id);
            }
        }

        ~ClassScope()
        {
            if (classId != 0) {
                scope.popClassScope();
            }
        }
    };

    extern thread_local Stack ProgramStack;
}// namespace fsc

#endif /* FSC_STACK_HPP */
