#ifndef FSC_AST_FUNCTION_HPP
#define FSC_AST_FUNCTION_HPP

#include "ast/basic_node.hpp"
#include "function/argument.hpp"
#include "visibility.hpp"
#include "visitor.hpp"
#include <ccl/ccl.hpp>

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
        ASSIGN
    };

    class Function : public NodeWrapper<NodeType::FUNCTION, SemicolonNeed::DO_NOT_NEED>
    {
    private:
        constexpr static ccl::StaticFlatmap<MagicFunctionType, std::string_view, 8> magicToFscName =
            {{MagicFunctionType::ADD, "__add__"},
             {MagicFunctionType::SUB, "__sub__"},
             {MagicFunctionType::MUL, "__mul__"},
             {MagicFunctionType::DIV, "__div__"},
             {MagicFunctionType::MOD, "__mod__"},
             {MagicFunctionType::EQUAL, "__equal__"},
             {MagicFunctionType::NOT_EQUAL, "__not_equal__"},
             {MagicFunctionType::ASSIGN, "__copy__"}};

        constexpr static ccl::StaticFlatmap<MagicFunctionType, std::string_view, 8> magicToRepr = {
            {MagicFunctionType::ADD, "+"},
            {MagicFunctionType::SUB, "-"},
            {MagicFunctionType::MUL, "*"},
            {MagicFunctionType::DIV, "/"},
            {MagicFunctionType::MOD, "%"},
            {MagicFunctionType::EQUAL, "__equal__"},
            {MagicFunctionType::NOT_EQUAL, "__not_equal__"},
            {MagicFunctionType::ASSIGN, "__copy__"}};

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
        Function(
            const FscParser::FunctionContext *function_context, Visitor &visitor, ccl::Id class_id);

        Function(
            ccl::Id class_id, std::string_view function_name, ccl::Id return_type,
            ccl::InitializerList<Argument> function_arguments,
            bool ends_with_parameter_pack = false);

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        [[nodiscard]] auto operator==(const Signature &other) const noexcept -> bool;

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

        auto genArguments(gen::CodeGenerator &output) const -> void;
        auto argumentToString(gen::CodeGenerator &output, const Argument &arg) const -> void;
        auto readArguments(const FscParser::ParametersContext *parameters_context, Visitor &visitor)
            -> void;

        auto processArgument(const FscParser::ArgumentContext *argument_context, Visitor &visitor)
            -> Argument;
        static auto defineArgument(const FscParser::Argument_definitionContext *argument_definition)
            -> Argument;

        auto setReturnType(const std::vector<antlr4::tree::ParseTree *> &nodes) -> void;
    };
}// namespace fsc::ast

#endif /* FSC_AST_FUNCTION_HPP */
