#include <lix/lix.hxx>

#include <iostream>
#include <string>

using namespace lix::core;

int main(int argc, char* argv[])
{
    if (argc == 1)
    {

        std::cout << "Lix v0.4.0\n";
        std::cout << "Press Ctrl+C or type \"quit\" to exit.\n";
        std::string input;

        while(std::getline(std::cin, input) && input != "quit")
        {
            types::Expr expr = io::read_expr(input);
            std::cout << expr << std::endl;
        }
    }

    return 0;
}
