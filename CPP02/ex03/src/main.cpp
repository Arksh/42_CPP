/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:10:47 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/06 11:03:26 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
Problem:
	Given three points A, B, and C that form a triangle, and a point P,
	determine whether point P lies inside or outside the triangle.

Example 1:
	Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
	Output: Inside
	Explanation:
					 B(10,30)
					/ \
				   /   \
				  /     \
				 /   P   \		P'
				/         \
		  (0,0)A-----------C(20,0)

Example 2:
	Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
	Output: Outside
	Explanation:
					 B(10,30)
					/ \
				   /   \
				  /     \
				 /       \		P
				/         \
		  (0,0)A-----------C(20,0)

Solution:
	To solve this problem, we can use the following approach:
	1.	Calculate the area of the given triangle ABC using its coordinates (x1, y1), (x2, y2), and (x3, y3) as:
		Area A = [x1(y2 – y3) + x2(y3 – y1) + x3(y1 - y2)] / 2;
	2.	Calculate the area of the triangle PAB using P and two vertices A and B.
		Let this area be A1.
	3.	Calculate the area of the triangle PBC using P and two vertices B and C.
		Let this area be A2.
	4.	Calculate the area of the triangle PAC using P and two vertices A and C.
		Let this area be A3.

	If P lies inside the triangle, then the sum of A1, A2, and A3 must be equal to A.
	If they are equal, we conclude that point P is inside the triangle; otherwise, it is outside.
	This approach allows us to determine the position of point P relative to the triangle formed by points A, B, and C.

*/

int main ( void )
{
	Point *A = new Point( 0,0 );
	Point *B = new Point( 10,30 );
	Point *C = new Point( 20,0 );
	Point *P = new Point( 10, 15 );

	if ( bsp( *A, *B, *C, *P ) )
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
	return 0;
}
