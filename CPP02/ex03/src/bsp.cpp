/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:08:47 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/06 10:51:35 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed abs(Fixed x)
{
	if (x < 0)
		return (x * -1);
	return x;
}

/**
 * @brief Calculate the area of a triangle defined by three points.
 *
 * This static member function calculates the area of a triangle defined by three points `a`, `b`, and `c` using
 * the Shoelace formula. It computes the area as (1/2) times the absolute value of the determinant of the points.
 *
 * @param a The first Point of the triangle.
 * @param b The second Point of the triangle.
 * @param c The third Point of the triangle.
 * @return The area of the triangle formed by the given points.
 */
static Fixed area( Point const a, Point const b, Point const c )
{
	return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
			( b.getX() * ( c.getY() - a.getY() ) ) +
			( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );
}

/**
 * @brief Check if a point is inside a triangle defined by three points.
 *
 * This function checks if a given Point `point` lies inside a triangle defined by three other Points `a`, `b`, and `c`.
 * It does so by comparing the sum of the areas of sub-triangles (formed by the main triangle and the given point) to
 * the area of the main triangle. If they are equal, the point is inside the triangle; otherwise, it is outside.
 *
 * @param a The first Point of the main triangle.
 * @param b The second Point of the main triangle.
 * @param c The third Point of the main triangle.
 * @param point The Point to check if it lies inside the triangle.
 * @return True if the point is inside the triangle, false otherwise.
 */
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = abs(area( a, b, c ));
	Fixed pabArea = abs(area( point, a, b ));
	Fixed pbcArea = abs(area( point, b, c ));
	Fixed pcaArea = abs(area( point, c, a ));

	return ( abcArea == pabArea + pbcArea + pcaArea );
}
