/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:58:10 by cagonzal          #+#    #+#             */
/*   Updated: 2025/11/13 12:29:31 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include<iomanip>
#include<iostream>

class Tester
{
	private:
		int _n;

	public:
		Tester(void) : _n(42) { return; }
		Tester(int n) : _n(n) { return; }
		int get_n() const { return this->_n; }
};

std::ostream &operator<< (std::ostream& os, Tester const &t)
{
	os << t.get_n();
	return os;
}

template< typename T >
void print(const T &x)
{
    std::cout << x << std::endl;
}

template< typename T >
void increment(T &x)
{
    x++;
}

template< typename T >
void decrement(T &x)
{
    x--;
}

template< typename T >
void append_a_char(T &x)
{
    x.append("a");
}

template< typename T >
void iter (T *array, const unsigned int length, void (*f)(T&))
{
    for (unsigned int i = 0; i < length; i++)
        f(array[i]);
}

template< typename T>
void iter (T *array, const unsigned int length, void (*f) (const T&))
{
    for (unsigned int i = 0; i < length; i++)
        f(array[i]);
}


#endif