/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:57:43 by cagonzal          #+#    #+#             */
/*   Updated: 2025/01/10 15:51:05 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int	main ( void )
{
	//atexit(leaks);
	Intern		*intern = new Intern();
	Bureaucrat	*bureu1 = new Bureaucrat("Juan", 148);
	Bureaucrat	*bureu2 = new Bureaucrat("Trebor", 36);
	Bureaucrat	*bureu3 = new Bureaucrat("Hermes", 5);
	std::cout<< std::endl<< "- - - - - - - - - - - - - "<<std::endl;
	std::cout<< "- -Let's create a form- - "<<std::endl;
	std::cout<< "- - - - - - - - - - - - - "<<std::endl;
	try
	{
		//PresidentialPardonForm , RobotomyRequestForm , ShrubberyCreationForm
		AForm 	*form = intern->makeForm("PresidentialPardonForm", "Alex");
		bureu2->signForm(*form);
		bureu3->signForm(*form);
		bureu2->executeForm(*form);
		bureu3->executeForm(*form);
	}
	catch (std::exception & e)
	{
		std::cout<< "The test has failed beacuse of "<< e.what()<<std::endl;
	}
	std::cout << std::endl<< "- - - - - - - - - - - - - "<<std::endl;
	std::cout<< "- -Testing form 2 fail- - "<<std::endl;
	std::cout<< "- - - - - - - - - - - - - "<<std::endl;
	try
	{
		//PresidentialPardonForm , RobotomyRequestForm , ShrubberyCreationForm
		AForm 	*form2 = intern->makeForm("UnknowForm", "Born 2 Fail");
		bureu1->signForm(*form2);
	}
	catch (std::exception & e)
	{
		std::cout<< "The test has failed beacuse of "<< e.what()<<std::endl;
	}
	return (0);
}
