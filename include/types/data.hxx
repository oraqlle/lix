#ifndef LIX_DATA
#   define LIX_DATA 

#include <variant>

#include <types/float.hxx>
#include <types/int.hxx>
#include <types/string.hxx>

namespace lix::core::types
{
    using Data = std::variant<Int, Float, String>;
}

#endif  /// LIX_DATA
