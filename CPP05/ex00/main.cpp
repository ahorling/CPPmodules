#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat Jeff("Jeff", 72);
    Bureaucrat Joe("Joe", 1);
    Bureaucrat Jack("Jack", 150);

    std::cout << Jeff << std::endl;
    std::cout << Joe << std::endl;
    std::cout << Jack << std::endl;

    try
    {
        Bureaucrat JoJo("JoJo", 420);
    }
    catch(const std::exception& e)
    {
        std::cerr << "JoJo failed his job interview" << "\n\n";
    }

    try
    {
        Bureaucrat Fred("Fred", -12);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Fred is not welcome here" << "\n\n";
    }

    std::cout << "Jeff's grade is: " << Jeff.getGrade() << std::endl;
    Jeff.upgrade();
    std::cout << "If he were to be promoted he would be at grade: " << Jeff.getGrade() << std::endl;
    Jeff.downgrade();
    Jeff.downgrade();
    std::cout << "Unfortunately he was actually demoted, so now he's just a grade " << Jeff.getGrade() << std::endl;
    
    try
    {
        std::cout << "Joe's grade is: " << Joe.getGrade() << std::endl;
        Joe.upgrade();
        std::cout << "If he were to be promoted he would be at grade: " << Joe.getGrade() << std::endl;
        Joe.downgrade();
        Joe.downgrade();
        std::cout << "Unfortunately he was actually demoted, so now he's just a grade " << Joe.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: JOE IS ALREADY AT THE TOP" << "\n\n";
    }
    
    try
    {
        std::cout << "Jack's grade is: " << Jack.getGrade() << std::endl;
        Jack.upgrade();
        std::cout << "If he were to be promoted he would be at grade: " << Jack.getGrade() << std::endl;
        Jack.downgrade();
        Jack.downgrade();
        std::cout << "Unfortunately he was actually demoted, so now he's just a grade " << Jack.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: JACK HAS BEEN FIRED" << "\n\n";
    }

    return (0);
}