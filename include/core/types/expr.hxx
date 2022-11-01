#ifndef LIX_EXPR
#   define LIX_EXPR

#include <optional>
#include <vector>

#include <core/types/types.hxx>

namespace lix::core::types
{
    class Expr
    {
    public:
        enum class ExprType : short
        { Sexpr, Qexpr };

        using Children          = std::vector<Value>;

    private:
        ExprType type;
        Children children;
    };
}

#endif  /// LIX_EXPR
