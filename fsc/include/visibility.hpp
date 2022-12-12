#ifndef FSC_VISIBILITY_HPP
#define FSC_VISIBILITY_HPP

#include "codegen.hpp"
#include <ccl/flatmap.hpp>

namespace fsc
{
    enum struct Visibility : size_t
    {
        EXPORT,
        FILE_PRIVATE,
        PRIVATE,
        PROTECTED,
        PUBLIC
    };

    constexpr inline ccl::StaticFlatmap<std::string_view, Visibility, 4> VisibilityByStr{
        {"public", Visibility::PUBLIC},
        {"protected", Visibility::PROTECTED},
        {"private", Visibility::PRIVATE},
        {"fileprivate", Visibility::FILE_PRIVATE}};

    auto genVisibility(Visibility visibility, gen::CodeGenerator &output) -> void;
}// namespace fsc

#endif /* FSC_VISIBILITY_HPP */
