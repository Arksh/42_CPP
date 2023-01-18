/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:10:47 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/09 15:39:18 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
Output: Inside
Explanation:
				 B(10,30)
				/ \
			   /   \
			  /     \
			 /   P   \      P'
			/         \
	  (0,0)A-----------C(20,0)

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
Output: Outside
Explanation:
				 B(10,30)
				/ \
			   /   \
			  /     \
			 /       \      P
			/         \
	  (0,0)A-----------C(20,0)

Solution:
	Let the coordinates of three corners be (x1, y1), (x2, y2) and (x3, y3).
	And coordinates of the given point P be (x, y)
	Calculate area of the given triangle, i.e., area of the triangle ABC in the above diagram.
	Area A = [x1(y2 – y3) + x2(y3 – y1) + x3(y1 - y2)] / 2
	Calculate area of the triangle PAB. Let this area be A1.
	Calculate area of the triangle PBC. Let this area be A2.
	Calculate area of the triangle PAC. Let this area be A3.

If P lies inside the triangle, then A1 + A2 + A3 must be equal to A.

*/

int main ( void )
{
	if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15) ) )
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
	return 0;
}
