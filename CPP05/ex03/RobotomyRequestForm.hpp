#ifndef RRF_HPP
# define RRF_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:

	std::string	_target;
	RobotomyRequestForm();

	public:

	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &rhs);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

	virtual void	execute(Bureaucrat const &executor) const;
};

#endif