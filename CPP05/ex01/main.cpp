#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat	Jeff("Jeff", 72);
    Bureaucrat	Joe("Joe", 1);
    
    Form		formA("formA", 80, 1);
	Form		formB("formB", 1, 1);

	std::cout << Jeff << std::endl;
	std::cout << Joe << std::endl;
	std::cout << formA << std::endl;
	std::cout << formB << '\n' << std::endl;

	try
	{
		std::cout << "Can Jeff sign form A?" << std::endl;
		formA.beSigned(Jeff);
		std:: cout << "Yes he can!" << std::endl;
		Jeff.signForm(formA);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nformA's signed status: " << formA.getSigned() << "\n\n";

	try
	{
		std::cout << "Can Jeff sign form B?" << std::endl;
		formB.beSigned(Jeff);
	}
	catch(const std::exception& e)
	{
		std::cerr << "No he couldn't. This attempt at overreaching his station will be reported."<< '\n' << std::endl;
	}
	
	std::cout << "formB's signed status: " << formB.getSigned() << "\n\n";

	try
	{
		std::cout << "How about Joe, can he sign form B?" << std::endl;
		formB.beSigned(Joe);
		std:: cout << "Yes he can!\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "formB's signed status: " << formB.getSigned() << "\n\n";

	//Form FormF("FormF", 0, 200);

    return (0);
}