/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:57:43 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 15:09:55 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void leaks(void)
{
	system("leaks -q test");
}


int main (void)
{
	atexit(leaks);
	{
		// AMateria *ice = new Ice();
		// AMateria *heal = new Cure();
		// AMateria *ice2 = ice->clone();
		// AMateria *heal2 = heal->clone();
		// AMateria *heal3 = heal->clone();
		// Character *character = new Character("Miguel");
		// Character *character2 = new Character("Test");

		// std::cout << "Character "<<character->getName() <<" starts equiping himself" << std::endl;
		// character->equip(ice);
		// character->equip(ice2);
		// character->equip(heal);
		// character->equip(heal2);
		// character->equip(heal3);

		// *character2 = *character;
		// std::cout << std::endl << "Now that character "<<character2->getName() <<" is ready he's going to use ... " << std::endl;
		// character2->use(0,*character2);
		// character2->use(1,*character2);
		// character2->use(2,*character2);
		// character2->use(3,*character2);
		// character2->use(5,*character2);
		// character2->use(0,*character);
		// std::cout << std::endl << "Now that he has used everything he's going to unequip it" << std::endl;
		// character->unequip(3);
		// character->unequip(2);
		// character->unequip(1);
		// character->unequip(0);
		// character->unequip(0);
		// std::cout << std::endl << "- - - - - - end testing - - - - - - " << std::endl;
		// delete character;
		// delete character2;
		// delete ice;
		// delete ice2;
		// delete heal;
		// delete heal2;
		// delete heal3;
	}
	// std::cout << std::endl << "- - - - - - - - - - - - - - - - - " << std::endl;
	{
		// IMateriaSource* src = new MateriaSource();
		// src->learnMateria(new Ice());
		// src->learnMateria(new Cure());
		// ICharacter* me = new Character("me");
		// AMateria* tmp;
		// tmp = src->createMateria("ice");
		// me->equip(tmp);
		// tmp = src->createMateria("cure");
		// me->equip(tmp);
		// ICharacter* bob = new Character("bob");
		// me->use(0, *bob);
		// me->use(1, *bob);
		// delete bob;
		// delete me;
		// delete src;
		// return 0;
	}
}
