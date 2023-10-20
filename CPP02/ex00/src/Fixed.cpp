/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:49:25 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/09 14:49:26 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	Empty Constructor
Fixed::Fixed() : nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

//	Copy Constructor
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	nbr = copy.getRawBits();
	return ;
}

//	Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

//	Fixed Operator assign
Fixed &Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->nbr = fixed.getRawBits();
	return *this;
}

/*
	SET & GET Functions
*/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->nbr);
}

void Fixed::setRawBits(int raw)
{
	this->nbr = raw;
}
