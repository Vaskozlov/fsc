#include "debug/debug.hpp"
#include <ccl/debug/debug_file.hpp>

using namespace std::literals;

DEBUG_VAR constexpr static FscProgram = R"(
func main() -> i32
{
    return 0
}
)"sv;

DEBUG_VAR constexpr static CppProgram = R"(
int main()
{
    return 0;
}
)"sv;

TEST_CASE("MainCompilation", "[FSC]")
{
    REQUIRE(fsc::compareProgramsOutput(FscProgram, CppProgram));
}