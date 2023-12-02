#ifndef PPF_HPP
# define PPF_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

	std::string	_target;
	PresidentialPardonForm();

	public:

	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &rhs);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

	virtual void	execute(Bureaucrat const &executor) const;
};

#endif