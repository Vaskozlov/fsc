#ifndef FSC_ARGUMENT_HPP
#define FSC_ARGUMENT_HPP

#include <map>
#include <memory>
#include <string>

namespace fsc {
    using TypeId = size_t;

    namespace ast {
        class Node;
    }
}// namespace fsc

namespace fsc::func {
    enum struct ArgumentCategory : size_t { IN, INOUT, OUT, COPY };

    extern const std::map<std::string, ArgumentCategory, std::less<>> ArgumentCategories;

    class Argument {
    public:
        friend auto operator==(const Argument &lhs, const TypeId rhs) noexcept -> bool
        {
            return lhs.type == rhs;
        }

        friend auto operator==(const Argument &lhs, const Argument &rhs) noexcept -> bool
        {
            return lhs.type == rhs.type;
        }

        std::string name;
        TypeId type;
        ArgumentCategory category;
    };
}// namespace fsc::func

#endif /* FSC_ARGUMENT_HPP */
