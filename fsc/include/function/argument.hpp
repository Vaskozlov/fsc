#ifndef FSC_ARGUMENT_HPP
#define FSC_ARGUMENT_HPP

#include "ast/value/variable.hpp"
#include "type/type.hpp"
#include <ccl/ccl.hpp>
#include <ccl/flatmap.hpp>

namespace fsc
{
    namespace ast
    {
        class Node;
    }

    enum struct CallRequirements : ccl::Id
    {
        IMPLICIT,
        EXPLICIT
    };

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
        ccl::Id type{};
        ArgumentCategory category{};

    public:
        explicit Argument(const ast::Node *node);

        Argument(
            std::string arg_name, ccl::Id type_id,
            ArgumentCategory argument_category = ArgumentCategory::COPY);

        [[nodiscard]] auto operator==(ccl::Id other) const noexcept -> bool
        {
            return type == other;
        }

        [[nodiscard]] auto operator==(const Argument &other) const noexcept -> bool
        {
            return type == other.type;
        }

        [[nodiscard]] auto getType() const noexcept -> ccl::Id
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

        auto toVariable() const -> ast::Variable;
    };

    struct Signature
    {
        std::string name{};
        ccl::SmallVector<Argument> arguments{};
        ccl::Id classId{};
    };
}// namespace fsc

#endif /* FSC_ARGUMENT_HPP */
