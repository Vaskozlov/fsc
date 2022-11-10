#include "interpreter.hpp"
#include <fmt/format.h>

auto main(int argc, char **argv) -> int
{
    if (1 == argc) {
        fmt::print("Filename expected\n");
        return 1;
    }

    std::ifstream stream(argv[1]);

    if (!stream.is_open()) {
        fmt::print("{} is not a valid file\n", argv[1]);
        return 1;
    }

    fsc::interpret(stream);

    return 0;
}
