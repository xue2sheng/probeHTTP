#include "main_function.h"
#include <iostream>

int main_function(int argc, char** argv)
{
    std::cout << "argc: " << argc << " argv: ";
    for(std::size_t i=0; i<argc; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
