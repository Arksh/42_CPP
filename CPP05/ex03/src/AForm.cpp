#include "AForm.hpp"

// Constructors
AForm::AForm(std::string name, int grade_sign, int  grade_exec) : _name(name), _isSigned(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (_grade_sign > 150 || _grade_exec > 150)
		throw AForm::GradeTooLowException();
	if (_grade_sign < 1 || _grade_exec < 1)
		throw AForm::GradeTooHighException();
	return ;
}

// Deep Copy Constructor
AForm::AForm(const AForm &form) : _name(form.getName()), _isSigned(form.getIsSigned()), _grade_sign(form.getNeededSignGrade()), _grade_exec(form.getNeededExecGrade())
{ return; }


// Destructor
AForm::~AForm() { return; }


// Operators
AForm & AForm::operator=(const AForm &form)
{
	if (this == &form)
		return (*this);
	return (*this);
}

std::ostream &operator<<(std::ostream& os, const AForm &form)
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
const char* AForm::GradeTooHighException::what() const throw()
{
	return ( "Form Grade is to high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ( "Form Grade is to low");
}

const char* AForm::NoSignException::what() const throw()
{
	return ( "form isn't signed");
}


// Getters 
std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getNeededSignGrade() const
{
	return (this->_grade_sign);
}
int AForm::getNeededExecGrade() const
{
	return (this->_grade_exec);
}


//Functions
void AForm::beSigned(const Bureaucrat &bureu)
{
	if (getNeededSignGrade() < bureu.getGrade())
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

void AForm::executeAction(void)
{
	std::cout<< "Form "<<this->getName()<< " was executed."<<std::endl;	
}