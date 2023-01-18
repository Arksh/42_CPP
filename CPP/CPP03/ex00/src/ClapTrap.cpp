/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 10:27:39 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("without name"), _hitPts(10) , _energyPts(10) , _attackDmg(0)
{
	std::cout << "Claptrap " << this->_name <<" arrives to the party "<<std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hitPts(10) , _energyPts(10) , _attackDmg(0)
{
	std::cout << "Claptrap " << this->_name <<" arrives to the party "<<std::endl;
	return ;

}

ClapTrap::ClapTrap( const ClapTrap & clap )
{
	*this = clap;
	return ;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Claptrap " << this->_name <<" leaves the party "<<std::endl;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clap)
{
	if (&clap == this)
		return *this;
	std::cout << "Claptrap " << this->_name <<" is now "<< clap._name<<std::endl;
	this->_name = clap._name;
	this->_hitPts = clap._hitPts;
	this->_energyPts = clap._energyPts;
	this->_attackDmg = clap._attackDmg;
	return (*this);
}

/****************/
/*	Functions	*/
/****************/

void ClapTrap::attack(std::string const & target)
{
	std::cout << "Claptrap " << this->_name <<" attacks " << target;
	std::cout << ", causing "<< this->_attackDmg << " points of damage!" <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPts -= amount;
	std::cout << "Claptrap " << this->_name;
	std::cout << " takes " << amount << " of damage"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPts += amount;
	std::cout << "Claptrap " << this->_name;
	std::cout << " recovers " << amount << " points of HP";
	std::cout << " and has " << this->_energyPts << " energy points"<<std::endl;
}

/****************/
/*	Get & Set	*/
/****************/

void ClapTrap::set_hp(int amount)
{
	this->_hitPts = amount;
}

void ClapTrap::set_energy(int amount)
{
	this->_energyPts = amount;
}

void ClapTrap::set_attack(int amount)
{
	this->_attackDmg = amount;
}

int ClapTrap::get_hp(void)
{
	return (this->_hitPts);
}

int ClapTrap::get_energy(void)
{
	return(this->_energyPts);
}

int ClapTrap::get_attack(void)
{
	return(this->_attackDmg);
}
