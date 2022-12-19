/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:13:00 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 16:36:15 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	return ;
}

Harl::~Harl( void )
{
	return ;
}

void Harl::complain (std::string level)
{
	int i = 0;

	std::string str[4] ={"WARNING","DEBUG","INFO","ERROR"};
	Harl::funptr function[4] = {&Harl::warning , &Harl::debug, &Harl::info, &Harl::error};

	while (i < 4)
	{
		if (str[i] == level)
			break;
		i++;
	}
	if (i == 4)
		std::cout <<"HARL MUMBLES AROUND" << std::endl;
	else
		(this->*(function[i]))();
}

void Harl::debug( void )
{
	std::cout <<"I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!." << std::endl;
}

void Harl::info( void )
{
	std::cout <<"I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!." << std::endl;
}

void Harl::warning( void )
{
	std::cout <<"I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month..." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now..." << std::endl;
}
