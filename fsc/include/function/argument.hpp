#ifndef FSC_ARGUMENT_HPP
#define FSC_ARGUMENT_HPP

#include "ast/value/variable.hpp"
#include "type/type.hpp"
#include <ccl/ccl.hpp>
#include <ccl/codegen/basic_codegen.hpp>
#include <ccl/flatmap.hpp>

namespace fsc
{

    enum struct ArgumentCategory : ccl::Id
    {
        IN,
        INOUT,
        OUT,
        COPY
    };

    constexpr inline ccl::StaticFlatmap<std::string_view, ArgumentCategory, 4> ArgumentCategories{
        {"in", ArgumentCategory::IN},
        {"inout", ArgumentCategory::INOUT},
        {"out", ArgumentCategory::OUT},
        {"copy", ArgumentCategory::COPY}};

    class Argument
    {
    private:
        std::string name{};
        FscType type;
        ArgumentCategory category{};

    public:
        explicit Argument(const ast::Node *node);

        Argument(
            std::string arg_name, FscType fsc_type,
            ArgumentCategory argument_category = ArgumentCategory::COPY);

        [[nodiscard]] auto operator==(FscType other) const noexcept -> bool
        {
            const auto is_template = type.isTemplate();

            return type.getTrueType() == other.getTrueType() || is_template;
        }

        [[nodiscard]] auto operator==(const Argument &other) const noexcept -> bool
        {
            return this->operator==(other.type);
        }

        [[nodiscard]] auto getType() const noexcept -> FscType
        {
            return type;
        }

        [[nodiscard]] auto getName() const noexcept -> const std::string &
        {
            return name;
        }

        [[nodiscard]] auto getCategory() const noexcept -> ArgumentCategory
        {
            return category;
        }

        [[nodiscard]] auto toVariable() const -> ast::Variable;
    };

    struct CCL_TRIVIAL_ABI SignatureView
    {
        const std::string &name;
        const ccl::SmallVector<Argument> &arguments;
        FscType classType;
    };

    struct Signature
    {
        [[nodiscard]] operator SignatureView() const// NOLINT
        {
            return {name, arguments, classType};
        }

        std::string name{};
        ccl::SmallVector<Argument> arguments{};
        FscType classType;
    };

    auto operator<<(ccl::codegen::BasicCodeGenerator &generator, const Argument &argument)
        -> ccl::codegen::BasicCodeGenerator &;
}// namespace fsc

#endif /* FSC_ARGUMENT_HPP */
