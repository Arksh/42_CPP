/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:34:20 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 15:02:12 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	return ;
}

Cat::Cat( const Cat & cat )
{
	*this = cat;
	return ;
}

Cat::~Cat( void )
{
	delete this->brain;
	return ;
}

Cat & Cat::operator=(const Cat &cat)
{
	if (&cat == this)
		return *this;
	this->type = cat.type;
	delete this->brain;
	this->brain = new Brain();
	*this->brain = *cat.brain;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow meowed the cat"<< std::endl;
}
