#ifndef FSC_AST_FUNCTION_HPP
#define FSC_AST_FUNCTION_HPP

#include "ast/basic_node.hpp"
#include "ccl/core/types.hpp"
#include "function/argument.hpp"
#include "type/antlr-types.hpp"
#include "type/builtin_types.hpp"
#include "visibility.hpp"
#include "visitor.hpp"
#include <ccl/ccl.hpp>
#include <ccl/codegen/basic_codegen.hpp>
#include <ccl/raii.hpp>
#include <FscParser.h>

namespace fsc::ast
{
    enum struct MagicFunctionType : ccl::u16
    {
        NONE,
        INIT,
        DEL,
        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        EQUAL,
        NOT_EQUAL,
        LESS,
        GREATER,
        LESS_EQ,
        GREATER_EQ,
        ASSIGN
    };

    struct FunctionInfo
    {
        bool NOEXCEPT = true;
        bool IS_METHOD = false;
        bool CONSTANT_METHOD = false;
        bool BUILTIN_FUNCTION = false;
        bool HAVE_PARAMETER_PACK = false;
        bool NODISCARD = true;
        bool CONSTEXPR = true;
        Visibility VISIBILITY = Visibility::FILE_PRIVATE;
    };

    class Function
      : public NodeWrapper<NodeType::FUNCTION, SemicolonNeed::DO_NOT_NEED>
      , public std::enable_shared_from_this<Function>
    {
    private:
        ccl::SmallVector<Argument> arguments;
        ccl::SmallVector<FscType> templates;
        ccl::SmallVector<FscType> remapTypes;
        ccl::Map<std::string, NodePtr> defaultArguments;
        NodePtr functionBody;
        std::string name;
        FunctionInfo functionInfo{};
        FscType returnType{Void};
        Visitor *visitorPtr{};
        FscType classType{};
        const FunctionContext *functionContext{};
        MagicFunctionType magicType{};

    public:
        Function() = default;

        Function(BasicContextPtr node_context);

        Function(
            FscType class_type, std::string_view function_name, FscType return_type,
            ccl::InitializerList<Argument> function_arguments, FunctionInfo function_info,
            const ccl::SmallVector<FscType> &function_templates = {},
            MagicFunctionType magic = MagicFunctionType::NONE);

        auto finishConstruction(
            const FunctionContext *function_context, Visitor &visitor, FscType class_type) -> void;

        auto analyze() -> void override;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final;

        [[nodiscard]] auto operator==(SignatureView other) const noexcept -> bool;

        auto memberize(FscType type_id) noexcept -> void
        {
            classType = type_id;
        }

        [[nodiscard]] auto isMember() const noexcept -> bool
        {
            return classType != Void;
        }

        [[nodiscard]] auto getClassType() const noexcept -> FscType
        {
            return classType;
        }

        [[nodiscard]] auto getMagicType() const noexcept -> MagicFunctionType
        {
            return magicType;
        }

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getArguments() const noexcept -> const ccl::SmallVector<Argument> &
        {
            return arguments;
        }

        [[nodiscard]] auto getReturnType() const -> FscType;

        [[nodiscard]] auto getVisibility() const noexcept -> Visibility
        {
            return functionInfo.VISIBILITY;
        }

        [[nodiscard]] auto getBody() const noexcept -> NodePtr
        {
            return functionBody;
        }

        [[nodiscard]] auto getDefaultArguments() const noexcept
            -> const ccl::Map<std::string, ccl::SharedPtr<ast::Node>> &
        {
            return defaultArguments;
        }

        auto analyzeOnCall(
            const ccl::SmallVector<NodePtr> &function_arguments,
            const ccl::SmallVector<FscType> &on_call_templates) -> FscType;

    protected:
        auto defaultAnalyze() const -> void;

    private:
        auto mapExplicitTemplates(
            ccl::SmallVector<std::string> &remap_types_names,
            ccl::SmallVector<AcquireTypeMapType> &remap_types_lock,
            const ccl::SmallVector<FscType> &on_call_templates) -> void;

        auto mapImplicitTemplates(
            ccl::SmallVector<std::string> &remap_types_names,
            ccl::SmallVector<AcquireTypeMapType> &remap_types_lock,
            const ccl::SmallVector<NodePtr> &function_arguments) -> void;

        auto checkFunctionArgumentAfterDeductionMatch(
            const ccl::SmallVector<NodePtr> &function_arguments) const noexcept(false) -> void;

        auto analyzeClassAfterConstruction() -> void;

        auto analyzeFunctionAfterTemplatesRemap() -> void;

        auto deduceReturnType(const ccl::SmallVector<std::string> &remap_types_names) const
            -> FscType;

        auto generateTemplateParameters(ccl::codegen::BasicCodeGenerator &output) const -> void;

        auto processMagicMethod() -> void;

        auto handleInit() noexcept(false) -> void;
        auto handleDestructor() noexcept(false) -> void;
        auto handleBinaryExpression(MagicFunctionType binary_operator) noexcept(false) -> void;

        auto processAttributes(FunctionAttributeContext *ctx) -> void;

        auto processTemplates(FscParser::Function_templatesContext *ctx) -> void;

        auto genArguments(ccl::codegen::BasicCodeGenerator &output) -> void;
        auto argumentToString(Argument &arg) const -> std::string;
        auto readArguments(const FscParser::ParametersContext *parameters_context, Visitor &visitor)
            -> void;

        auto processArgument(const FscParser::ArgumentContext *argument_context, Visitor &visitor)
            -> Argument;
        static auto defineArgument(const FscParser::Argument_definitionContext *argument_definition)
            -> Argument;

        auto setReturnType(const std::vector<antlr4::tree::ParseTree *> &nodes) -> void;

        auto completeBody(Visitor &visitor) -> void;

        auto addVisibility(ccl::codegen::BasicCodeGenerator &output) const -> void;
        auto addNodiscardModifier(ccl::codegen::BasicCodeGenerator &output) const -> void;
        auto addConstexprModifier(ccl::codegen::BasicCodeGenerator &output) const -> void;
        auto addConstModifier(ccl::codegen::BasicCodeGenerator &output) const -> void;
        auto addNoexceptModifier(ccl::codegen::BasicCodeGenerator &output) const -> void;
    };
}// namespace fsc::ast

#endif /* FSC_AST_FUNCTION_HPP */
