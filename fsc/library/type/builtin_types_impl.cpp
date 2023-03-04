#include "type/builtin_types_impl.hpp"

namespace fsc
{
    template class FscBuiltinType<VoidType>;

    template class FscBuiltinType<FscInt32>;
    template class FscBuiltinType<FscInt64>;

    template class FscBuiltinType<FscUInt32>;
    template class FscBuiltinType<FscUInt64>;

    template class FscBuiltinType<ReprOrValue<ccl::f32>>;
    template class FscBuiltinType<ReprOrValue<ccl::f64>>;

    template class FscBuiltinType<FscBool>;

    template class FscBuiltinType<FscString>;

}// namespace fsc
