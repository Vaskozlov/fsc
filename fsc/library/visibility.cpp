#include "visibility.hpp"

namespace fsc
{
    using namespace std::string_view_literals;

    static auto genMethodVisibility(Visibility visibility, ccl::codegen::BasicCodeGenerator &output)
        -> void
    {
        if (visibility == Visibility::EXPORT) {
            throw std::logic_error("Export visibility is not available at the moment");
        }

        switch (visibility) {
        case Visibility::PUBLIC:
            output << "public:"sv;
            break;

        case Visibility::PROTECTED:
            output << "protected:"sv;
            break;

        default:
            output << "private: "sv;
            break;
        }

        output << ccl::codegen::endl;
    }

    auto genVisibility(Visibility visibility, ccl::codegen::BasicCodeGenerator &output) -> void
    {
        genMethodVisibility(visibility, output);
    }
}// namespace fsc
