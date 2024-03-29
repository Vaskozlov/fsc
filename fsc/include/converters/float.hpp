#ifndef FSC_FLOAT_HPP
#define FSC_FLOAT_HPP

#include "converters/int.hpp"

namespace fsc::converter
{
    auto toFloat(const std::string &repr, BasicContextPtr value_context)
        -> ccl::SharedPtr<ast::Value>;
}

#endif /* FSC_FLOAT_HPP */
