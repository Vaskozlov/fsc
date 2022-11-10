#ifndef FSC_VISIBILITY_HPP
#define FSC_VISIBILITY_HPP

#include <ccl/flatmap.hpp>

namespace fsc {
    CCL_ENUM(Visibility, size_t, EXPORT, FILE_PRIVATE, PRIVATE, PROTECTED, PUBLIC);

    constexpr inline ccl::StaticFlatmap<std::string_view, Visibility, 4> VisibilityByStr{
            {"public", Visibility::PUBLIC},
            {"protected", Visibility::PROTECTED},
            {"private", Visibility::PRIVATE},
            {"fileprivate", Visibility::FILE_PRIVATE}};
}// namespace fsc

#endif /* FSC_VISIBILITY_HPP */
