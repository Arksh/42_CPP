/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:45:31 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/06 12:57:16 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

/**
 * 	Polymorphism is a fundamental concept in object-oriented programming that
 * 	allows objects of different classes to be treated as objects of a common base class.
 * 	It enables a single interface or method to be used for different types of objects,
 * 	providing flexibility and extensibility in your code.
 *
 * 	Default Constructor:
 *
 * 		The default constructor of DiamondTrap initializes a DiamondTrap object without
 * 		specifying a name. It sets the name of DiamondTrap, FragTrap, and ScavTrap
 * 		to "without name" and copies attributes from its base classes. *
 * 		Polymorphism is at play because you can create a DiamondTrap object using this
 * 		constructor and treat it as a DiamondTrap, even though it inherits from both
 * 		FragTrap and ScavTrap. The code can work with it as if it were just a DiamondTrap.
 *
 * 	Parameterized Constructor:
 *
 * 		The parameterized constructor of DiamondTrap takes a std::string parameter and
 * 		assigns it to the name of DiamondTrap, FragTrap, and ScavTrap.
 * 		This constructor also demonstrates polymorphism because you can create a
 * 		DiamondTrap object with a name, and it can still be treated as a DiamondTrap,
 * 		even though it inherits from both FragTrap and ScavTrap. It adheres to the same
 * 		interface as the default constructor, allowing you to work with it in a consistent way.
 *
 * 	In both cases, polymorphism allows you to create and interact with DiamondTrap objects
 * 	while maintaining a common interface across different constructors. This flexibility
 * 	makes your code more versatile and easier to maintain when dealing with objects of derived classes.
 */

/* void leaks (void)
{
	//atexit(leaks);
	system("leaks -q test");
} */

int main (void)
{
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
