/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:57:43 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/28 13:40:13 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void)
{ 
	Bureaucrat	_bureu1("Pedro", 2);
	Bureaucrat	_bureu2("Sandra", 14);
	Bureaucrat	_bureu3("Miguel", 33);
	Bureaucrat	_bureu4("Ana", 53);
	Bureaucrat	_bureu5("Juan", 148);
	
	std::cout<< std::endl << "- - - - - - - - - - - - - - - - - - "<<std::endl;
	std::cout<< "- - PresidentialPardonForm test - - "<<std::endl;
	std::cout<< "- - - - - - - - - - - - - - - - - - "<<std::endl;
	{	
		PresidentialPardonForm	form("PresidentialPardon");
		_bureu3.signForm(form);
		_bureu2.signForm(form);
		_bureu2.executeForm(form);
		_bureu1.executeForm(form);
	}
	std::cout<< std::endl << "- - - - - - - - - - - - - - - - - - "<<std::endl;
	std::cout<< "- - RobotomyRequestForm test - - "<<std::endl;
	std::cout<< "- - - - - - - - - - - - - - - - - - "<<std::endl;
	{	
		RobotomyRequestForm	form("RobotomyRequest");
		_bureu5.signForm(form);
		_bureu4.signForm(form);
		_bureu4.executeForm(form);
		_bureu3.executeForm(form);
	}

	std::cout<< std::endl << "- - - - - - - - - - - - - - - - - - "<<std::endl;
	std::cout<< "- - ShrubberyCreationForm test - - "<<std::endl;
	std::cout<< "- - - - - - - - - - - - - - - - - - "<<std::endl;
	{	
		ShrubberyCreationForm	form("ShrubberyCreationForm");
		_bureu5.signForm(form);
		_bureu4.signForm(form);
		_bureu4.executeForm(form);
	}
	return (0);
}