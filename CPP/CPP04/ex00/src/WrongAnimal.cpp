/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:34:41 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:38:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("test")
{
	return ;
}

WrongAnimal::~WrongAnimal( void )
{
	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal & w_anim )
{
	*this = w_anim;
	return ;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &w_anim )
{
	if (&w_anim == this)
		return *this;
	this->type = w_anim.type;
	return (*this);
}

std::string WrongAnimal::getType( void ) const
{
	return (this->type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Even though I'm the WrongAnimal, I cannot make a sound :("<< std::endl;
}
