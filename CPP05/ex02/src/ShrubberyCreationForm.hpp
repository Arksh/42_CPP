#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	private:
		void executeAction();

	public:
		ShrubberyCreationForm(const std::string str);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm &form);
		
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);

        void execute(Bureaucrat const &executor);
};

#endif