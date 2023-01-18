/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:45:31 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 11:16:09 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*
void leaks (void)
{
	system("leaks -q test");
}
*/

int main (void)
{
	//atexit(leaks);
	std::cout << "______________________________"<< std::endl;
	ClapTrap a("Pepe");
	a.attack("Juan");
	a.takeDamage(3);
	a.beRepaired(3);

	std::cout << "______________________________"<< std::endl;
	ScavTrap b("Pedro");
	b.guardGate();
	b.attack("Juan");

	std::cout << "______________________________"<< std::endl;
	FragTrap c("Paco");
	c.highFivesGuys();
	c.attack("Juan");

	std::cout << "______________________________"<< std::endl;
	return (0);
}
