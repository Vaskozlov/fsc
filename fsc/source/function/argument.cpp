#include "function/argument.hpp"

namespace fsc::func {
    const std::map<std::string, ArgumentCategory, std::less<>> ArgumentCategories{
            {"in", ArgumentCategory::IN},
            {"inout", ArgumentCategory::INOUT},
            {"out", ArgumentCategory::OUT},
            {"copy", ArgumentCategory::COPY},
    };
}
