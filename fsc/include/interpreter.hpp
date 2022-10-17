#ifndef FSC_INTERPRETER_HPP
#define FSC_INTERPRETER_HPP

#include <fstream>

namespace fsc {
    auto interpret(std::ifstream &stream) -> void;
}

#endif /* FSC_INTERPRETER_HPP */
