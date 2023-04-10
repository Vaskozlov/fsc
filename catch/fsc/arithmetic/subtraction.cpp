#include "debug/debug.hpp"
#include <ccl/debug/debug_file.hpp>

using namespace std::literals;

DEBUG_VAR constexpr static FscProgram = R"(
func main() -> i32
{
    print(10 - 10)
    print(10.15151 - 10.15151)
    print(10.15151F64 - 10.15151F64)

    return 0
}
)"sv;

DEBUG_VAR constexpr static CppProgram = R"(
#include <iostream>

int main()
{
    std::cout <<  10 - 10 << std::endl;
    std::cout <<  10.15151F - 10.15151F << std::endl;
    std::cout <<  10.15151 - 10.15151 << std::endl;

    return 0;
}
)"sv;


TEST_CASE("Subtraction", "[FSC]")
{
    REQUIRE(fsc::compareProgramsOutput(FscProgram, CppProgram));
}