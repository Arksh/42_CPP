/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:57:43 by cagonzal          #+#    #+#             */
/*   Updated: 2025/09/25 11:36:38 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void)
{ 
	Bureaucrat	bureu1("Pedro", 2);
	Bureaucrat	bureu2("Sandra", 14);
	Bureaucrat	bureu3("Miguel", 33);
	Bureaucrat	bureu4("Ana", 53);
	Bureaucrat	bureu5("Juan", 148);
	
	std::cout<< std::endl << "- - - - - - - - - - - - - - - - - - "<<std::endl;
	std::cout<< "- - PresidentialPardonForm test - - "<<std::endl;
	std::cout<< "- - - - - - - - - - - - - - - - - - "<<std::endl;
	{	
		PresidentialPardonForm	form("PresidentialPardon");
		bureu3.signForm(form);
		bureu2.signForm(form);
		bureu2.executeForm(form);
		bureu1.executeForm(form);
	}
	std::cout<< std::endl << "- - - - - - - - - - - - - - - - - - "<<std::endl;
	std::cout<< "- - RobotomyRequestForm test - - "<<std::endl;
	std::cout<< "- - - - - - - - - - - - - - - - - - "<<std::endl;
	{	
		RobotomyRequestForm	form("RobotomyRequest");
		bureu5.signForm(form);
		bureu4.signForm(form);
		bureu4.executeForm(form);
		bureu3.executeForm(form);
	}

	std::cout<< std::endl << "- - - - - - - - - - - - - - - - - - "<<std::endl;
	std::cout<< "- - ShrubberyCreationForm test - - "<<std::endl;
	std::cout<< "- - - - - - - - - - - - - - - - - - "<<std::endl;
	{	
		ShrubberyCreationForm	form("ShrubberyCreationForm");
		bureu5.signForm(form);
		bureu4.signForm(form);
		bureu4.executeForm(form);
	}
	return (0);
}