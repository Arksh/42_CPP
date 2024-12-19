#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	private:
		void executeAction();

	public:
		PresidentialPardonForm(const std::string str);
		~PresidentialPardonForm();

		PresidentialPardonForm(const PresidentialPardonForm &form);
		
		PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
		void execute(Bureaucrat const & executor);

};

#endif