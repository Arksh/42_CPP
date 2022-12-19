/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:16:48 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 13:26:20 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{
	return ;
}

Weapon::Weapon( std::string str ) :type(str)
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

const std::string Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string str)
{
	this->type = str;
}
