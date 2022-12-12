#ifndef FSC_UUID_FACTORY_HPP
#define FSC_UUID_FACTORY_HPP

#include <atomic>
#include <cinttypes>

namespace fsc
{
    class UuidFactory
    {
    public:
        auto operator()() -> ccl::Id
        {
            return std::atomic_fetch_add_explicit(&current_id, 1U, std::memory_order_relaxed);
        }

    private:
        std::atomic<ccl::Id> current_id{1};
    };
}// namespace fsc

#endif /* FSC_UUID_FACTORY_HPP */
