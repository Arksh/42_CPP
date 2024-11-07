#include "Form.hpp"

// Constructors
Form::Form() : _name("Default"), _isSigned(false), _grade_sign(150), _grade_exec(150)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string name, const int grade_sign, const int  grade_exec) : _name(name), _isSigned(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (_grade_sign > 150 || _grade_exec > 150)
		throw Form::GradeTooLowException();
	if (_grade_sign < 1 || _grade_exec < 1)
		throw Form::GradeTooHighException();

	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
	return ;
}

// Deep Copy Constructor
Form::Form(const Form &form) : _name(form.getName()), _isSigned(form.getIsSigned()), _grade_sign(form.getNeededSignGrade()), _grade_exec(form.getNeededExecGrade())
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &form)
{
	if (this == &form)
		return (*this);
	return (*this);
}

std::ostream &operator<<(std::ostream& os, const Form &form)
{
	os << "Form : "<<form.getName()<< " requires a signing grade of "<< form.getNeededSignGrade();
	os << " and a execution grade of "<<form.getNeededExecGrade();
	if (form.getIsSigned() == true)
		os << " this form IS SIGNED";
	else
		os << " this form IS NOT SIGNED";
	return (os);
}


// Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
	return ( "Form Grade is to high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ( "Form Grade is to low");
}


// Getters 
const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getNeededSignGrade() const
{
	return (this->_grade_sign);
}
int Form::getNeededExecGrade() const
{
	return (this->_grade_exec);
}


//Functions
void Form::beSigned(const Bureaucrat &bureu)
{
	if (getNeededSignGrade() < bureu.getGrade())
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}