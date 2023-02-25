#include "ast/container/class.hpp"
#include "ast/function/function.hpp"
#include "stack/stack.hpp"

using namespace ccl;

namespace fsc::ast
{
    auto Function::analyze() -> AnalysisReport
    {
        auto report = Function::defaultAnalyze();
        analyzeReport(report);
        return report;
    }

    auto Function::defaultAnalyze() -> AnalysisReport
    {
        if (functionInfo.BUILTIN_FUNCTION) {
            auto report = AnalysisReport{};
            report.updateConstexpr(functionInfo.CONSTEXPR);
            report.updateNoexcept(functionInfo.NOEXCEPT);
            return report;
        }

        if (templates.empty()) {
            auto uuid = functionUuid;

            if (ProgramStack.hasFunctionInCallTree(uuid)) {
                return {};
            }

            const auto function_scope = ProgramStack.acquireFunctionScope(uuid);
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
                if (report.hasBeenModified(variable_node)) {
                    functionInfo.CONSTANT_METHOD = false;
                    break;
                }
            }
        }
    }

    auto Function::analyzeOnCall(
        const SmallVector<NodePtr> &function_arguments,
        const ccl::SmallVector<FscType> &on_call_templates) -> std::pair<FscType, AnalysisReport>
    {
        auto remap_types_names = SmallVector<std::string>{};
        auto remap_types_lock = SmallVector<AcquireTypeMapType>{};

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

    auto Function::analyzeClassAfterConstruction() -> AnalysisReport
    {
        const auto &class_node = classType.getClass();
        const auto &fsc_class = class_node->as<ast::Class>();
        return fsc_class.analyzeOnConstruction();
    }

    auto Function::analyzeFunctionAfterTemplatesRemap() -> AnalysisReport
    {
        if (!templates.empty()) {
            completeBody();
        }

        auto uuid = functionUuid * std::max(1ZU, hashTypes(templates));

        if (ProgramStack.hasFunctionInCallTree(uuid)) {
            return {};
        }

        const auto function_scope = ProgramStack.acquireFunctionScope(uuid);

        return functionBody->analyze();
    }

    auto Function::modifyBuiltinFunctionReport(AnalysisReport &report) -> void
    {
        report.updateNoexcept(functionInfo.NOEXCEPT);
        report.updateConstexpr(functionInfo.CONSTEXPR);
    }

    auto Function::deduceReturnType(const SmallVector<std::string> &remap_types_names) const
        -> FscType
    {
        auto returned_type = getReturnType();

        if (magicType == MagicFunctionType::INIT && !remap_types_names.empty()) {
            returned_type =
                FscType{fmt::format("{}<{}>", name, fmt::join(remap_types_names, ", "))};
        }

        return returned_type;
    }
}// namespace fsc::ast
