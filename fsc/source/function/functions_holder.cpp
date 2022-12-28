#include "function/functions_holder.hpp"
#include "ast/function/function.hpp"
#include "ccl/core/types.hpp"
#include "function/argument.hpp"
#include <algorithm>
#include <ccl/ccl.hpp>
#include <fmt/format.h>
#include <ranges>

namespace fsc::func
{
    FunctionsHolder::FunctionsHolder(ccl::InitializerList<ccl::Vector<ast::Function>> functions_)
    {
        for (const auto &list : functions_) {
            for (const auto &function : list) {
                registerFunction(function);
            }
        }
    }

    auto FunctionsHolder::registerFunction(const ast::Function &function) -> ccl::SharedPtr<ast::Function>
    {
        auto function_ptr = ccl::makeShared<ast::Function>(function);
        appendFunction(function_ptr, function_ptr->getClassId());

        switch (function_ptr->getMagicType()) {
        case ast::MagicFunctionType::INIT:
            appendFunction(function_ptr, 0);
            break;

        default:
            break;
        }

        return function_ptr;
    }

    auto FunctionsHolder::appendFunction(
        ccl::SharedPtr<ast::Function> &function,
        ccl::Id class_id) noexcept(false) -> void
    {
        auto &functions_with_similar_class_id = functions[class_id];
        auto &functions_with_similar_name = functions_with_similar_class_id[function->getName()];

        if (std::ranges::find(functions_with_similar_name, function) !=
            functions_with_similar_name.end()) {
            throw std::runtime_error(
                fmt::format("Function with name {} already exists", function->getName()));
        }

        functions_with_similar_name.push_back(function);
    }

    auto FunctionsHolder::get(const Signature &signature) const
        -> ccl::SharedPtr<ast::Function>
    {
        return *findFunction(signature);
    }

    auto FunctionsHolder::get(
        const std::string &name,
        const ccl::SmallVector<Argument> &arguments) const -> ccl::SharedPtr<ast::Function>
    {
        return get({name, arguments});
    }

    auto FunctionsHolder::findFunction(
        const Signature &signature) const noexcept(false) ->
        typename FunctionsList::const_iterator
    {
        const auto &functions_with_similar_class_id = functions.at(signature.classId);

        if (!functions_with_similar_class_id.contains(signature.name)) {
            throwUnableToFindFunction(signature);
        }

        const auto &functions_with_similar_name =
            functions_with_similar_class_id.at(signature.name);

        const auto function_it =
            std::ranges::find_if(functions_with_similar_name, [&signature](const auto &function) {
                return *function == signature;
            });

        if (function_it == functions_with_similar_name.end()) {
            if (signature.classId == 0 && signature.name.substr(0, 2) == "__") {
                ccl::SmallVector<Argument> arguments;

                for (const auto &argument : signature.arguments | std::views::drop(1)) {
                    arguments.push_back(argument);
                }

                return findFunction(
                    Signature{signature.name, arguments, arguments.front().getType()});
            }

            throwUnableToFindFunction(signature);
        }

        return function_it;
    }

    auto FunctionsHolder::throwUnableToFindFunction(const Signature &signature) noexcept(false)
        -> void
    {
        throw std::runtime_error(fmt::format("Function with name {} not found", signature.name));
    }
}// namespace fsc::func
