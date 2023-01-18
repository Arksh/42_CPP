/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:45:31 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/16 12:56:51 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
	DiamondTrap d("Juancho");
	DiamondTrap d2("Julia");
	d2 = d;

	std::cout << "______________________________"<< std::endl;
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();
	d.attack("Objetivo de D");
	d2.guardGate();
	std::cout << "______________________________"<< std::endl;
	return (0);
}
