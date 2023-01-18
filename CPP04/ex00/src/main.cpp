/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:57:43 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:47:44 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// void	leaks ( void )
// {
// 	system("leaks -q testAnimal");
// }

int	main ( void )
{
	Animal* animal = new Animal();
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	WrongAnimal* wrongcat = new WrongCat();

	// atexit(leaks);
	std::cout << "The Dog should be a " << dog->getType() << " " << std::endl;
	std::cout << "The Cat should be a " << cat->getType() << " " << std::endl;
	std::cout << "This animal should be a " << animal->getType() << " " << std::endl;
	std::cout << "This animal should be a " << wrongcat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound(); //will output the dog sound!
	wrongcat->makeSound();
	std::cout << " ___ Deep Copy ____ " << std::endl;
	*dog = *cat;
	std::cout << "The Dog changed into a "<< dog->getType() << " " << std::endl;
	delete dog;
	delete animal;
	delete cat;
	delete wrongcat;
}
