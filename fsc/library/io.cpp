#include "io.hpp"

namespace fsc
{
    auto readFile(const std::filesystem::path &path) -> std::string
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
