#ifndef AFORM_HPP
# define AFORM_HPP

# include <iomanip>
# include <iostream>
# include <fstream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const	std::string	_name;
		bool				_isSigned;
		const	int			_grade_sign;
		const	int			_grade_exec;

	protected:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoSignException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		virtual void executeAction();
	
	public:
		// Constructors and Destructor
		AForm(std::string name, int grade_sign, int  grade_exec);
		virtual ~AForm();

		// Operators
		AForm(const AForm & form);
		AForm & operator=(const AForm & form);

		// Getters 
		std::string getName() const;
		int getNeededSignGrade() const;
		int getNeededExecGrade() const;
		bool getIsSigned() const;
		
		// Methods
		void beSigned(const Bureaucrat &bureu);
		virtual void execute(const Bureaucrat & executor) = 0;		
};

std::ostream &operator<<(std::ostream& os, const AForm &form);

#endif