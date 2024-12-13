#include <stack>
#include "RPN.hpp"

RPN::RPN()  {};

RPN::~RPN() {};

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this == &other)
        return (*this);
    this->RPNStack = other.RPNStack;
    return(*this);
}

int checkInput(char c)
{
    if (c == '+')
        return(PLUS);
    else if (c == '-')
        return(MINUS);
    else if (c == '*')
        return(MULT);
    else if (c == '/')
        return(DIV);
    else if (c == ' ')
        return(SPACE);
    else if (c >= '0' && c <= '9')
        return(DIGIT);
    else
        throw std::runtime_error("Invalid input");
    return(-1);
}

void    RPN::calc(const std::string &equation)
{
    std::string::const_iterator itbegin = equation.begin();
    std::string::const_iterator itend = equation.end();
    while (itbegin != itend)
    {
        switch (checkInput(*itbegin))
        {
            case PLUS:
                this->add();
                break;
            case MINUS:
                this->subtract();
                break;
            case MULT:
                this->multiply();
                break;
            case DIV:
                this->divide();
                break;
            case SPACE:
                break;
            case DIGIT:
                RPNStack.push(*itbegin - '0');
                break;
            case -1:
                throw std::runtime_error("How did you even get here?");
        }
        itbegin++;
    }
    if (RPNStack.empty())
        throw std::runtime_error("How did you end up with an empty stack at the end?");
    if (RPNStack.size() > 1)
        throw std::runtime_error("there's still more stuff in stack, how did you get here?");
    std::cout << RPNStack.top() << std::endl;
}

void    RPN::add()
{
    if (this->RPNStack.size() < 2)
        throw std::runtime_error("not enough numbers in stack to complete operation");
    size_t result;
    size_t b = this->RPNStack.top();
    RPNStack.pop();
    size_t a = this->RPNStack.top();
    RPNStack.pop();
    result = a + b;
    RPNStack.push(result);
    std::cout << a << " + " << b << " = " << result << std::endl;
}

void    RPN::subtract()
{
    if (this->RPNStack.size() < 2)
        throw std::runtime_error("not enough numbers in stack to complete operation");
    size_t result;
    size_t b = this->RPNStack.top();
    RPNStack.pop();
    size_t a = this->RPNStack.top();
    RPNStack.pop();
    result = a - b;
    RPNStack.push(result);
    std::cout << a << " - " << b << " = " << result << std::endl;
}

void    RPN::multiply()
{
    if (this->RPNStack.size() < 2)
        throw std::runtime_error("not enough numbers in stack to complete operation");
    size_t result;
    size_t b = this->RPNStack.top();
    RPNStack.pop();
    size_t a = this->RPNStack.top();
    RPNStack.pop();
    result = a * b;
    RPNStack.push(result);
    std::cout << a << " * " << b << " = " << result << std::endl;
}

void    RPN::divide()
{
    if (this->RPNStack.size() < 2)
        throw std::runtime_error("not enough numbers in stack to complete operation");
    size_t result;
    size_t b = this->RPNStack.top();
    if (b == 0)
        throw std::runtime_error("You just divided by 0, activating my face-down trap card! I activate 'throwing an exception!', destroying your attempt at breaking my code!");
    RPNStack.pop();
    size_t a = this->RPNStack.top();
    RPNStack.pop();
    result = a / b;
    RPNStack.push(result);
    std::cout << a << " / " << b << " = " << result << std::endl;
}