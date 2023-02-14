#include "debug/debug.hpp"

using namespace std::literals;

DEBUG_VAR constexpr static FscProgram = R"(
func main() -> i32
{
    print("{}\n", 10 - 10)
    print("{}\n", 10.15151 - 10.15151)
    print("{}\n", 10.15151F64 - 10.15151F64)

    return 0
}
)"sv;

DEBUG_VAR constexpr static CppProgram = R"(
int main()
{
    fmt::print("{}\n", 10 - 10);
    fmt::print("{}\n", 10.15151F - 10.15151F);
    fmt::print("{}\n", 10.15151 - 10.15151);

    return 0;
}
)"sv;


BOOST_AUTO_TEST_CASE(Subtraction, *utf::depends_on("Print"))
{
    BOOST_ASSERT(fsc::compareProgramsOutput(FscProgram, CppProgram));
}