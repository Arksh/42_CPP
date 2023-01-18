/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 16:38:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : type("none")
{
	return ;
}

AMateria::AMateria( std::string const &str ) : type(str)
{
	return ;
}

AMateria::~AMateria( void )
{
	return ;
}


AMateria & AMateria::operator=(const AMateria &amateria)
{
	this->type = amateria.type;
	return (*this);
}


std::string const & AMateria::getType(void) const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout<< "does unspecific magic to "<< target.getName()<< std::endl;
	return;
}
