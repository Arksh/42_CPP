/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:59:54 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/20 13:48:23 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include<iomanip>
#include<iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
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

	public:
		Bureaucrat				( std::string str, int i );
		~Bureaucrat				( void );
		Bureaucrat				( const Bureaucrat & bureu );

		Bureaucrat operator=	( const Bureaucrat & bureu );
		std::string getName		( void ) const;

		int getGrade			( void ) const;
		void increaseGrade		( void );
		void decreaseGrade		( void );
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureu);
#endif
