/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 10:57:57 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap " << this->_name <<" arrives to the party "<<std::endl;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->_name <<" arrives to the party "<<std::endl;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap & scav)
{
	*this = scav;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name <<" leaves the battle "<<std::endl;
	return ;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & scav)
{
	std::cout << "ScavTrap " << this->_name <<" is now "<< scav._name<<std::endl;
	if (&scav == this)
		return *this;
	this->_name = scav._name;
	this->_hitPts = scav._hitPts;
	this->_energyPts = scav._energyPts;
	this->_attackDmg = scav._attackDmg;
	return (*this);
}

void  ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name <<" have entered in Gate keeper mode"<<std::endl;
}
