/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:52:45 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/09 15:08:21 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include <string>
#include <iostream>
#include "Fixed.hpp"


class	Point {

	private:
		Fixed const _x;
		Fixed const _y;

	public:

		Point 			( void );
		Point 			( const float x, const float y );
		Point 			( const Point &src );
		~Point			( void );

		Point&  operator=( const Point &rhs );

		Fixed getX( void ) const ;
		Fixed getY( void ) const ;

};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
