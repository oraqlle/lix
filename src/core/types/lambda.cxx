#include <core/types/types.hxx>

namespace lix::core::types
{
    class Lambda
    {
    public:
        using Parameters            = Qexpr;
        using Body                  = Qexpr;

    private:
        Parameters formals;
        Body body;
    };
}
