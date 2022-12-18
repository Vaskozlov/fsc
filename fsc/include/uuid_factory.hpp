#ifndef FSC_UUID_FACTORY_HPP
#define FSC_UUID_FACTORY_HPP

#include <atomic>
#include <ccl/ccl.hpp>

namespace fsc
{
    class UuidFactory
    {
    private:
        std::atomic<ccl::Id> counter{1};

    public:
        explicit UuidFactory(ccl::Id counter_begin)
          : counter{counter_begin}
        {}

        CCL_INLINE auto operator()() -> ccl::Id
        {
            return std::atomic_fetch_add_explicit(&counter, 1U, std::memory_order_relaxed);
        }
    };
}// namespace fsc

#endif /* FSC_UUID_FACTORY_HPP */
