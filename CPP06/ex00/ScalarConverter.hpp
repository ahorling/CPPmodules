#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

enum e_type
{
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
};

class Converter
{
    public:
        static void convert(const std::string &input);
};

#endif