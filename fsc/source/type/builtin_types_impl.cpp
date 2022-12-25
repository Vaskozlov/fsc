#include "type/builtin_types_impl.hpp"

namespace fsc
{
    template class FscBuiltinType<Int32>;
    template class FscBuiltinType<Int64>;

    template class FscBuiltinType<UInt32>;
    template class FscBuiltinType<UInt64>;

    template class FscBuiltinType<Float32>;
    template class FscBuiltinType<Float64>;

    template class FscBuiltinType<Bool>;

    template class FscBuiltinType<String>;
}// namespace fsc
