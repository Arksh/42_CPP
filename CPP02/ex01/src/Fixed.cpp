/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:58 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/06 10:29:59 by cagonzal         ###   ########.fr       */
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
/**
 * @brief Integer Constructor for Fixed numbers.
 *
 * This constructor initializes a Fixed object with an integer value. It takes an integer as a parameter,
 * shifts the integer value to the left by the fractional bits count, and stores it as the internal
 * binary representation (raw bits) of the Fixed number.
 *
 * @param number The integer value to be converted into a Fixed number.
 */
Fixed::Fixed(int number) : nbr(number << 8)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

	//	Float Constructor
/**
 * @brief Float Constructor for Fixed numbers.
 *
 * This constructor initializes a Fixed object with a floating-point value. It takes a floating-point number
 * as a parameter, rounds the number to the nearest fixed-point representation based on the fractional bits count,
 * and stores it as the internal binary representation (raw bits) of the Fixed number.
 *
 * @param number The floating-point value to be converted into a Fixed number.
 */
Fixed::Fixed(float number) : nbr(static_cast<int>(roundf(number * (1 << frac))))
{
	std::cout << "Float constructor called" << std::endl;
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
/**
 * @brief Assignment operator for the Fixed class.
 *
 * This member function overloads the assignment operator (=) for the Fixed class.
 * It copies the raw binary representation from the provided `fixed` object to `this` object.
 *
 * @param fixed The Fixed object to copy from.
 * @return A reference to the modified Fixed object.
 */
Fixed &Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->nbr = fixed.getRawBits();
	return *this;
}

	//	Fixed Operator output
/**
 * @brief Output operator for the Fixed class.
 *
 * This function overloads the output stream operator (<<) for the Fixed class.
 * It outputs the floating-point representation of the Fixed object to the provided output stream.
 *
 * @param os The output stream to write to.
 * @param f The Fixed object to output.
 * @return A reference to the output stream.
 */
std::ostream& operator << (std::ostream& os, const Fixed &f) //, const Fixed &f
{
	os << f.toFloat();
	return (os);
}


/**
 * SET & GET Functions
 */
int Fixed::getRawBits(void) const
{
	return (this->nbr);
}

void Fixed::setRawBits(int raw)
{
	this->nbr = raw;
}

int Fixed::toInt (void) const
{
	return (static_cast<int>(this->getRawBits() / (1 << this->frac)));
}

float Fixed::toFloat (void) const
{
	return (static_cast<float>(this->getRawBits() / static_cast<float>(1 << this->frac)));
}
