#include "codegen.hpp"
#include "ast/basic_node.hpp"
#include "function/argument.hpp"
#include "type/type.hpp"
#include <ccl/flatmap.hpp>
#include <ranges>

namespace fsc::gen
{
    using namespace std::string_view_literals;

    constexpr static auto ScopeStr = "    "sv;

    auto CodeGenerator::operator<<(char chr) -> CodeGenerator &
    {
        if (chr == '\n') {
            newLine();
        } else {
            generated.push_back(chr);
        }

        return *this;
    }

    auto CodeGenerator::operator<<(std::string_view str) -> CodeGenerator &
    {
        bool need_to_add_new_line = false;

        for (const auto word : std::views::split(str, '\n')) {
            if (need_to_add_new_line) {
                newLine();
            }

            need_to_add_new_line = true;
            generated.append(std::string_view{word});
        }

        return *this;
    }

    auto CodeGenerator::operator<<(const std::string &str) -> CodeGenerator &
    {
        return *this << std::string_view{str};
    }

    auto CodeGenerator::operator<<(const Argument &argument) -> CodeGenerator &
    {
        const auto category = argument.getCategory();
        const auto &name = argument.getName();
        const auto &type_name = FscType::getTypeName(argument.getType());
        const auto type_id = argument.getType();
        const auto is_trivially_copiable = FscType::isTriviallyCopyable(type_id);

        if (category == ArgumentCategory::IN || category == ArgumentCategory::INOUT) {
            *this << "const ";
        }

        *this << type_name << ' ';

        if ((!is_trivially_copiable && category == ArgumentCategory::IN) ||
            category == ArgumentCategory::OUT || category == ArgumentCategory::INOUT) {
            *this << "&";
        }

        *this << name;

        return *this;
    }

    auto CodeGenerator::operator<<(const ast::Node &node) -> CodeGenerator &
    {
        node.codeGen(*this);
        return *this;
    }

    auto CodeGenerator::operator<<(const FscType &fsc_type) -> CodeGenerator &
    {
        fsc_type.codeGen(*this);
        return *this;
    }

    auto CodeGenerator::operator<<(PushScope /* unused */) -> CodeGenerator &
    {
        pushScope();
        return *this;
    }

    auto CodeGenerator::operator<<(PopScope /* unused */) -> CodeGenerator &
    {
        popScope();
        return *this;
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
}// namespace fsc::gen
