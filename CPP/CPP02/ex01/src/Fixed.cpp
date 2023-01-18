/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:58 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/09 14:49:14 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	Empty Constructor
Fixed::Fixed() : nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

//	Int Constructor
Fixed::Fixed(int number) : nbr(number << 8)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

//	Float Constructor
Fixed::Fixed(float number) : nbr(static_cast<int>(roundf(number * (1 << frac))))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

///	Copy Constructor
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

//	Fixed Operator output
std::ostream& operator<<(std::ostream& os, const Fixed &f) //, const Fixed &f
{
	os << f.toFloat();
	return (os);
}


/*
	SET & GET Functions
*/

int Fixed::getRawBits(void) const
{
	return (this->nbr);
}

void Fixed::setRawBits(int raw)
{
	this->nbr = raw;
}

int Fixed::toInt ( void ) const
{
	return (static_cast<int>(this->getRawBits() / (1 << this->frac)));
}

float Fixed::toFloat ( void ) const
{
	return (static_cast<float>(this->getRawBits() / static_cast<float>(1 << this->frac)));
}
