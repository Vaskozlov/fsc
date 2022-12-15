#include "codegen.hpp"

namespace fsc::gen
{
    using namespace std::string_view_literals;

    constexpr inline auto ScopeStr = "    "sv;

    auto CodeGenerator::write(const std::string &str) -> void
    {
        generated.append(str);
    }

    auto CodeGenerator::write(std::string_view str) -> void
    {
        generated.append(str);
    }

    auto CodeGenerator::write(char chr) -> void
    {
        generated.push_back(chr);
    }

    auto CodeGenerator::newLine() -> void
    {
        generated.push_back('\n');
        generated.append(prefix);
    }

    auto CodeGenerator::pushScope() -> void
    {
        prefix.append(ScopeStr);
    }

    auto CodeGenerator::popScope() -> void
    {
        for (auto i = ccl::as<size_t>(0); i != ScopeStr.size(); ++i) {
            prefix.pop_back();
        }
    }

    auto CodeGenerator::openCurly() -> void
    {
        write('{');
    }

    auto CodeGenerator::closeCurly() -> void
    {
        write('}');
    }
}// namespace fsc::gen
