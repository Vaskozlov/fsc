#ifndef FSC_COMPILER_HPP
#define FSC_COMPILER_HPP

#include <fstream>

namespace fsc {
    auto compile(std::ifstream &stream) -> void;
}

#endif /* FSC_COMPILER_HPP */
