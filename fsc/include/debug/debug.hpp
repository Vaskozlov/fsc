#ifndef FSC_DEBUG_HPP
#define FSC_DEBUG_HPP

#include <string_view>

using namespace std::string_view_literals;

namespace fsc
{
    auto compareProgramsOutput(std::string_view fsc_program, std::string_view cpp_program) -> bool;
}// namespace fsc

#endif /* FSC_DEBUG_HPP */
