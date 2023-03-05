#include "debug/debug.hpp"
#include <ccl/debug/debug_file.hpp>

using namespace std::literals;

DEBUG_VAR constexpr static FscProgram = R"(
func main() -> i32
{
    let i_32 = i32(10)
    let i_64 = i64(10)
    let u_32 = u32(10)
    let u_64 = u64(10)

    let f_32 = f32(10)
    let f_64 = f64(10)

    return 0
}
)"sv;

DEBUG_VAR constexpr static CppProgram = R"(
int main()
{
    return 0;
}
)"sv;

BOOST_AUTO_TEST_CASE(CoreTypes, *utf::depends_on("MainCompilation"))
{
    BOOST_ASSERT(fsc::compareProgramsOutput(FscProgram, CppProgram));
}