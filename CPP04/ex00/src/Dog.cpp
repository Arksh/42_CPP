/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:34:00 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:34:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal ()
{
	this->type = "Dog";
	return ;
}

Dog::Dog( const Dog & dog )
{
	*this = dog;
}

Dog::~Dog( void )
{
	return ;
}

Dog & Dog::operator=(const Dog &dog)
{
	if (&dog == this)
		return *this;
	this->type = dog.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woff barked the dog"<< std::endl;
}
