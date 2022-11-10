#ifndef FSC_ARGUMENT_HPP
#define FSC_ARGUMENT_HPP

#include "ast/variable.hpp"
#include "type/type.hpp"
#include <ccl/ccl.hpp>
#include <ccl/flatmap.hpp>

namespace fsc {
    using TypeId = size_t;

    namespace ast {
        class Node;
    }
}// namespace fsc

namespace fsc::func {
    CCL_ENUM(ArgumentCategory, size_t, IN, INOUT, OUT, COPY);

    constexpr inline ccl::StaticFlatmap<std::string_view, ArgumentCategory, 4> ArgumentCategories{
            {"in", ArgumentCategory::IN},
            {"inout", ArgumentCategory::INOUT},
            {"out", ArgumentCategory::OUT},
            {"copy", ArgumentCategory::COPY}};

    class Argument {
    public:
        Argument(std::string name_, TypeId type_,
                 ArgumentCategory category_ = ArgumentCategory::COPY)
            : name(std::move(name_)), type(type_), category(category_)
        {}

        Argument(const ast::Node *node) : name(), type(node->getValueType()), category()
        {}

        friend auto operator==(const Argument &lhs, const TypeId rhs) noexcept -> bool
        {
            return lhs.type == rhs;
        }

        friend auto operator==(const Argument &lhs, const Argument &rhs) noexcept -> bool
        {
            return lhs.type == rhs.type;
        }

        auto toVariable() const -> ast::Variable
        {
            auto flags = ast::VariableFlags{};
            auto optimized_category = category;

            if (category == func::ArgumentCategory::IN && FscType::isTriviallyCopyable(type)) {
                optimized_category = func::ArgumentCategory::COPY;
            }

            switch (optimized_category) {
                case func::ArgumentCategory::COPY:
                    break;

                case func::ArgumentCategory::IN:
                    flags.constant = true;
                    flags.reference = true;
                    break;

                case func::ArgumentCategory::OUT:
                case func::ArgumentCategory::INOUT:
                    flags.reference = true;
                    break;

                default:
                    std::unreachable();
            }

            return ast::Variable{name, type, flags};
        }

        std::string name;
        TypeId type;
        ArgumentCategory category;
    };
}// namespace fsc::func

#endif /* FSC_ARGUMENT_HPP */
