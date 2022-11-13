#include <map>
#include <string>

#include <core/types/types.hxx>

namespace lix::core::types
{
    class Env
    {
    public:
        Env()                               = default;
        Env(const Env& env)                 = default;
        Env(Env&& env)                      = default;
        Env& operator= (const Env& env)     = default;
        Env& operator= (Env&& env)          = default;
        ~Env()                              = default;

    private:
        std::map<std::string, Expr> syms;
    };
}
