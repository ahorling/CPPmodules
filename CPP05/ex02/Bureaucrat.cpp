#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighExcpetion();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : _name(rhs._name)
{
    *this = rhs;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    this->_grade = rhs._grade;
    return(*this);
}

std::string Bureaucrat::getName() const
{
    return(this->_name);
}

int			Bureaucrat::getGrade() const
{
    return(this->_grade);
}

void		Bureaucrat::upgrade()
{
    if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighExcpetion();
	else
		this->_grade--;
}

void		Bureaucrat::downgrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

char const	*Bureaucrat::GradeTooHighExcpetion::what() const throw()
{
	return ("Grade too high");
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (out);
}

void        Bureaucrat::signForm(AForm &tobesigned) const
{
    if (this->_grade <= tobesigned.getSignAuth())
	{
		tobesigned.beSigned(*this);
        std::cout << this->_name << " signed " << tobesigned.getName() << std::endl;
	}
    else
        std::cout << this->_name << " couldn't sign " << tobesigned.getName() << " because their grade is too low." << std::endl;
}

void		Bureaucrat::executeForm(AForm const &tobeexecuted) const
{
	tobeexecuted.execute(*this);
	std::cout << _name << " has executed " << tobeexecuted.getName() << std::endl;
}