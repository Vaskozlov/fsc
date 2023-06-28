#include "io.hpp"

namespace fsc
{
    auto readFile(const std::filesystem::path &path) -> std::string
    {
        auto stream = std::ifstream(path);

        if (!stream.is_open()) {
            throw std::invalid_argument(fmt::format("Failed to open file {}", path.string()));
        }

        auto buffer = std::stringstream{};
        buffer << stream.rdbuf();

        return buffer.str();
    }
}// namespace fsc
