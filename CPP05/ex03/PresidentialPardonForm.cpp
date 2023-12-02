#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) : AForm(rhs), _target(rhs._target)
{
	*this = rhs;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	this->_target = rhs._target;
	return(*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecAuth())
		throw AForm::GradeTooLowException();
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	std::cout << "Congratulations " << this->_target << "! You have been officially pardoned by our Glorious Leader, Zaphod Beeblebrox. For what you ask? You know what you did." << std::endl;
}