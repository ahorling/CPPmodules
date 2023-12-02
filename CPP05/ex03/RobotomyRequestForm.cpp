#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) : AForm(rhs), _target(rhs._target)
{
	*this = rhs;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	this->_target = rhs._target;
	return(*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecAuth())
		throw AForm::GradeTooLowException();
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	std::cout << "*** LOUD DRILLING NOISES ***" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 1)
		std::cout << this->_target << " Has survived the robotomization! congrats!" << std::endl;
	else
		std::cout << this->_target << " Has not survived the robotomization. How unfortunate." << std::endl;
}