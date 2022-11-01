#ifndef LIX_MATCH
#   define LIX_MATCH

namespace lix::core
{
    template<typename... Ms>
    struct match : Ms...
    { using Ms::operator()...; };

    template<typename... Ms>
    match(Ms...) -> match<Ms...>;
}

#endif  /// LIX_MATCH