#include "debug/debug.hpp"
#include <ccl/debug/debug_file.hpp>

using namespace std::literals;

DEBUG_VAR constexpr static FscProgram = R"(
func test()
{
    return 10
}

func main() -> i32
{
    print("{}\n", test())
    return 0
}
)"sv;

DEBUG_VAR constexpr static CppProgram = R"(
int test()
{
    return 10;
}

int main()
{
    fmt::print("{}\n", test());
    return 0;
}
)"sv;

TEST_CASE("FunctionCreation", "[FSC]")
{
    REQUIRE(fsc::compareProgramsOutput(FscProgram, CppProgram));
}