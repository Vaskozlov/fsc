#include "visibility.hpp"

namespace fsc
{
    using namespace std::string_view_literals;

    auto genVisibility(Visibility visibility, ccl::codegen::BasicCodeGenerator &output) -> void
    {
        switch (visibility) {
        case Visibility::PUBLIC:
            output << "public:"sv;
            break;

        case Visibility::PROTECTED:
            output << "protected:"sv;
            break;

        case Visibility::EXPORT:
            throw std::logic_error("Export visibility is not available at the moment");

        default:
            output << "private: "sv;
            break;
        }

        output << ccl::codegen::endl;
    }
}// namespace fsc