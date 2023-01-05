#include "function/functions_holder.hpp"
#include "ast/function/function.hpp"
#include "ast/function/magic_methods_table.hpp"
#include "function/argument.hpp"
#include <algorithm>
#include <ccl/ccl.hpp>
#include <expected>
#include <fmt/format.h>
#include <ranges>

namespace fsc::func
{
    static auto isMagicFunction(SignatureView signature) noexcept -> bool
    {
        return ast::magic::SpecialFunctionsMagic.contains(signature.name);
    }

    FunctionsHolder::FunctionsHolder() = default;

    FunctionsHolder::FunctionsHolder(ccl::InitializerList<ccl::Vector<ast::Function>> functions_)
    {
        for (const auto &list : functions_) {
            for (const auto &function : list) {
                registerFunction(ccl::makeShared<ast::Function>(function));
            }
        }
    }

    auto FunctionsHolder::registerFunction(ccl::SharedPtr<ast::Function> function) -> void
    {
        appendFunction(function, function->getClassId());

        switch (function->getMagicType()) {
        case ast::MagicFunctionType::INIT:
            appendFunction(function, 0);
            break;

        default:
            break;
        }
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
                fmt::format("function with name {} already exists", function->getName()));
        }

        functions_with_similar_name.push_back(function);
    }

    auto FunctionsHolder::get(SignatureView signature) const -> ccl::SharedPtr<ast::Function>
    {
        auto find_result = findFunction(signature);

        if (find_result == std::unexpected(FunctionFindFailure::NO_FUNCTIONS_WITH_THE_SAME_NAME)) {
            throwUnableToFindFunctionWithGivenName(signature);
        } else if (
            find_result ==
            std::unexpected(FunctionFindFailure::NO_FUNCTIONS_WITH_THE_SAME_PARAMETERS)) {
            throwUnableToFindFunctionWithGivenParameters(signature);
        }

        return *find_result.value();
    }

    auto FunctionsHolder::get(const std::string &name, const ccl::SmallVector<Argument> &arguments)
        const -> ccl::SharedPtr<ast::Function>
    {
        return get({name, arguments});
    }

    // NOLINTNEXTLINE
    auto FunctionsHolder::findFunction(SignatureView signature) const noexcept
        -> std::expected<typename FunctionsList::const_iterator, FunctionFindFailure>
    {
        if (!functions.contains(signature.classId)) {
            return checkMagicFunctionOrReturnFailure(
                signature, FunctionFindFailure::NO_FUNCTIONS_WITH_THE_SAME_NAME);
        }

        const auto &functions_with_similar_class_id = functions.at(signature.classId);

        if (!functions_with_similar_class_id.contains(signature.name)) {
            return checkMagicFunctionOrReturnFailure(
                signature, FunctionFindFailure::NO_FUNCTIONS_WITH_THE_SAME_NAME);
        }

        const auto &functions_with_similar_name =
            functions_with_similar_class_id.at(signature.name);

        const auto function_it =
            std::ranges::find_if(functions_with_similar_name, [&signature](const auto &function) {
                return *function == signature;
            });

        if (function_it == functions_with_similar_name.end()) {
            return checkMagicFunctionOrReturnFailure(
                signature, FunctionFindFailure::NO_FUNCTIONS_WITH_THE_SAME_PARAMETERS);
        }

        return function_it;
    }

    // NOLINTNEXTLINE
    auto FunctionsHolder::findMagicFunction(SignatureView signature) const noexcept
        -> std::expected<typename FunctionsList::const_iterator, FunctionFindFailure>
    {
        auto arguments = ccl::SmallVector<Argument>{};

        for (const auto &argument : signature.arguments | std::views::drop(1)) {
            arguments.push_back(argument);
        }

        const auto class_id = arguments.front().getType();

        return findFunction({signature.name, arguments, class_id});
    }

    // NOLINTNEXTLINE
    auto FunctionsHolder::checkMagicFunctionOrReturnFailure(
        SignatureView signature,
        FunctionFindFailure failure_type) const noexcept
        -> std::expected<typename FunctionsList::const_iterator, FunctionFindFailure>
    {
        if (signature.classId == 0 && isMagicFunction(signature)) {
            return findMagicFunction(signature);
        }

        return std::unexpected(failure_type);
    }

    auto FunctionsHolder::throwUnableToFindFunctionWithGivenName(SignatureView signature) noexcept(
        false) -> void
    {
        throw std::runtime_error(fmt::format("function with name {} not found", signature.name));
    }

    auto FunctionsHolder::throwUnableToFindFunctionWithGivenParameters(
        SignatureView signature) noexcept(false) -> void
    {
        throw std::runtime_error(fmt::format(
            "function with name {} has been found, but it's parameters do not match",
            signature.name));
    }
}// namespace fsc::func
