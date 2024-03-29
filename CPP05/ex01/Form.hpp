#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
    
    std::string const	_name;
    bool                _signed;
    int const           _signauth;
    int const           _execauth;
    Form();

	public:

    Form(std::string const &name, int const signauth, int const execauth);
    Form(Form const &src);
    ~Form();


    Form &operator=(Form const &rhs);

    std::string getName() const;
    bool        getSigned() const;
    int         getSignAuth() const;
    int         getExecAuth() const;

    void        beSigned(Bureaucrat const &signer);
    
    class GradeTooHighExcpetion : public std::exception
    {
        public: 
        char const *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
        char const *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif