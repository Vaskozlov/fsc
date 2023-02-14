#include "debug/debug.hpp"

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

BOOST_AUTO_TEST_CASE(FunctionCreation, *utf::depends_on("Print"))
{
    BOOST_ASSERT(fsc::compareProgramsOutput(FscProgram, CppProgram));
}