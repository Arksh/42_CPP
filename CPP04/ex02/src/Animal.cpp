/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:33:22 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/20 12:51:46 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("test")
{
	return ;
}

Animal::~Animal( void )
{
	return ;
}

Animal::Animal( const Animal & anim )
{
	*this = anim;
	return ;
}

Animal & Animal::operator=(const Animal &anim)
{
	if (&anim == this)
		return *this;
	this->type = anim.type;
	return (*this);
}

std::string Animal::getType( void ) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << "Even though I'm an Animal, I cannot make a sound :("<< std::endl;
}
