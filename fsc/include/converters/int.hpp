#ifndef FSC_INT_HPP
#define FSC_INT_HPP

#include "ast/value.hpp"
#include "type/builtin_types_impl.hpp"

namespace fsc::converter {
    auto toInt(const std::string &repr) -> std::shared_ptr<ast::Value>;
}

#endif /* FSC_INT_HPP */