/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:45:31 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 10:27:53 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

/*
void leaks (void)
{
	system("leaks -q test");
}
*/

int main (void)
{
	//atexit(leaks);
	ClapTrap a	("Pepe");
	ClapTrap b	(a);
	ClapTrap c	("Jose");

	a.attack("Juan");
	a.takeDamage(3);
	a.beRepaired(3);
	a = c;

	return (0);
}
