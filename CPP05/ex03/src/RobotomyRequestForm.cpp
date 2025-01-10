#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string str) : AForm(str, 25, 5) { return; }

RobotomyRequestForm::~RobotomyRequestForm() { return; }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form) { return; }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
		return *this;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (getNeededExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::NoSignException();
	
	this->executeAction();
}

void RobotomyRequestForm::executeAction()
{
	int n_generated;

	srand (time(NULL));
	n_generated = rand() % 100;
	if (n_generated < 50)
		std::cout << "Target "<<this->getName() << " has been robotomized successfully" <<std::endl;
	else
		std::cout << "Target "<<this->getName() <<  " failed to be robotimized" <<std::endl;
}