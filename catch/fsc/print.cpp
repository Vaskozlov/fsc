#include "debug/debug.hpp"
#include <ccl/debug/debug_file.hpp>

using namespace std::literals;

DEBUG_VAR constexpr static FscProgram = R"(
func main() -> i32
{
    print(10)
    return 0
}
)"sv;

DEBUG_VAR constexpr static CppProgram = R"(
#include <iostream>

int main()
{
    std::cout << 10 << std::endl;;
    return 0;
}
)"sv;

TEST_CASE("Print", "[FSC]")
{
    REQUIRE(fsc::compareProgramsOutput(FscProgram, CppProgram));
}