/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:26 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:34:56 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief The main function for a zombie-related program.
 *
 * This is the entry point of the program that demonstrates the use of Zombie objects.
 * It creates Zombie objects using dynamic allocation, announces their presence,
 * and then deallocates the memory for these objects.
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	Zombie* z = new Zombie("Pedro");
	Zombie* z2 = newZombie("Juan");

	randomChump("Paco");
	z->announce();
	delete(z2);
	delete(z);
}
