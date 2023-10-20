/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:57:06 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:48:46 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/**
 * @brief The main function for a weapon and human demonstration program.
 *
 * This is the entry point of the program that demonstrates the use of Weapon and HumanA/HumanB classes.
 * It creates instances of Weapon and HumanA/HumanB, assigns weapons to humans, and simulates attacks.
 *
 * @return 0 on successful execution.
 */
int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club2 = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club2);
		jim.attack();
		club2.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
