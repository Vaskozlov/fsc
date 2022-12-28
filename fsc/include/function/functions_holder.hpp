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
        FunctionsHolder();

        FunctionsHolder(ccl::InitializerList<ccl::Vector<ast::Function>> functions_);

        auto registerFunction(ccl::SharedPtr<ast::Function> function) -> void;

        [[nodiscard]] auto visitFunction(SignatureView signature, auto &&function) const
            -> decltype(auto)
        {
            return function(findFunction(signature)->get());
        }

        [[nodiscard]] auto get(SignatureView signature) const -> ccl::SharedPtr<ast::Function>;

        [[nodiscard]] auto
            get(const std::string &name, const ccl::SmallVector<Argument> &arguments) const
            -> ccl::SharedPtr<ast::Function>;

    private:
        auto appendFunction(ccl::SharedPtr<ast::Function> &function, ccl::Id class_id) noexcept(
            false) -> void;

        [[nodiscard]] auto findFunction(SignatureView signature) const noexcept(false) ->
            typename FunctionsList::const_iterator;

        [[noreturn]] static auto
            throwUnableToFindFunction(SignatureView signature) noexcept(false) -> void;
    };

    extern FunctionsHolder Functions;
}// namespace fsc::func

#endif /* FSC_FUNCTIONS_HPP */
