/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:09:17 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:36:33 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/**
 * @brief Create a horde of zombies with unique names.
 *
 * This function creates a horde of zombie objects with the specified name and unique names for each zombie.
 *
 * @param nbr The number of zombies to create in the horde.
 * @param name The base name for all zombies in the horde.
 * @return A pointer to an array of Zombie objects representing the zombie horde.
 */
Zombie* zombieHorde(int nbr, std::string name)
{
	int i = 0;
	Zombie* z = new Zombie[nbr];

	while (i != nbr)
	{
		z[i].setZombieName(name + ' ' + std::to_string(i + 1));
		i++;
	}
	return (z);
}
