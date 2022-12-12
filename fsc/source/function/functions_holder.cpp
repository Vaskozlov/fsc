#include "function/functions_holder.hpp"
#include "type/builtin_types.hpp"
#include <algorithm>
#include <ast/function.hpp>
#include <ccl/ccl.hpp>
#include <fmt/format.h>

namespace fsc::func
{
    FunctionsHolder::FunctionsHolder(ccl::InitializerList<ast::Function> functions_)
    {
        for (const auto &function : functions_) {
            registerFunction(ccl::makeShared<ast::Function>(function));
        }
    }

    void FunctionsHolder::registerFunction(ccl::SharedPtr<ast::Function> function)
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

    auto FunctionsHolder::appendFunction(ccl::SharedPtr<ast::Function> &function, ccl::Id class_id)
        -> void
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

    auto FunctionsHolder::get(const Signature &signature, CallRequirements call_requirements)
        -> ccl::SharedPtr<ast::Function>
    {
        const auto &functions_with_similar_class_id = functions.at(signature.classId);
        const auto &functions_with_similar_name =
            functions_with_similar_class_id.at(signature.name);

        const auto function_it =
            std::ranges::find_if(functions_with_similar_name, [&signature](const auto &function) {
                return *function == signature;
            });

        if (function_it == functions_with_similar_name.end()) {
            throw std::runtime_error(
                fmt::format("Function with name {} not found", signature.name));
        }

        if (call_requirements == CallRequirements::IMPLICIT &&
            (*function_it)->getCallRequirements() == CallRequirements::EXPLICIT) {
            throw std::runtime_error(
                fmt::format("Function {} has to be called explicitly", signature.name));
        }

        return *function_it;
    }
}// namespace fsc::func
