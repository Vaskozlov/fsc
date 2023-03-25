#ifndef FSC_STACK_HPP
#define FSC_STACK_HPP

#include "ast/value/variable.hpp"
#include "type/type.hpp"
#include <ccl/raii.hpp>
#include <deque>
#include <map>
#include <type/builtin_types.hpp>

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

        static ScopeStorage globalStorage;
        ccl::Vector<FscType> classScopes;
        ccl::Set<ccl::Id> functionsScopes;
        std::deque<Scope> scopes;
        ccl::Vector<ast::NodePtr> functionOnAnalysis;

    public:
        [[nodiscard]] auto acquireStackScope(ScopeType scope_type) -> auto
        {
            return ccl::Raii{
                [this, scope_type]() {
                    scopes.emplace_front(scope_type);
                },
                [this]() {
                    scopes.pop_front();
                }};
        }

        [[nodiscard]] auto acquireClassScope(FscType type_id) -> auto
        {
            return ccl::Raii{
                [this, type_id]() {
                    if (type_id != Void) {
                        classScopes.push_back(type_id);
                    }
                },
                [this, type_id]() {
                    if (type_id != Void) {
                        classScopes.pop_back();
                    }
                }};
        }

        [[nodiscard]] auto acquireAnalysisScope(ccl::Id function_id, ast::NodePtr function) -> auto
        {
            return ccl::Raii{
                [this, function_id, function]() {
                    functionsScopes.emplace(function_id);
                    functionOnAnalysis.emplace_back(function);
                },
                [this, function_id]() {
                    functionsScopes.erase(function_id);
                    functionOnAnalysis.pop_back();
                }};
        }

        [[nodiscard]] auto getCurrentFunctionOnAnalysis() const -> ast::NodePtr
        {
            return functionOnAnalysis.back();
        }

        [[nodiscard]] auto hasFunctionInCallTree(ccl::Id function_id) const -> bool
        {
            return functionsScopes.contains(function_id);
        }

        [[nodiscard]] auto getCurrentClassScope() const -> FscType
        {
            if (classScopes.empty()) {
                return Void;
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

    extern Stack ProgramStack;
}// namespace fsc

#endif /* FSC_STACK_HPP */
