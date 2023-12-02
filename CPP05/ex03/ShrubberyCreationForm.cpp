#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm(rhs), _target(rhs._target)
{
	*this = rhs;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	this->_target = rhs._target;
	return(*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecAuth())
		throw AForm::GradeTooLowException();
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	
	std::ofstream shrubd((this->_target + "_shrubbery").c_str());

	if (!shrubd.is_open())
		throw ShrubberyCreationForm::FileFailedException();


	shrubd << "        ^         " << "       ^         " << "       ^         " << std::endl;
    shrubd << "       / \\       " << "       / \\       " << "       / \\       " << std::endl;
    shrubd << "      /   \\      " << "      /   \\      " << "      /   \\      " << std::endl;
    shrubd << "     /     \\     " << "     /     \\     " << "     /     \\     " << std::endl;
    shrubd << "    /_______\\    " << "    /_______\\    " << "    /_______\\    " << std::endl;
	shrubd << "       |||        " << "      |||        " << "      |||        " << std::endl;
	shrubd.close();
}

const char	*ShrubberyCreationForm::FileFailedException::what() const throw()
{
	return ("File issue detected");
}