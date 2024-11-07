#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const	std::string	_name;
		bool				_isSigned;
		const	int			_grade_sign;
		const	int			_grade_exec;

	public:

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
	
		// Constructors and Destructor
		Form();
		Form(const std::string name, const int grade_sign, const int  grade_exec);
		~Form();

		// Operators
		Form(const Form & form);
		Form & operator=(const Form & form);

		// Getters 
		const std::string getName() const;
		bool getIsSigned() const;
		int getNeededSignGrade() const;
		int getNeededExecGrade() const;
		
		// Methods
		void beSigned(const Bureaucrat &bureu);
		
};

std::ostream &operator<<(std::ostream& os, const Form &form);
#endif