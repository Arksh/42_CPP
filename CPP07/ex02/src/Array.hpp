/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:08:00 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/31 11:12:50 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;

		class OutofBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	public:
		Array() : _array(0), _size(0) {}
		Array(unsigned int n);
		Array(const Array& other);
		~Array() { delete[] _array; }

		Array& operator=(const Array& other);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const { return _size; }
};

#include "Array.ipp"
#endif