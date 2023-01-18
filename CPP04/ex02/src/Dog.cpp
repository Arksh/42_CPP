/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:34:00 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 15:01:53 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal ()
{
	this->type = "Dog";
	this->brain = new Brain();
	return ;
}

Dog::Dog( const Dog & dog )
{
	*this = dog;
}

Dog::~Dog( void )
{
	delete this->brain;
	return ;
}

Dog & Dog::operator=(const Dog &dog)
{
	if (&dog == this)
		return *this;
	this->type = dog.type;
	delete this->brain;
	this->brain = new Brain();
	*this->brain = *dog.brain;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woff barked the dog"<< std::endl;
}
