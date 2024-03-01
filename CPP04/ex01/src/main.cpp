/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:57:43 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/20 12:50:14 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	leaks ( void )
{
	system("leaks -q test");
}

int	main ( void )
{
	atexit(leaks);
	{
		// Animal* array[10];

		// std::cout<<"__________Brain_creations__________"<<std::endl;
		// std::cout<<std::endl;
		// int i = 0;
		// std::cout<<"__________Dog__________"<<std::endl;
		// std::cout<<std::endl;
		// while (i < 5)
		// 	array[i++] = new Dog();
		// std::cout<<"__________Cat__________"<<std::endl;
		// std::cout<<std::endl;
		// while (i < 10)
		// 	array[i++] = new Cat();
		// std::cout<<std::endl;
		// std::cout<<"__________Brain_destruction__________"<<std::endl;
		// std::cout<<std::endl;
		// while (i > 0)
		// 	delete array[--i];
		// std::cout<<std::endl;
		// std::cout<<"__________Ended_test__________"<<std::endl;
		// std::cout<<std::endl;
	}
	{
		Animal* dog = new Dog();
		Animal* dog3 = new Dog();
		Animal* cat = new Cat();

		*dog3 = *dog;
		std::cout<<"Dog 3 is a "<< dog3->getType()<<std::endl;
		*dog3 = *dog;
		std::cout<<"Dog 3 is a "<< dog3->getType()<<std::endl;
		delete dog;
		delete cat;
		delete dog3;
	}
	{
		// Dog _dog1;
		// Dog _dog2;
		// Cat _cat1;
		// Cat _cat2;

		// _cat1 = _cat2;
	}
}
