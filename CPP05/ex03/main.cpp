#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat	Joe("Joe", 1);
    Intern		notImportant;
	AForm		*Shrub;
	AForm		*Pardon;
	AForm		*Robot;
	AForm		*whoops;

	std::cout << "Jeff has been replaced by an intern due to poor performance. The Intern will now create a few forms" << std::endl;

	try
	{
		Shrub = notImportant.makeForm("Shrubbery Creation", "The Park");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Pardon = notImportant.makeForm("Presidential Pardon", "Evaluatee");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



	try
	{
		Robot = notImportant.makeForm("Robotomy Request", "Deez");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	


	std::cout << "now Joe can sign and execute all those forms!" << std::endl;

	try
	{
		Joe.signForm(*Shrub);
		Joe.signForm(*Pardon);
		Joe.signForm(*Robot);
		Joe.executeForm(*Shrub);
		Joe.executeForm(*Pardon);
		Joe.executeForm(*Robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "The intern does mess up occasionally, though..." << std::endl;

	try
	{
		whoops = notImportant.makeForm("Presidential Creation", "Deez");

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}