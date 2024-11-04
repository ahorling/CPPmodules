#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "only provide the executable and a single number please." << std::endl;
        return (1);
    }

    Converter::convert(argv[1]);
    return(0);
}