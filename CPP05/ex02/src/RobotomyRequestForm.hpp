#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <stdlib.h>
# include <time.h>

class RobotomyRequestForm : public AForm
{

	private:
		void executeAction();

	public:
		RobotomyRequestForm(const std::string str);
		~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm &form);
		
		RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
		void execute(Bureaucrat const & executor);

};

#endif