#include "debug/debug.hpp"

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
        fmt::print("S has been constructed");
    }

    ~S()
    {
        fmt::print("S has been deleted");
    }
};

int main()
{
    [[maybe_unused]] const auto s = S();
    return 0;
}
)"sv;

BOOST_AUTO_TEST_CASE(ClassCreation, *utf::depends_on("FunctionCreation"))
{
    BOOST_ASSERT(fsc::compareProgramsOutput(FscProgram, CppProgram));
}