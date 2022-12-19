/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:09:17 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 12:29:57 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

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
