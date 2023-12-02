#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat	Jeff("Jeff", 60);
    Bureaucrat	Joe("Joe", 1);
    
    ShrubberyCreationForm		Shrub("Space");
	RobotomyRequestForm			Robot("Greg");
	PresidentialPardonForm		Pardon("Evaluator");

	std::cout << Jeff << std::endl;
	std::cout << Joe << std::endl;
	std::cout << Shrub << std::endl;
	std::cout << Robot << std::endl;
	std::cout << Pardon << '\n' << std::endl;

	try
	{
		std::cout << "Jeff can sign the shrub form" << std::endl;
		Jeff.signForm(Shrub);
		std::cout << "He can also execute it all by himself!" << std::endl;
		Jeff.executeForm(Shrub);
		std::cout << "Look at all those shrubs floating in space... Good Job, Jeff!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------------------------\n\n";

	try
	{
		std::cout << "Jeff can also sign the robotomy form" << std::endl;
		Jeff.signForm(Robot);
		std::cout << "However, he can't execute it all by himself. Look what happens when he tries!" << std::endl;
		Jeff.executeForm(Robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "Joe can execute the robotomy form however." << std::endl;
		Joe.executeForm(Robot);
		std::cout << "Good Job, Joe." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------------------------\n\n";
	
	try
	{
		std::cout << "Jeff can't even sign the pardon form" << std::endl;
		Jeff.signForm(Pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "so now Joe is going to have to do all the work" << std::endl;
		Joe.signForm(Pardon);
		Joe.executeForm(Pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return (0);
}