/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:59:54 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/07 16:44:13 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iomanip>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;


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
		
		Bureaucrat				( std::string str, int i );
		~Bureaucrat				( void );
		Bureaucrat				( const Bureaucrat & bureu );

		Bureaucrat operator=	( const Bureaucrat & bureu );
		std::string getName		( void ) const;

		int getGrade			( void ) const;
		void increaseGrade		( void );
		void decreaseGrade		( void );
		void signForm			( Form &form );
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureu);
#endif
