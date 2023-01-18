/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 10:53:51 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap " << this->_name <<" arrives to the party "<<std::endl;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name <<" arrives to the party "<<std::endl;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	return ;
}

FragTrap::FragTrap(const FragTrap & frag)
{
	*this = frag;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name <<" leaves the party "<<std::endl;
	return ;
}

FragTrap& FragTrap::operator=(FragTrap const & frag)
{
	std::cout << "FragTrap " << this->_name <<" is now "<< frag._name<<std::endl;
	if (&frag == this)
		return *this;
	this->_name = frag._name;
	this->_hitPts = frag._hitPts;
	this->_energyPts = frag._energyPts;
	this->_attackDmg = frag._attackDmg;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name <<" high fives!"<<std::endl;
}
