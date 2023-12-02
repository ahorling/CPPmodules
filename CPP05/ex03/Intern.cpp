#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &rhs)
{
	*this = rhs;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return(*this);
}

int		FormExists(std::string const &name)
{
	std::string	formlist[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	for (int i = 0; i < (int)(sizeof(formlist)/sizeof(formlist[0])); i++)
	{
		if (name == formlist[i])
			return(i);
	}
	return (-1);
}

AForm	*Intern::makeForm(std::string const &name, std:: string const &target) const
{
	AForm *Form;

	switch (FormExists(name))
	{
		case -1:
			throw Intern::IncorrectFormException();
		case 0:
			Form = new ShrubberyCreationForm(target);
			break;
		case 1:
			Form = new RobotomyRequestForm(target);
			break;
		case 2:
			Form = new PresidentialPardonForm(target);
			break;
	}
	std::cout << "A random, unimportant intern creates a " << *Form << ". Good job!" << std::endl;
	return (Form);
}

const char	*Intern::IncorrectFormException::what() const throw()
{
	return ("Incorrect form. please do it properly next time.");
}