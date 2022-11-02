#ifndef FSC_FUNCTION_HPP
#define FSC_FUNCTION_HPP

#include "FscVisitor.h"
#include "ast/basic_node.hpp"
#include "function/argument.hpp"
#include "function/signature.hpp"
#include "type/type.hpp"
#include "visitor.hpp"
#include <optional>

namespace fsc::func {
    enum struct Visibility : size_t { EXPORT, FILE_PRIVATE, PRIVATE, PROTECTED, PUBLIC };
    enum struct CallRequirements : size_t { IMPLICIT, EXPLICIT };

    class Function {
        using FscFunction = std::shared_ptr<ast::Node>;

        std::map<std::string, std::shared_ptr<ast::Node>> defaultArguments;
        Signature signature;
        std::optional<FscFunction> function;
        TypeId returnType{};
        Visibility visibility{Visibility::FILE_PRIVATE};
        CallRequirements callRequirements{};

    public:
        Function(const FscParser::FunctionContext *function_context, Visitor &visitor);

        Function(std::string name_, const TypeId return_type_,
                 const std::initializer_list<Argument> &arguments_,
                 CallRequirements call_requirements);

        [[nodiscard]] auto operator==(const Function &other) const noexcept -> bool
        {
            return signature == other.signature;
        }

        [[nodiscard]] auto operator==(const Signature &other) const noexcept -> bool
        {
            return signature == other;
        }

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return signature.name;
        }

        [[nodiscard]] auto getArguments() const noexcept -> const std::vector<Argument> &
        {
            return signature.arguments;
        }

        [[nodiscard]] auto getReturnType() const noexcept -> TypeId
        {
            return returnType;
        }

        [[nodiscard]] auto getVisibility() const noexcept -> Visibility
        {
            return visibility;
        }

        [[nodiscard]] auto getBody() const noexcept -> const std::optional<FscFunction> &
        {
            return function;
        }

        [[nodiscard]] auto getDefaultArguments() const noexcept
                -> const std::map<std::string, std::shared_ptr<ast::Node>> &
        {
            return defaultArguments;
        }

        [[nodiscard]] auto getCallRequirements() const noexcept -> CallRequirements
        {
            return callRequirements;
        }

    private:
        auto setReturnType(const std::vector<antlr4::tree::ParseTree *> &nodes) -> void;
        auto readArguments(const FscParser::ParametersContext *parameters_context, Visitor &visitor)
                -> void;
        auto processArgument(const FscParser::ArgumentContext *argument_context, Visitor &visitor)
                -> Argument;
        static auto defineArgument(const FscParser::Argument_definitionContext *argument_definition)
                -> Argument;
    };
}// namespace fsc::func

#endif /* FSC_FUNCTION_HPP */
