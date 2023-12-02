#ifndef SCF_HPP
# define SCF_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:

	std::string	_target;
	ShrubberyCreationForm();

	public:

	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

	virtual void	execute(Bureaucrat const &executor) const;

	class FileFailedException : public std::exception
	{
		public:
		char const  *what() const throw();
	};
};

#endif