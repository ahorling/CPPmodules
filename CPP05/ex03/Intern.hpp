#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class AForm;

class Intern
{
	public:

	Intern();
	Intern(Intern const &rhs);
	~Intern();

	Intern &operator=(Intern const &other);

	AForm	*makeForm(std::string const &formName, std::string const &formTarget) const;

	class IncorrectFormException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

#endif