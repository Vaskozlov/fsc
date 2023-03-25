#include "ast/function/function.hpp"

using namespace ccl;

namespace fsc::ast
{
    auto Function::mapExplicitTemplates(
        Vector<std::string> &remap_types_names,
        Vector<AcquireTypeMapType> &remap_types_lock,
        const ccl::Vector<FscType> &on_call_templates) -> void
    {
        auto explicit_templates_to_remap = std::min(templates.size(), on_call_templates.size());

        for (auto i = 0ZU; i != explicit_templates_to_remap; ++i) {
            remap_types_lock.emplace_back(
                TypeManager::acquireTypeMap(templates[i], on_call_templates[i]));
            remap_types_names.emplace_back(templates[i].getName());
        }
    }

    auto Function::mapImplicitTemplates(
        ccl::Vector<std::string> &remap_types_names,
        ccl::Vector<AcquireTypeMapType> &remap_types_lock,
        const Vector<NodePtr> &function_arguments) -> void
    {
        for (auto i = 0ZU; i != arguments.size(); ++i) {
            const auto argument_type = arguments.at(i).getType();

            if (argument_type.isTemplate() && !argument_type.isRemapTemplate()) {
                remap_types_lock.emplace_back(TypeManager::acquireTypeMap(
                    argument_type, function_arguments.at(i)->getValueType()));
                remap_types_names.emplace_back(argument_type.getName());
            }
        }
    }
}// namespace fsc::ast