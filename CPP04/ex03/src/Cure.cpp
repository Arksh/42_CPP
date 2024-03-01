/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:22 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 15:32:19 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("Cure")
{
	return;
}

Cure::Cure(Cure const & materia)
{
	*this = materia;
	return;
}

Cure& Cure::operator=(const Cure &amateria)
{
	this->type = amateria.getType();
	return (*this);
}

Cure::~Cure(void)
{
	return;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout<< "heals "<< target.getName()<< " wounds"<< std::endl;
}
