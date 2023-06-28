#ifndef FSC_IO_HPP
#define FSC_IO_HPP

#include <ccl/raii.hpp>
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

        const auto file_tracker = ccl::Raii(
            [&out]() {
                out.close();
            });

        (out.write(std::data(args), ccl::as<long>(std::size(args))), ...);
    }

    inline auto deleteFile(std::string_view filename) -> void
    {
        std::filesystem::remove(filename);
    }

    auto readFile(const std::filesystem::path &path) noexcept(false) -> std::string;
}// namespace fsc

#endif /* FSC_IO_HPP */
