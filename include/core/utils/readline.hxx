#ifndef LIX_READLINE
#   define LIX_READLINE

#ifdef _WIN32

    char* readline(char* prompt);

    void add_history(char* unused);

#else
    #include <editline/readline.h>
    #include <editline/history.h>
#endif

#endif  /// LIX_READLINE
