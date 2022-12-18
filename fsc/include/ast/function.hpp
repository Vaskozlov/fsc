#ifndef FSC_AST_FUNCTION_HPP
#define FSC_AST_FUNCTION_HPP

#include "ast/basic_node.hpp"
#include "visibility.hpp"
#include "visitor.hpp"
#include <ccl/ccl.hpp>
#include <function/argument.hpp>

namespace fsc::ast
{
    enum struct MagicFunctionType : ccl::u16
    {
        NONE,
        INIT
    };

    class Function : public NodeWrapper<NodeType::FUNCTION, SemicolonNeed::DO_NOT_NEED>
    {
        ccl::Map<std::string, ccl::SharedPtr<ast::Node>> defaultArguments;
        ccl::SmallVector<Argument> arguments;
        NodePtr function;
        std::string name;
        Visibility visibility{Visibility::FILE_PRIVATE};
        CallRequirements callRequirements{CallRequirements::EXPLICIT};
        ccl::Id returnType{};
        ccl::Id classId{};
        MagicFunctionType magicType{};
        bool endsWithParameterPack{};

    public:
        Function(
            const FscParser::FunctionContext *function_context, Visitor &visitor, ccl::Id class_id);

        Function(
            std::string_view function_name, const ccl::Id return_type,
            ccl::InitializerList<Argument> function_arguments, CallRequirements call_requirements,
            bool ends_with_parameter_pack = false);

        auto print(const std::string &prefix, bool is_left) const -> void final;

        auto codeGen(gen::CodeGenerator &output) const -> void final;

        [[nodiscard]] auto memberizeFunction(ccl::Id type_id) noexcept -> void
        {
            classId = type_id;
        }

        template<typename T>
        [[nodiscard]] auto operator==(const T &other) const noexcept -> bool
            requires(std::is_same_v<T, Function> || std::is_same_v<T, Signature>)
        {
            const auto is_constructor =
                (other.classId == 0 && getMagicType() == MagicFunctionType::INIT);

            if (arguments.size() > std::size(other.arguments)) {
                return false;
            }

            const auto first_arguments_equal = std::ranges::equal(
                arguments.cbegin(), arguments.cend(), other.arguments.cbegin(),
                other.arguments.cbegin() + arguments.size());

            if (!first_arguments_equal) {
                return false;
            }

            auto arguments_equal = first_arguments_equal;

            if (std::size(other.arguments) > arguments.size()) {
                arguments_equal = endsWithParameterPack;
            }

            return (arguments_equal && ((classId == other.classId) || is_constructor)) &&
                   name == other.name;
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

        [[nodiscard]] auto getCallRequirements() const noexcept -> CallRequirements
        {
            return callRequirements;
        }

    private:
        auto processMagicMethod() -> void;
        auto processInitMethod() noexcept(false) -> void;

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
