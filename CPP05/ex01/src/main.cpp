/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:57:43 by cagonzal          #+#    #+#             */
/*   Updated: 2025/09/25 10:53:29 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{ 
	Bureaucrat	bureu("Hermes", 48);
	std::cout<<"- - - - - - - - - - - - - - - - - - - -"<<std::endl;
	try
	{
		Form	form("Receipt", 35, 35);
		std::cout<< form <<std::endl;
		bureu.signForm(form);
		std::cout<< form <<std::endl;
	}
	catch (std::exception & e)
	{
		std::cout<< e.what() <<std::endl;
	}
	std::cout<<"- - - - - - - - - - - - - - - - - - - -"<<std::endl;
	try
	{
		Form	form("Reset Server", 56, 56);
		std::cout<< form <<std::endl;
		bureu.signForm(form);
		std::cout<< form <<std::endl;
	}
	catch (std::exception & e)
	{
		std::cout<< e.what() <<std::endl;
	}
	std::cout<<"- - - - - - - - - - - - - - - - - - - -"<<std::endl;
	std::cout<<"- - - - - -Error on Forms - - - - - - -"<<std::endl;
	std::cout<<"- - - - - - - - - - - - - - - - - - - -"<<std::endl;
	try
	{
		Form	form("Born to Fail", -1, -1);
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cout<< e.what() <<std::endl;
	}

	try
	{
		Form	form("Born to Fail 'The sequel, now is personal'", 255, 255);
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout<< e.what() <<std::endl;
	}
	return (0);
}