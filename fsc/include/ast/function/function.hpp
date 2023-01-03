#ifndef FSC_AST_FUNCTION_HPP
#define FSC_AST_FUNCTION_HPP

#include "ast/basic_node.hpp"
#include "function/argument.hpp"
#include "visibility.hpp"
#include "visitor.hpp"
#include <ccl/ccl.hpp>
#include <ccl/codegen/basic_codegen.hpp>

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

    class Function
      : public NodeWrapper<NodeType::FUNCTION, SemicolonNeed::DO_NOT_NEED>
      , public std::enable_shared_from_this<Function>
    {
    private:
        ccl::Map<std::string, ccl::SharedPtr<ast::Node>> defaultArguments;
        ccl::SmallVector<Argument> arguments;
        NodePtr function;
        std::string name;
        Visibility visibility{Visibility::FILE_PRIVATE};
        ccl::Id returnType{};
        ccl::Id classId{};
        MagicFunctionType magicType{};
        bool endsWithParameterPack{};

    public:
        Function();

        Function(
            ccl::Id class_id, std::string_view function_name, ccl::Id return_type,
            ccl::InitializerList<Argument> function_arguments,
            bool ends_with_parameter_pack = false);

        auto finishConstruction(
            const FscParser::FunctionContext *function_context, Visitor &visitor, ccl::Id class_id)
            -> void;

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void final;

        [[nodiscard]] auto operator==(SignatureView other) const noexcept -> bool;

        auto memberize(ccl::Id type_id) noexcept -> void
        {
            classId = type_id;
        }

        [[nodiscard]] auto isMember() const noexcept -> bool
        {
            return classId != 0;
        }

        [[nodiscard]] auto getClassId() const noexcept -> ccl::Id
        {
            return classId;
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

        [[nodiscard]] auto getReturnType() const noexcept -> ccl::Id
        {
            return returnType;
        }

        [[nodiscard]] auto getVisibility() const noexcept -> Visibility
        {
            return visibility;
        }

        [[nodiscard]] auto getBody() const noexcept -> NodePtr
        {
            return function;
        }

        [[nodiscard]] auto getDefaultArguments() const noexcept
            -> const ccl::Map<std::string, ccl::SharedPtr<ast::Node>> &
        {
            return defaultArguments;
        }

    private:
        auto processMagicMethod() -> void;

        auto processInitMethod() noexcept(false) -> void;
        auto processDelMethod() noexcept(false) -> void;
        auto processBinaryOperatorMethod(MagicFunctionType binary_operator) noexcept(false) -> void;

        auto processAttributes(FscParser::Function_attibutesContext *ctx) -> void;

        auto genArguments(ccl::codegen::BasicCodeGenerator &output) const -> void;
        auto argumentToString(ccl::codegen::BasicCodeGenerator &output, const Argument &arg) const -> void;
        auto readArguments(const FscParser::ParametersContext *parameters_context, Visitor &visitor)
            -> void;

        auto processArgument(const FscParser::ArgumentContext *argument_context, Visitor &visitor)
            -> Argument;
        static auto defineArgument(const FscParser::Argument_definitionContext *argument_definition)
            -> Argument;

        auto setReturnType(const std::vector<antlr4::tree::ParseTree *> &nodes) -> void;

        auto addNodiscardModifier(ccl::codegen::BasicCodeGenerator &output) const -> void;
        auto addConstexprModifier(ccl::codegen::BasicCodeGenerator &output) const -> void;
    };
}// namespace fsc::ast

#endif /* FSC_AST_FUNCTION_HPP */
