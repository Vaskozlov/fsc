#ifndef FSC_COMPILER_HPP
#define FSC_COMPILER_HPP

#include "ast/basic_node.hpp"
#include <fstream>
#include <string_view>
#include <filesystem>

namespace fsc
{
    extern const std::string_view FscProgramsHeader;
    extern const std::string_view CompilerFlags;

    auto compile(
        const std::filesystem::path &filename,  ast::OptimizationLevel optimization_level,
        bool print_tree = false) -> std::string;
}// namespace fsc

#endif /* FSC_COMPILER_HPP */
