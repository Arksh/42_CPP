/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:23:32 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/31 11:18:22 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Parameterized constructor
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = T();
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	_array = new T[other._size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

// Subscript operator (non-const)
template <typename T>
T& Array<T>::operator[](unsigned int index)	
{
	if (index >= _size)
		throw Array<T>::OutofBoundsException();
	return _array[index];
}

// Subscript operator (const)
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw Array<T>::OutofBoundsException();
	return _array[index];
}



template<typename T>
const char* Array<T>::OutofBoundsException::what() const throw()
{
	return ("Out of Bounds Exception");
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T> &f) 
{
	os << "ARRAY : " << std::endl;
	os << "ARRAY address: " << &f << std::endl; 
	os << "ARRAY content: ";
	os << "\tsize [" << f.size() << "]"<< std::endl;
	for (int x = 0; x < (int)f.size();x++)
			os << "\t\tarray["<< x <<"]" << " = " << f[x] << std::endl;
	return (os);
}