#ifndef AForm_HPP
# define AForm_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
	
	std::string const	_name;
	bool                _signed;
	int const           _signauth;
	int const           _execauth;
	AForm();

	public:

	AForm(std::string const &name, int const signauth, int const execauth);
	AForm(AForm const &src);
	virtual ~AForm();


	AForm &operator=(AForm const &rhs);

	std::string 	getName() const;
	bool        	getSigned() const;
	int         	getSignAuth() const;
	int         	getExecAuth() const;

	void        	beSigned(Bureaucrat const &signer);
	virtual void    execute(Bureaucrat const &executor) const = 0;
	
	class GradeTooHighExcpetion : public std::exception
	{
		public: 
		char const *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		char const  *what() const throw();
	};

	class   NotSignedException : public std::exception
	{
		public:
		char const  *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &AForm);

#endif