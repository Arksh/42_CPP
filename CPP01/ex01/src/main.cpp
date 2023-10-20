/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:26 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 12:25:38 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int		nbr = 4;
	int		i = 0;
	Zombie*	z = zombieHorde(nbr, "Paco");

	while (i < nbr)
	{
		z[i++].announce();
	}
	delete []z;
}
