#ifndef FSC_IO_HPP
#define FSC_IO_HPP

#include <ccl/string_view.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <istream>

namespace fsc
{
    template<ccl::StringLike<char>... Ts>
    auto writeToFile(const std::string &filename, Ts &&...args) -> void
    {
        auto out = std::ofstream{filename};
        (out.write(std::data(args), ccl::as<long>(std::size(args))), ...);
        out.close();
    }

    inline auto deleteFile(std::string_view filename) -> void
    {
        std::filesystem::remove(filename);
    }

    inline auto readFile(const std::filesystem::path &path) -> std::string
    {
        auto stream = std::ifstream(path);

        if (!stream.is_open()) {
            fmt::print("Error: cannot open file {}\n", path.string());
            std::cout.flush();
            throw std::invalid_argument("Failed to open file");
        }

        auto buffer = std::stringstream{};
        buffer << stream.rdbuf();

        return buffer.str();
    }
}// namespace fsc

#endif /* FSC_IO_HPP */