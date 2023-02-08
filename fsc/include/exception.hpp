#ifndef FSC_EXCEPTION_HPP
#define FSC_EXCEPTION_HPP

#include <exception>
#include <stdexcept>

namespace fsc
{
    class FscException : public std::runtime_error
    {
    public:
        template<typename... Ts>
        FscException(Ts &&...args)
          : std::runtime_error{std::forward<Ts>(args)...}
        {}
    };
}// namespace fsc

#endif /* FSC_EXCEPTION_HPP */
