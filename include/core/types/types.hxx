#ifndef LIX_TYPES
#   define LIX_TYPES

#include <functional>
#include <string>
#include <variant>

namespace lix::core::types
{
    /// Primitive Data types
    using Int           = int;
    using Float         = double;
    using String        = std::string;

    /// Error Type
    class Error 
    : public std::string {};

    /// Symbol Type
    class Symbol
    : std::string {};

    /// Comment Type
    struct Comment {};

    /// S-Expression Type
    class Sexpr;

    /// Q-Expression Type
    class Qexpr;

    /// Value Type
    class Value;

    /// Environment Type
    class Env;

    /// Builtin Function Type
    using Builtin       = std::function<Value(Env, Value)>;

    /// Lambda Type
    class Lambda;
}

#endif  /// LIX_TYPES
