#ifndef FSC_SIGNATURE_HPP
#define FSC_SIGNATURE_HPP

#include "function/argument.hpp"
#include <vector>

namespace fsc::func {
    class Signature {
    public:
        std::string name;
        std::vector<Argument> arguments;

        auto operator<=>(const Signature &other) const noexcept -> std::weak_ordering = default;
    };
}// namespace fsc::func

#endif /* FSC_SIGNATURE_HPP */
