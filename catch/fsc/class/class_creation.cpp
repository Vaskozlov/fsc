#include "debug/debug.hpp"
#include <ccl/debug/debug_file.hpp>

using namespace std::literals;

DEBUG_VAR constexpr static FscProgram = R"(
class S
{
    public func __init__()
    {
        print("S has been constructed")
    }

    public func __del__()
    {
        print("S has been deleted")
    }
}

func main() -> i32
{
    let s = S()
    return 0
}
)"sv;

DEBUG_VAR constexpr static CppProgram = R"(
class S
{
public:
    S()
    {
        fmt::print("S has been constructed\n");
    }

    ~S()
    {
        fmt::print("S has been deleted\n");
    }
};

int main()
{
    [[maybe_unused]] const auto s = S();
    return 0;
}
)"sv;

TEST_CASE("ClassCreation", "[FSC]")
{
    REQUIRE(fsc::compareProgramsOutput(FscProgram, CppProgram));
}