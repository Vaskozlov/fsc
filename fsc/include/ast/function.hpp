#ifndef FSC_AST_FUNCTION_HPP
#define FSC_AST_FUNCTION_HPP

#include "ast/basic_node.hpp"
#include "visibility.hpp"
#include "visitor.hpp"
#include <ccl/ccl.hpp>
#include <function/argument.hpp>

namespace fsc::ast {
    class Function : public Node {
        ccl::Map<std::string, ccl::SharedPtr<ast::Node>> defaultArguments;
        ccl::SmallVector<Argument> arguments;
        NodePtr function;
        std::string name;
        Visibility visibility{Visibility::FILE_PRIVATE};
        CallRequirements callRequirements{CallRequirements::EXPLICIT};
        TypeId returnType{};
        TypeId classId{};

    public:
        Function(const FscParser::FunctionContext *function_context, Visitor &visitor);

        Function(std::string_view name_, const TypeId return_type_,
                 ccl::InitializerList<Argument> arguments_, CallRequirements call_requirements_);

        auto print(const std::string &prefix, const bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        [[nodiscard]] constexpr static auto classof() noexcept -> NodeType
        {
            return NodeType::FUNCTION;
        }

        [[nodiscard]] auto makeFunctionMember(TypeId type_id) noexcept -> void
        {
            classId = type_id;
        }

        [[nodiscard]] auto operator==(const Function &other) const noexcept -> bool
        {
            return classId == other.classId && name == other.name && arguments == other.arguments;
        }

        [[nodiscard]] auto operator==(const Signature &other) const noexcept -> bool
        {
            return classId == other.classId && name == other.name && arguments == other.arguments;
        }

        [[nodiscard]] auto isMember() const noexcept -> bool
        {
            return classId != 0;
        }

        [[nodiscard]] auto getClassId() const noexcept -> TypeId
        {
            return classId;
        }

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getArguments() const noexcept -> const ccl::SmallVector<Argument> &
        {
            return arguments;
        }

        [[nodiscard]] auto getReturnType() const noexcept -> TypeId
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

        [[nodiscard]] auto getCallRequirements() const noexcept -> CallRequirements
        {
            return callRequirements;
        }


    private:
        auto genArguments(gen::CodeGenerator &output) const -> void;
        auto argumentToString(gen::CodeGenerator &output, const Argument &arg) const -> void;

        auto setReturnType(const std::vector<antlr4::tree::ParseTree *> &nodes) -> void;
        auto readArguments(const FscParser::ParametersContext *parameters_context, Visitor &visitor)
                -> void;
        auto processArgument(const FscParser::ArgumentContext *argument_context, Visitor &visitor)
                -> Argument;
        auto processAttributes(FscParser::Function_attibutesContext *ctx) -> void;
        static auto defineArgument(const FscParser::Argument_definitionContext *argument_definition)
                -> Argument;
    };
}// namespace fsc::ast

#endif /* FSC_AST_FUNCTION_HPP */
