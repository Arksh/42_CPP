/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/06 12:21:21 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**
 * @brief Default constructor for the ScavTrap class.
 *
 * This constructor initializes a new ScavTrap object. It sets the hit points, energy points,
 * and attack damage to default values and prints a message indicating the arrival of the ScavTrap.
 * The default values are: hit points (100), energy points (50), and attack damage (20).
 *
 * @param None.
 * @return None.
 */
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap " << this->_name <<" arrives to the party "<<std::endl;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	return ;
}

/**
 * @brief Parameterized constructor for the ScavTrap class.
 *
 * This constructor initializes a new ScavTrap object with a specified name. It sets the name of the ScavTrap,
 * hit points, energy points, and attack damage to default values and prints a message indicating the arrival of the ScavTrap.
 * The default values are: hit points (100), energy points (50), and attack damage (20).
 *
 * @param name The name to assign to the ScavTrap.
 * @return None.
 */
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

/**
 * @brief Assignment operator for the ScavTrap class.
 *
 * This assignment operator overloads the `=` operator to copy the values of another ScavTrap object `scav`
 * into the current object.
 * It sets the name, hit points, energy points, and attack damage of the current ScavTrap to the values of
 * the provided `scav` object.
 * The operator also prints a message indicating the change in the name.
 *
 * @param scav The ScavTrap object to copy data from.
 * @return A reference to the modified ScavTrap object.
 */
ScavTrap& ScavTrap::operator = (ScavTrap const & scav)
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
