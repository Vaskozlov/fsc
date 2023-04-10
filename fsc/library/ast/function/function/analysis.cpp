#include "ast/container/class.hpp"
#include "ast/function/function.hpp"
#include "stack/stack.hpp"

using namespace ccl;

namespace fsc::ast
{
    auto Function::analyze() -> AnalysisReport
    {
        auto report = Function::constructAnalysisReport();
        analyzeReport(report);
        return report;
    }

    auto Function::constructAnalysisReport() -> AnalysisReport
    {
        if (functionInfo.BUILTIN_FUNCTION) {
            auto report = AnalysisReport{};
            report.updateConstexpr(functionInfo.CONSTEXPR);
            report.updateNoexcept(functionInfo.NOEXCEPT);
            return report;
        }

        if (classType != Void) {
            auto uuid = functionUuid * std::max<size_t>(1, hashTypes(templates));

            if (ProgramStack.hasFunctionInCallTree(uuid)) {
                return {};
            }

            const auto function_scope = ProgramStack.acquireAnalysisScope(uuid, shared_from_this());
            auto report = functionBody->analyze();
            analyzeReport(report);
            return report;
        }

        return {};
    }

    auto Function::analyzeReport(const AnalysisReport &report) -> void
    {
        if (functionInfo.BUILTIN_FUNCTION) {
            return;
        }

        functionInfo.NOEXCEPT &= report.isNoexcept();
        functionInfo.CONSTEXPR &= report.isConstexpr();

        if (classType != Void) {
            const auto &member_variables = TypeManager::getMemberVariables(classType);

            for (const auto &[variable_name, variable_node] : member_variables) {
                if (report.hasBeenModified(variable_node.get())) {
                    functionInfo.CONSTANT_METHOD = false;
                    functionInfo.STATIC_METHOD = false;
                    break;
                }

                if (report.hasBeenRead(variable_node.get())) {
                    functionInfo.STATIC_METHOD = false;
                }
            }
        }
    }

    auto Function::analyzeOnCall(
        const Vector<NodePtr> &function_arguments,
        const ccl::Vector<FscType> &on_call_templates) -> std::pair<FscType, AnalysisReport>
    {
        auto remap_types_names = Vector<std::string>{};
        auto remap_types_lock = Vector<AcquireTypeMapType>{};

        mapExplicitTemplates(remap_types_names, remap_types_lock, on_call_templates);
        mapImplicitTemplates(remap_types_names, remap_types_lock, function_arguments);
        checkFunctionArgumentAfterDeductionMatch(
            function_arguments);// TODO: check this before finding function

        auto report = AnalysisReport{};

        if (!functionInfo.BUILTIN_FUNCTION) {
            report = getReportOfUserDefinedFunction();
        } else {
            modifyBuiltinFunctionReport(report);
        }

        analyzeReport(report);

        return {deduceReturnType(remap_types_names), report};
    }

    auto Function::updateReturnType(FscType new_return_type) -> void
    {
        const auto is_template = std::ranges::any_of(templates, [this](auto elem) {
            return elem == returnType;
        });

        if (returnType != Auto && returnType != new_return_type && !is_template) {
            throw FscException("function has two different return types");
        }

        if (!is_template && templates.empty()) {
            returnType = new_return_type;
        }
    }

    auto Function::analyzeClassAfterConstruction() -> AnalysisReport
    {
        const auto &class_node = classType.getClass();
        auto &fsc_class = class_node->as<ast::Class>();
        return fsc_class.analyzeOnConstruction();
    }

    auto Function::analyzeFunctionAfterTemplatesRemap() -> AnalysisReport
    {
        auto uuid = functionUuid * std::max<size_t>(1, hashTypes(templates));

        if (ProgramStack.hasFunctionInCallTree(uuid)) {
            return {};
        }

        completeBody();

        const auto function_scope = ProgramStack.acquireAnalysisScope(uuid, shared_from_this());

        return functionBody->analyze();
    }

    auto Function::modifyBuiltinFunctionReport(AnalysisReport &report) const noexcept -> void
    {
        report.updateNoexcept(functionInfo.NOEXCEPT);
        report.updateConstexpr(functionInfo.CONSTEXPR);
    }

    auto Function::deduceReturnType(const Vector<std::string> &remap_types_names) const -> FscType
    {
        auto returned_type = getReturnType();

        if (magicType == MagicFunctionType::INIT && !remap_types_names.empty()) {
            returned_type =
                FscType{fmt::format("{}<{}>", name, fmt::join(remap_types_names, ", "))};
        }

        return returned_type;
    }

    auto Function::evalCall(const ccl::Vector<NodePtr> &passed_arguments) -> ccl::Optional<NodePtr>
    {
        if (!functionInfo.CONSTEXPR) {
            return std::nullopt;
        }

        auto function_scope = ProgramStack.acquireStackScope(ScopeType::HARD);
        for (auto i = ccl::as<size_t>(0); i != arguments.size(); ++i) {
            auto variable = makeShared<Variable>(arguments[i].toVariable());

            if (auto value = std::dynamic_pointer_cast<Value>(passed_arguments[i]);
                value != nullptr) {
                variable->setValue(std::move(value));
            }

            else if (auto argument_as_variable =
                         std::dynamic_pointer_cast<Variable>(passed_arguments[i]);
                     argument_as_variable != nullptr) {
                variable->setValue(argument_as_variable->getStoredValue());
            }

            ProgramStack.addVariable(variable);
        }

        if (functionInfo.BUILTIN_FUNCTION && comiletimeVersionOfBuiltinFunction != nullptr) {
            return comiletimeVersionOfBuiltinFunction();
        } else if (!functionInfo.BUILTIN_FUNCTION) {
            // add compile time call
        }

        return std::nullopt;
    }
}// namespace fsc::ast
