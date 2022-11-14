#include <core/utils/readline.hxx>


#ifdef _WIN32
    #include <stdio.h>

    static char buffer[2048];

    char* readline(char* prompt) 
    {
        fputs(prompt, stdout);
        fgets(buffer, 2048, stdin);
        char* cpy = malloc(strlen(buffer) + 1);
        strcpy(cpy, buffer);
        cpy[strlen(cpy)-1] = '\0';
        return cpy;
    }

    void add_history(char* unused) {}
#endif  /// _WIN32
