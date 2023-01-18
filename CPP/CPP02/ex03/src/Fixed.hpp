/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:50:27 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/09 14:50:28 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

/*
	seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm	meaning
	31								0	bit #
	s = sign bit, e = exponent, m = mantissa
*/

class	Fixed
{
	private:
		int					nbr;
		static const int	frac = 8;

	public:
		Fixed();
		Fixed( int nbr );
		Fixed( float nbr );
		Fixed( const Fixed &copy );
		~Fixed();

		Fixed& operator = ( const Fixed &fixed );

		void	setRawBits(int raw);
		int		getRawBits(void) const;

		int		toInt ( void ) const;
		float	toFloat ( void ) const;

		// MIN-MAX OPERATORS
		static Fixed min ( const Fixed &fixed, const Fixed &fixed2);
		static Fixed max ( const Fixed &fixed, const Fixed &fixed2);

		// Comparison operators
		bool operator!= ( const Fixed &fixed2 );
		bool operator== ( const Fixed &fixed2 );
		bool operator> ( const Fixed &fixed2 );
		bool operator>= ( const Fixed &fixed2 );
		bool operator< ( const Fixed &fixed2 );
		bool operator<= ( const Fixed &fixed2 );

		// Arithmetic perators
		Fixed operator- ( const Fixed &fixed2 ) const;
		Fixed operator+ ( const Fixed &fixed2 ) const;
		Fixed operator* ( const Fixed &fixed2 ) const;
		Fixed operator/ ( const Fixed &fixed2 ) const;

		// Pre Increase / Decrease Operators
		Fixed &operator++ ( void );
		Fixed &operator-- ( void );

		// Post Increase / Decrease Operators
		Fixed operator++ ( int );
		Fixed operator-- ( int );
};
	// Output operator
	std::ostream &operator<<(std::ostream& os, const Fixed &f); //, const Fixed &f

#endif
