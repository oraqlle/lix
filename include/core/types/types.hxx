#ifndef LIX_TYPES
#   define LIX_TYPES

#include <functional>
#include <memory>
#include <string>
#include <variant>

namespace lix::core::types
{
    /// Primitive Data types
    using None          = std::monostate;
    using Int           = int;
    // using Float         = double;
    // using String        = std::string;

    /// Expr Type
    class Expr;

    /// Error Type
    class Error 
    : public std::string {};

    /// Symbol Type
    class Symbol
    : std::string {};

    /// Comment Type
    // struct Comment {};

    /// S-Expression Type
    using Sexpr = std::vector<std::unique_ptr<Expr>>;

    /// Q-Expression Type
    // class Qexpr;

    /// Environment Type
    // class Env;

    /// Builtin Function Type
    // using Function = std::function<Expr(Expr)>;

    /// Lambda Type
    // class Lambda;

    /// Cell Type
    using Cell = std::variant<None, Int, Error, Symbol, Expr>;
}

#endif  /// LIX_TYPES
