#ifndef FSC_CODEGEN_HPP
#define FSC_CODEGEN_HPP

#include <string>

namespace fsc::gen {
    class CodeGenerator {
        std::string generated;
        std::string prefix;

    public:
        [[nodiscard]] auto getGenerated() const -> const std::string &
        {
            return generated;
        }

        [[nodiscard]] auto getBackInserter() -> std::back_insert_iterator<std::string>
        {
            return std::back_inserter(generated);
        }

        auto add(std::string &&str) -> void
        {
            generated.append(std::move(str));
        }

        auto add(const std::string_view &&str) -> void
        {
            generated.append(str);
        }

        auto add(char chr) -> void
        {
            generated.push_back(chr);
        }

        auto newLine() -> void
        {
            generated.push_back('\n');
            generated.append(prefix);
        }

        auto pushScope() -> void
        {
            using namespace std::string_view_literals;
            prefix.append("    "sv);
        }

        auto popScope() -> void
        {
            for (size_t i = 0; i != 4; ++i) {
                prefix.pop_back();
            }
        }

        auto openCurly() -> void
        {
            add('{');
        }

        auto closeCurly() -> void
        {
            add('}');
        }
    };
}// namespace fsc::gen

#endif /* FSC_CODEGEN_HPP */
