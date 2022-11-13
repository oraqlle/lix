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

    using Data          = std::variant<Int, Float, String>;

    /// Error Type
    class Error 
    : public std::string {};

    /// Symbol Type
    class Symbol
    : std::string {};

    /// Comment Type
    class Comment
    : std::string {};

    /// Environment Type
    class Env;

    /// Expr Type
    class Expr;

    /// Value Type
    class Value;

    /// Builtin Function Type
    using Builtin       = std::function<Value(Env, Value)>;

    /// Lambda Type
    class Lambda;
}

#endif  /// LIX_TYPES
