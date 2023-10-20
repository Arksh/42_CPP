/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:17:01 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 14:55:54 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str) : weapon(NULL) , name(str)
{
	return;
}

HumanB::~HumanB (void)
{
	return;
}

void HumanB::attack(void)
{
	if (weapon != NULL)
		std::cout<<this->name<<" attacks with his "<<this->weapon->getType()<<std::endl;
	else
		std::cout<<this->name<<" tries to punch you"<<std::endl;
}

void    HumanB::setWeapon(Weapon &w)
{
	this->weapon = &w;
}
