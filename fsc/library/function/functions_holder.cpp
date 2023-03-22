#include "function/functions_holder.hpp"
#include "ast/function/function.hpp"
#include "ast/function/magic_methods_table.hpp"
#include "function/argument.hpp"
#include "stack/stack.hpp"
#include <algorithm>
#include <ccl/ccl.hpp>
#include <ranges>

namespace fsc::func
{
    using namespace ccl;
    namespace sv = std::views;

    static auto isMagicFunction(SignatureView signature) noexcept -> bool
    {
        return ast::magic::SpecialFunctionsMagic.contains(signature.name);
    }

    FunctionsHolder::FunctionsHolder() = default;

    FunctionsHolder::FunctionsHolder(InitializerList<Vector<ast::Function>> functions_)
    {
        for (const auto &list : functions_) {
            for (const auto &function : list) {
                registerFunction(makeShared<ast::Function>(function));
            }
        }
    }

    auto FunctionsHolder::registerFunction(SharedPtr<ast::Function> function) -> void
    {
        appendFunction(function, function->getClassType());

        switch (function->getMagicType()) {
        case ast::MagicFunctionType::INIT:
            appendFunction(function, Void);
            break;

        default:
            break;
        }
    }

    auto FunctionsHolder::appendFunction(
        SharedPtr<ast::Function> &function,
        FscType class_type) noexcept(false) -> void
    {
        auto &functions_with_similar_class_id = functions[class_type];
        auto &functions_with_similar_name = functions_with_similar_class_id[function->getName()];

        if (auto similar_function_it = std::ranges::find(functions_with_similar_name, function);
            similar_function_it != functions_with_similar_name.end()) {
            auto &similar_function = *similar_function_it;

            if (similar_function->getArguments() == function->getArguments()) {
                throw FscException{
                    fmt::format("function with name {} already exists", function->getName())};
            }
        }

        functions_with_similar_name.push_back(function);
    }

    auto FunctionsHolder::get(SignatureView signature) const -> SharedPtr<ast::Function>
    {
        return *findFunction(signature);
    }

    auto FunctionsHolder::get(const std::string &name, const Vector<Argument> &arguments) const
        -> SharedPtr<ast::Function>
    {
        return get({name, arguments, Void});
    }

    // NOLINTNEXTLINE
    auto FunctionsHolder::findFunction(SignatureView signature) const ->
        typename FunctionsList::const_iterator
    {
        if (TypeManager::exists(signature.name) &&
            FscType{signature.name}.getName() != signature.name) {
            const auto function_to_fsc_type = FscType{signature.name};
            const auto real_function_name = function_to_fsc_type.getName();

            return findFunction({real_function_name, signature.arguments, signature.classType});
        }

        signature.classType = cleanupType(signature.classType);

        if (!functions.contains(signature.classType)) {
            return checkMagicFunctionOrReturnFailure(
                signature, FunctionFindFailure::NO_FUNCTIONS_WITH_THE_SAME_NAME);
        }

        const auto &functions_with_similar_class_id = functions.at(signature.classType);

        if (!functions_with_similar_class_id.contains(signature.name)) {
            return checkMagicFunctionOrReturnFailure(
                signature, FunctionFindFailure::NO_FUNCTIONS_WITH_THE_SAME_NAME);
        }

        const auto &functions_with_similar_name =
            functions_with_similar_class_id.at(signature.name);

        const auto function_it = std::ranges::find_if(
            functions_with_similar_name, [&signature](const SharedPtr<ast::Function> &function) {
                return *function == signature;
            });

        if (function_it == functions_with_similar_name.end()) {
            return checkMagicFunctionOrReturnFailure(
                signature, FunctionFindFailure::NO_FUNCTIONS_WITH_THE_SAME_PARAMETERS);
        }

        return function_it;
    }

    // NOLINTNEXTLINE
    auto FunctionsHolder::findMagicFunction(SignatureView signature) const ->
        typename FunctionsList::const_iterator
    {
        auto arguments = Vector<Argument>{};

        for (const auto &argument : signature.arguments | sv::drop(1)) {
            arguments.push_back(argument);
        }

        const auto class_id = arguments.front().getType();

        return findFunction({signature.name, arguments, class_id});
    }

    // NOLINTNEXTLINE
    auto FunctionsHolder::checkMagicFunctionOrReturnFailure(
        SignatureView signature,
        FunctionFindFailure failure_type) const -> typename FunctionsList::const_iterator
    {
        if (signature.classType == Void && isMagicFunction(signature)) {
            return findMagicFunction(signature);
        }

        if (signature.classType == Void && ProgramStack.getCurrentClassScope() != Void) {
            return findFunction(
                {signature.name, signature.arguments, ProgramStack.getCurrentClassScope()});
        }

        if (failure_type == FunctionFindFailure::NO_FUNCTIONS_WITH_THE_SAME_NAME) {
            throwUnableToFindFunctionWithGivenName(signature);
        } else {
            throwUnableToFindFunctionWithGivenParameters(signature);
        }
    }

    auto FunctionsHolder::throwUnableToFindFunctionWithGivenName(SignatureView signature) noexcept(
        false) -> void
    {
        throw FscException{fmt::format("function with name {} not found", signature.name)};
    }

    auto FunctionsHolder::throwUnableToFindFunctionWithGivenParameters(
        SignatureView signature) noexcept(false) -> void
    {
        throw FscException{fmt::format(
            "function with name {} has been found, but it's parameters do not match",
            signature.name)};
    }
}// namespace fsc::func
