/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:53:34 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/30 13:51:36 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iomanip>
#include <iostream>

class Tester
{
	private:
		int _n;

	public:
		Tester(int n) : _n(n) { return; }
		
		bool operator== (Tester const & t) const { return (this->_n == t._n); }
		bool operator!= (Tester const & t) const { return (this->_n != t._n); }
		bool operator>  (Tester const & t) const { return (this->_n >  t._n); }
		bool operator<  (Tester const & t) const { return (this->_n <  t._n); }
		bool operator>= (Tester const & t) const { return (this->_n >= t._n); }
		bool operator<= (Tester const & t) const { return (this->_n <= t._n); }
		
		int get_n() const { return this->_n; }
};

std::ostream &operator<< (std::ostream& os, Tester const &t)
{
	os << t.get_n();
	return os;
}

int main( void ) 
{
	int a = 2;
	int b = 3;
	std::string c = "chaine1";
	std::string d = "chaine2";
	Tester t1(66);
	Tester t2(25);

	std::cout << "OPERACIONES SIMPLES" << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << "OPERACIONES COMPLEJAS" << std::endl;
	::swap(t1, t2);
	std::cout << "t1 = " << t1 << ", t2 = " << t2 << std::endl;
	std::cout << "min( t1, t2 ) = " << ::min(t1, t2) << std::endl;
	std::cout << "max( t1, t2 ) = " << ::max(t1, t2) << std::endl;
	return 0;
}