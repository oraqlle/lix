#include <string>
#include <vector>

#include <core/types/types.hxx>

namespace lix::core::types
{
    class Env
    {
    public:
        Env() = default;
        Env(const Env& env) = default;
        Env(Env&& env) = default;
        Env& operator= (const Env& env) = default;
        Env& operator= (Env&& env) = default;

    private:
        std::vector<std::string> syms;
        std::vector<Expr> vals;
    };
}
