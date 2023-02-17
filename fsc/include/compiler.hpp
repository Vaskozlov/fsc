#ifndef FSC_COMPILER_HPP
#define FSC_COMPILER_HPP

#include <fstream>
#include <string_view>

namespace fsc
{
    extern const std::string_view FscProgramsHeader;
    extern const std::string_view CompilerFlags;

    auto compile(std::string_view filename, std::ifstream &stream, bool print_tree = false)
        -> std::string;
}// namespace fsc

#endif /* FSC_COMPILER_HPP */
