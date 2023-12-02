#include "AForm.hpp"

AForm::AForm(): _signauth(0), _execauth(0)
{
}

AForm::AForm(std::string const &name, int const signauth, int const execauth): _name(name), _signauth(signauth), _execauth(execauth)
{
	if (_signauth <= 0 || _execauth <= 0)
		throw AForm::GradeTooHighExcpetion();
	else if (_signauth >= 151 || _execauth >= 151)
		throw AForm::GradeTooLowException();
    this->_signed = false;
}

AForm::AForm(AForm const &rhs) : _name(rhs._name), _signed(rhs._signed), _signauth(rhs._signauth), _execauth(rhs._execauth)
{
    *this = rhs;
}

AForm::~AForm()
{
}

AForm	&AForm::operator=(AForm const &rhs)
{
	this->_signed = rhs._signed;
	return(*this);
}

std::string	        AForm::getName() const
{
    return(this->_name);
}

bool				AForm::getSigned() const
{
    return(this->_signed);
}

int					AForm::getExecAuth() const
{
    return(this->_execauth);
}

int					AForm::getSignAuth() const
{
    return(this->_signauth);
}

char const	    *AForm::GradeTooHighExcpetion::what() const throw()
{
	return ("Grade too high");
}

char const	    *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

void	AForm::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() <= this->_signauth)
		_signed = true;
	else if (signer.getGrade() > this->_signauth)
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, AForm const &AForm)
{
    out << AForm.getName() << " is signed: " << AForm.getSigned() << ", with a signage autherization of grade: " << AForm.getSignAuth() << " and an execution autherization of grade: " << AForm.getExecAuth();
    return(out);
}

char const		*AForm::NotSignedException::what() const throw()
{
	return ("Form not signed!!!");
}