#ifndef FSC_COMPILER_HPP
#define FSC_COMPILER_HPP

#include <fstream>
#include <string_view>

namespace fsc
{
    extern constinit const std::string_view FscProgramsHeader;
    extern constinit const std::string_view ClangCompilerFlags;

    auto compile(std::ifstream &stream) -> void;
}

#endif /* FSC_COMPILER_HPP */
