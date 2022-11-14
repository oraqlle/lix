#ifndef LIX_LAMBDA
#   define LIX_LAMBDA

#include <core/types/types.hxx>

namespace lix::core::types
{
    class Lambda
    {
    public:
        using Parameters            = Qexpr;
        using Body                  = Qexpr;

    public:
        Lambda ()                               = default;
        Lambda (const Lambda& lambda)           = default;
        Lambda (Lambda&& lambda)                = default;
        Lambda& operator= (const Lambda& fun)   = default;
        Lambda& operator= (Lambda&& fun)        = default;

    private:
        // Parameters formals;
        // Body body;
    };
}

#endif  /// LIX_LAMBDA
