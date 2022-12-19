/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:13:00 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 16:55:06 by cagonzal         ###   ########.fr       */
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

	std::string str[4] ={ "DEBUG", "INFO", "WARNING", "ERROR" };
	Harl::funptr function[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	while (i < 4)
	{
		if (str[i] == level)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			(this->*(function[0]))();
		case 1:
			(this->*(function[1]))();
		case 2:
			(this->*(function[2]))();
		case 3:
			(this->*(function[3]))();
			break;
		default:
			std::cout <<"HARL MUMBLES AROUND" << std::endl;
			break;
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout <<"I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!.\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout <<"I cannot believe adding extra bacon cost more money.\nYou don't put enough! If you did I would not have to ask for it!.\n" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout <<"I think I deserve to have some extra bacon for free.\nI've been coming here for years and you just started working here last month...\n" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now...\n" << std::endl;
}
