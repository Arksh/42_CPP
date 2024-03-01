/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:22 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/20 13:04:53 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	return;
}

Ice::Ice(Ice const & materia)
{
	*this = materia;
	return;
}

Ice& Ice::operator=(const Ice &amateria)
{
	this->type = amateria.getType();
	return (*this);
}

Ice::~Ice(void)
{
	return;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout<< "* shoots an ice bolt at "<< target.getName()<< std::endl;
}
