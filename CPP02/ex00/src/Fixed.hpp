/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:49:31 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/09 14:49:32 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
		Fixed( const Fixed &copy );
		~Fixed();

		Fixed& operator = ( const Fixed &fixed );

		void	setRawBits(int raw);
		int		getRawBits(void) const;

};

#endif
