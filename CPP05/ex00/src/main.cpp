/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:57:43 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/07 16:22:59 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

/*
void	leaks ( void )
{
	system("leaks -q test");
}
*/

int	main ( void )
{
	//atexit(leaks);
	try
	{
		Bureaucrat bureu("Hermes",36);

		std::cout<< bureu <<std::endl;
		bureu.decreaseGrade();
		bureu.decreaseGrade();
		std::cout<< bureu <<std::endl;
		bureu.increaseGrade();
		bureu.increaseGrade();
		std::cout<< bureu <<std::endl;

	}
	catch (std::exception & e)
	{
		std::cout<< e.what() <<std::endl;
	}
	std::cout<< "- - - - - - - - - - - - - - - - -"<<std::endl;
	std::cout<< "- - - - - Going to fail - - - - -"<<std::endl;
	std::cout<< "- - - - - - - - - - - - - - - - -"<<std::endl;
	try
	{
		Bureaucrat bureu("Juan",150);
		bureu.decreaseGrade();

	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout<< e.what() <<std::endl;
	}
	std::cout<< "- - - - - - - - - - - - - - - - -"<<std::endl;
	try
	{
		Bureaucrat bureu("Pedro",1);
		bureu.increaseGrade();
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout<< e.what() <<std::endl;
	}
	return (0);
}
