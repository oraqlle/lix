#include <memory>
#include <optional>
#include <queue>
#include <variant>
#include <vector>

#include <core/types/types.hxx>
#include <core/types/expr.hxx>

namespace lix::core::types
{
    class Value
    {
    public:
        using Cell              = std::variant<std::monostate,
                                               Data, 
                                               Error, 
                                               Symbol,
                                               Comment,
                                               Builtin,
                                               Expr>;

    public:
        Value() = delete;

        Value(const Value& other) = default;

        Value(Value&& other) = default;

        explicit Value(Data&& data)
        : cell{ Data{ data } }
        {}

        explicit Value(Error&& err)
        : cell{ Error{ err } }
        {}

        explicit Value(Symbol&& sym)
        : cell{ Symbol{ sym } }
        {}

        explicit Value(Comment&& com)
        : cell{ Comment{ com } }
        {}

        explicit Value(Builtin&& fun)
        : cell{  Builtin{ fun } }
        {}

        explicit Value(Expr&& expr)
        : cell{ Expr{ expr } }
        {}

    private:
        Cell cell;
    };
}
