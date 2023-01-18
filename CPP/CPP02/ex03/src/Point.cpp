/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:52:40 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/09 15:07:44 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//	Default Constructor
Point::Point( void ) : _x(0), _y(0)
{
	return ;
}

//	Parameter Constructor
Point::Point( const float x, const float y ) : _x(x), _y(y)
{
	return ;
}

//	Copy Constructor
Point::Point( const Point & src ) : _x(src._x), _y(src._y)
{
	return ;
}

//	Destructor
Point::~Point( void )
{
	return ;
}

Point& Point::operator=( const Point &rhs )
{
	if ( this != &rhs )
	{
		( Fixed ) this->_x = rhs.getX();
		( Fixed ) this->_y = rhs.getY();
	}
	return *this;
}

//	Get Functions
Fixed Point::getX( void ) const
{
	return this->_x;
}

Fixed Point::getY( void ) const
{
	return this->_y;
}
