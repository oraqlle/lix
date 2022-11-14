#ifndef LIX_EXPR
#   define LIX_EXPR

#include <core/types/types.hxx>

#include <core/utils/match.hxx>

#include <string>
#include <utility>

using lix::core::types::Cell;
using lix::core::utils::match;

namespace lix::core::types
{
    class Expr
    {
    public:
        explicit Expr(Cell&& cell)
        : cell{std::move(cell)}
        {}

    public:
        Cell cell;
    };
}

#endif  /// LIX_EXPR
