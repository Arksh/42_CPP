#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string str) : AForm(str, 145, 137) { return; }

ShrubberyCreationForm::~ShrubberyCreationForm() { return; }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form) { return; }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
    if (this != &form)
        return *this;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if (getNeededExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::NoSignException();
    
    this->executeAction();
}


void ShrubberyCreationForm::executeAction()
{
    
    std::string test = this->getName()+"_ShrubberyCreationForm.txt" ;
    std::ofstream newfile( test.c_str() );
    if (!newfile.is_open())
    {
        std::cerr << "Error: Could not create file " << test << std::endl;
        return;
    }

    newfile << "       _-_" << std::endl;
    newfile << "    /~~   ~~\\" << std::endl;
    newfile << " /~~         ~~\\" << std::endl;
    newfile << "{               }" << std::endl;
    newfile << " \\  _-     -_  /" << std::endl;
    newfile << "   ~  \\\\ //  ~" << std::endl;
    newfile << "_- -   | | _- _" << std::endl;
    newfile << "  _ -  | |   -_" << std::endl;
    newfile << "      // \\\\" << std::endl;
    newfile.close();
    std::cout << "File -> "<< test << " created suscefully check the directory" << std::endl;	
}