#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:

    std::string const   _name;
    int                 _grade;
    Bureaucrat();

    public:

    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const &src);
    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &rhs);

    std::string getName() const;
    int         getGrade() const;

    void        upgrade();
    void        downgrade();
    void        signForm(Form &tobesigned) const;

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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif