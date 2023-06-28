#include "io.hpp"

namespace fsc
{
    using namespace std::string_literals;

    auto readFile(const std::filesystem::path &path) -> std::string
    {
        auto stream = std::ifstream(path);

        if (!stream.is_open()) {
            throw std::invalid_argument("Failed to open file {}"s + path.string());
        }

        auto buffer = std::stringstream{};
        buffer << stream.rdbuf();

        return buffer.str();
    }
}// namespace fsc
