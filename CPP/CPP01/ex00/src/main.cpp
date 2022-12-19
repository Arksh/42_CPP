/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:26 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/16 16:12:13 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* z = new Zombie("Pedro");
    Zombie* z2 = newZombie("Juan");

    randomChump("Paco");
    z->announce();
    delete(z2);
    delete(z);
}
