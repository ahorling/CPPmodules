#ifndef RPN_H
 #define RPN_H

#include <stack>
#include <iostream>

enum e_INPUT
{
    PLUS = 10,
    MINUS = 11,
    MULT = 12,
    DIV = 13,
    SPACE = 14,
    DIGIT = 1
};

class RPN
{
    private:
        std::stack<size_t> RPNStack;
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

    public:
        RPN();
        ~RPN();

        void add();
        void subtract();
        void divide();
        void multiply();
        void calc(const std::string &equation);
        void print();


};

#endif