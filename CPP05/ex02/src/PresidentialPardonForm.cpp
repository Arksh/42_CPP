#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(const std::string str) : AForm(str, 25, 5) { return; }

PresidentialPardonForm::~PresidentialPardonForm() { return; }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form) { return; }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
		return *this;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	if (getNeededExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::NoSignException();
	
	this->executeAction();
}

void PresidentialPardonForm::executeAction( void )
{
	std::cout << "Target "<<this->getName() << " has been pardoned by Imperator Julius \"the Eternal\"." <<std::endl;
}