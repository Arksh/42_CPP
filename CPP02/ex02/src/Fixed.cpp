/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:40 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/06 10:45:01 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	Empty Constructor
Fixed::Fixed() : nbr(0)
{
	return ;
}

//	Int Constructor
Fixed::Fixed(int number) : nbr(number << 8)
{
	return ;
}

//	Float Constructor
Fixed::Fixed(float number) : nbr(static_cast<int>(roundf(number * (1 << frac))))
{
	return ;
}

///	Copy Constructor
Fixed::Fixed(const Fixed &copy)
{
	nbr = copy.getRawBits();
	return ;
}

//	Destructor
Fixed::~Fixed()
{
	return ;
}

//	Fixed Operator assign
Fixed &Fixed::operator = (const Fixed &fixed)
{
	this->nbr = fixed.getRawBits();
	return *this;
}

//	Fixed Operator output
std::ostream& operator << (std::ostream& os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

//	************************************************
//	* Functions to Pre Increase/Decrease Operators *
//	************************************************

/**
 * @brief Pre-increment operator for Fixed numbers.
 *
 * This operator overloads the pre-increment (`++`) operator for Fixed numbers.
 * It increases the internal binary representation (raw bits) of the Fixed number by 1.
 * After the increment, the modified Fixed object is returned.
 *
 * @return A reference to the modified Fixed object after increment.
 */
Fixed &Fixed::operator ++ (void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

/**
 * @brief Pre-decrement operator for Fixed numbers.
 *
 * This operator overloads the pre-decrement (`--`) operator for Fixed numbers.
 * It decreases the internal binary representation (raw bits) of the Fixed number by 1.
 * After the decrement, the modified Fixed object is returned.
 *
 * @return A reference to the modified Fixed object after decrement.
 */
Fixed &Fixed::operator -- (void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

//	*************************************************
//	* Functions to Post Increase/Decrease Operators *
//	*************************************************

/**
 * @brief Post-increment operator for Fixed numbers.
 *
 * This operator overloads the post-increment (`++`) operator for Fixed numbers.
 * It creates a copy of the current Fixed object, increases the internal binary representation (raw bits) by 1,
 * and returns the copy of the Fixed object before the increment.
 *
 * @param int An unused parameter to indicate the post-increment operator.
 * @return A copy of the original Fixed object before the increment.
 */
Fixed Fixed::operator ++ (int)
{
	Fixed p(this->toFloat());
	this->setRawBits(this->getRawBits() + 1);
	return (p);
}

/**
 * @brief Post-decrement operator for Fixed numbers.
 *
 * This operator overloads the post-decrement (`--`) operator for Fixed numbers.
 * It creates a copy of the current Fixed object, decreases the internal binary representation (raw bits) by 1,
 * and returns the copy of the Fixed object before the decrement.
 *
 * @param int An unused parameter to indicate the post-decrement operator.
 * @return A copy of the original Fixed object before the decrement.
 */
Fixed Fixed::operator -- (int)
{
	Fixed p(this->toFloat());
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

//	**********************************
//	* Functions to MIN-MAX Operators *
//	**********************************

/**
 * @brief Find the minimum value between two Fixed numbers.
 *
 * This static member function of the Fixed class compares two Fixed numbers, f1 and f2,
 * and returns the Fixed number with the smaller value. It uses the internal binary representation (raw bits)
 * for comparison.
 *
 * @param f1 The first Fixed number to compare.
 * @param f2 The second Fixed number to compare.
 * @return The Fixed number with the smaller value between f1 and f2.
 */
Fixed Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if(f1.getRawBits() < f2.getRawBits())
		return (f1);
	return(f2);
}

/**
 * @brief Find the maximum value between two Fixed numbers.
 *
 * This static member function of the Fixed class compares two Fixed numbers, f1 and f2,
 * and returns the Fixed number with the larger value. It uses the internal binary representation (raw bits)
 * for comparison.
 *
 * @param f1 The first Fixed number to compare.
 * @param f2 The second Fixed number to compare.
 * @return The Fixed number with the larger value between f1 and f2.
 */
Fixed Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if(f1.getRawBits() > f2.getRawBits())
		return (f1);
	return(f2);
}

//	*************************************
//	* Functions to comparison operators *
//	*************************************

bool Fixed::operator != (const Fixed &f2)
{
	if (this->getRawBits() == f2.getRawBits())
		return (0);
	return(1);
}

bool Fixed::operator == (const Fixed &f2)
{
	if (this->getRawBits() != f2.getRawBits())
		return (0);
	return(1);
}

bool Fixed::operator > (const Fixed &f2)
{
	if (this->getRawBits() > f2.getRawBits())
		return (1);
	return(0);
}

bool Fixed::operator < (const Fixed &f2)
{
	if (this->getRawBits() < f2.getRawBits())
		return (1);
	return(0);
}

bool Fixed::operator >= (const Fixed &f2)
{
	if (this->getRawBits() >= f2.getRawBits())
		return (1);
	return(0);
}

bool Fixed::operator <= (const Fixed &f2)
{
	if (this->getRawBits() <= f2.getRawBits())
		return (1);
	return(0);
}

//	**************************************
//	* Functions to  arithmetic operators *
//	**************************************

Fixed Fixed::operator - (const Fixed &f2) const
{
	Fixed result(this->toFloat() - f2.toFloat());
	return(result);
}

Fixed Fixed::operator + (const Fixed &f2) const
{
	Fixed result(this->toFloat() + f2.toFloat());
	return(result);
}

Fixed Fixed::operator * (const Fixed &f2) const
{
	Fixed result(this->toFloat() * f2.toFloat());
	return(result);
}

Fixed Fixed::operator / (const Fixed &f2) const
{
	Fixed result(this->toFloat() / f2.toFloat());
	return(result);
}

//	********************************
//	* Functions to manage the bits *
//	********************************

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
