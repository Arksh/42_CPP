/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:34:20 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:34:21 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	return ;
}

Cat::Cat( const Cat & cat )
{
	*this = cat;
	return ;
}

Cat::~Cat( void )
{
	return ;
}

Cat & Cat::operator=(const Cat &cat)
{
	if (&cat == this)
		return *this;
	this->type = cat.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow meowed the cat"<< std::endl;
}
