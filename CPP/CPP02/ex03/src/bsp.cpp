/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:08:47 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/09 15:23:01 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed abs(Fixed x)
{
	if (x < 0)
		return (x * -1);
	return x;
}

static Fixed area( Point const a, Point const b, Point const c )
{
	return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
			( b.getX() * ( c.getY() - a.getY() ) ) +
			( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = abs(area( a, b, c ));
	Fixed pabArea = abs(area( point, a, b ));
	Fixed pbcArea = abs(area( point, b, c ));
	Fixed pcaArea = abs(area( point, c, a ));

	return ( abcArea == pabArea + pbcArea + pcaArea );
}
