#include "Form.hpp"

Form::Form(): _signauth(0), _execauth(0)
{
}

Form::Form(std::string const &name, int const signauth, int const execauth): _name(name), _signauth(signauth), _execauth(execauth)
{
	if (_signauth <= 0 || _execauth <= 0)
		throw Form::GradeTooHighExcpetion();
	else if (_signauth >= 151 || _execauth >= 151)
		throw Form::GradeTooLowException();
    this->_signed = false;
}

Form::Form(Form const &rhs) : _name(rhs._name), _signed(rhs._signed), _signauth(rhs._signauth), _execauth(rhs._execauth)
{
    *this = rhs;
}

Form::~Form()
{
}

Form	&Form::operator=(Form const &rhs)
{
	this->_signed = rhs._signed;
	return(*this);
}

std::string	        Form::getName() const
{
    return(this->_name);
}

bool				Form::getSigned() const
{
    return(this->_signed);
}

int					Form::getExecAuth() const
{
    return(this->_execauth);
}

int					Form::getSignAuth() const
{
    return(this->_signauth);
}

char const	    *Form::GradeTooHighExcpetion::what() const throw()
{
	return ("Grade too high");
}

char const	    *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

void	Form::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() <= this->_signauth)
		_signed = true;
	else if (signer.getGrade() > this->_signauth)
		throw Form::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, Form const &Form)
{
    out << Form.getName() << " is signed: " << Form.getSigned() << ", with a signage autherization of grade: " << Form.getSignAuth() << " and an execution autherization of grade: " << Form.getExecAuth();
    return(out);
}