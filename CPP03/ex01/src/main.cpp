/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:45:31 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 10:46:18 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/*
void leaks (void)
{
	system("leaks -q test");
}
*/

int main (void)
{
	//atexit(leaks);
	ClapTrap a("Pepe");

	a.attack("Juan");
	a.takeDamage(3);
	a.beRepaired(3);

	ScavTrap b("Pedro");
	b.guardGate();
	b.takeDamage(7);
	b.attack("Juan");
	b.beRepaired(5);
	return (0);
}
