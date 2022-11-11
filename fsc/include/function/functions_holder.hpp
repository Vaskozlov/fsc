#ifndef FSC_FUNCTIONS_HPP
#define FSC_FUNCTIONS_HPP

#include "ast/function.hpp"
#include <ccl/core/types.hpp>
#include <list>

namespace fsc::func {
    class FunctionsHolder {
        ccl::Map<TypeId, ccl::Map<std::string, std::list<ccl::SharedPtr<ast::Function>>>> functions;

    public:
        FunctionsHolder() = default;
        FunctionsHolder(ccl::InitializerList<ast::Function> functions_);

        auto registerFunction(ccl::SharedPtr<ast::Function> function) -> void;

        auto get(const Signature &signature, CallRequirements call_requirements)
                -> ccl::SharedPtr<ast::Function>;

        auto get(const std::string &name, const ccl::SmallVector<Argument> &arguments,
                 CallRequirements call_requirements) -> ccl::SharedPtr<ast::Function>
        {
            return get({name, arguments}, call_requirements);
        }
    };

    extern FunctionsHolder Functions;
}// namespace fsc::func

#endif /* FSC_FUNCTIONS_HPP */
