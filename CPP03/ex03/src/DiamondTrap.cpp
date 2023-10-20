/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/02 16:41:42 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**
 * @brief Default constructor for the DiamondTrap class.
 *
 * This constructor initializes a new DiamondTrap object without specifying a name.
 * It sets the name of the DiamondTrap and its base classes (FragTrap and ScavTrap)
 * to "without name," and it copies the hit points, energy points, and attack damage
 * from FragTrap and ScavTrap to DiamondTrap. Additionally, it prints a message
 * indicating the arrival of the DiamondTrap.
 *
 * @param None.
 * @return None.
 */
DiamondTrap::DiamondTrap() : FragTrap("without name"), ScavTrap("without name")
{
	this->_name = "without name";
	this->ClapTrap::_name = "without name_clap_name";
	this->_hitPts = FragTrap::_hitPts;
	this->_energyPts = ScavTrap::_energyPts;
	this->_attackDmg = FragTrap::_attackDmg;
	std::cout << "DiamondTrap " << this->_name <<" arrives to the party "<<std::endl;
	return;
}

/**
 * @brief Parameterized constructor for the DiamondTrap class.
 *
 * This constructor initializes a new DiamondTrap object with a specified name `str`.
 * It sets the name of the DiamondTrap, FragTrap, and ScavTrap based on the input `str`.
 * Additionally, it copies the hit points, energy points, and attack damage from FragTrap and ScavTrap to DiamondTrap,
 * creating a composition of FragTrap and ScavTrap within DiamondTrap. Finally, it prints a message
 * indicating the arrival of the DiamondTrap.
 *
 * @param str The name to assign to the DiamondTrap and its base classes.
 * @return None.
 */
DiamondTrap::DiamondTrap(std::string str) : ClapTrap(str + "_clap_name") , FragTrap(str), ScavTrap(str)
{
	//std::cout << "LLama al compuesto "<<std::endl;
	this->_name = str;
	this->_hitPts = FragTrap::_hitPts;
	this->_energyPts = ScavTrap::_energyPts;
	this->_attackDmg = FragTrap::_attackDmg;
	std::cout << "DiamondTrap " << this->_name <<" arrives to the party "<<std::endl;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap & diam)
{
	*this = diam;
	return;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name <<" leaves the party "<<std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & diam)
{
	std::cout << "DiamondTrap " << this->ScavTrap::_name <<" is now "<< diam.ScavTrap::_name<<std::endl;
	if (&diam == this)
		return *this;
	this->_name = diam.ScavTrap::_name;
	this->_hitPts = diam.ScavTrap::_hitPts;
	this->_energyPts = diam.ScavTrap::_energyPts;
	this->_attackDmg = diam.ScavTrap::_attackDmg;
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Hi im " << this->_name << " and my ClapTrap name is "<< this->ClapTrap::_name << std::endl;
}
