#ifndef FSC_FUNCTIONS_HPP
#define FSC_FUNCTIONS_HPP

#include "ast/function/function.hpp"
#include <ccl/core/types.hpp>
#include <function/argument.hpp>
#include <list>
#include <type/type.hpp>

namespace fsc::func
{
    class FunctionsHolder
    {
    private:
        using FunctionsList = std::list<ccl::SharedPtr<ast::Function>>;
        using FunctionsByNameMap = ccl::Map<std::string, FunctionsList>;
        using FunctionByClassIdMap = ccl::Map<ccl::Id, FunctionsByNameMap>;

        FunctionByClassIdMap functions;

    public:
        FunctionsHolder() = default;
        FunctionsHolder(ccl::InitializerList<ccl::Vector<ast::Function>> functions_);

        auto registerFunction(ccl::SharedPtr<ast::Function> function) -> void;

        [[nodiscard]] auto visitFunction(
            const Signature &signature,
            auto &&function,
            CallRequirements call_requirements = CallRequirements::EXPLICIT) const -> decltype(auto)
        {
            return function(findFunction(signature, call_requirements)->get());
        }

        [[nodiscard]] auto
            get(const Signature &signature,
                CallRequirements call_requirements = CallRequirements::EXPLICIT) const
            -> ccl::SharedPtr<ast::Function>;

        [[nodiscard]] auto
            get(const std::string &name,
                const ccl::SmallVector<Argument> &arguments,
                CallRequirements call_requirements) const -> ccl::SharedPtr<ast::Function>;

    private:
        auto appendFunction(ccl::SharedPtr<ast::Function> &function, ccl::Id class_id) noexcept(
            false) -> void;

        [[nodiscard]] auto
            findFunction(const Signature &signature, CallRequirements call_requirements) const
            noexcept(false) -> typename FunctionsList::const_iterator;

        [[noreturn]] static auto
            throwUnableToFindFunction(const Signature &signature) noexcept(false) -> void;
    };

    extern FunctionsHolder Functions;
}// namespace fsc::func

#endif /* FSC_FUNCTIONS_HPP */
