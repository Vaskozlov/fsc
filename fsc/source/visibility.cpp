#include "visibility.hpp"
#include <codegen.hpp>

namespace fsc
{
    using namespace std::string_view_literals;

    auto genVisibility(Visibility visibility, gen::CodeGenerator &output) -> void
    {
        output.newLine();

        switch (visibility) {
        case Visibility::PUBLIC:
            output.write("public:"sv);
            break;

        case Visibility::PROTECTED:
            output.write("protected:"sv);
            break;

        case Visibility::EXPORT:
            throw std::logic_error("Export visibility is not available at the moment");

        default:
            output.write("private: "sv);
            break;
        }

        output.newLine();
    }
}// namespace fsc
