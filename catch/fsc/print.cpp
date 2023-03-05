#include "debug/debug.hpp"
#include <ccl/debug/debug_file.hpp>

using namespace std::literals;

DEBUG_VAR constexpr static FscProgram = R"(
func main() -> i32
{
    print("{}\n", 10)
    return 0
}
)"sv;

DEBUG_VAR constexpr static CppProgram = R"(
int main()
{
    fmt::print("{}\n", 10);
    return 0;
}
)"sv;

BOOST_AUTO_TEST_CASE(Print, *utf::depends_on("MainCompilation"))
{
    BOOST_ASSERT(fsc::compareProgramsOutput(FscProgram, CppProgram));
}