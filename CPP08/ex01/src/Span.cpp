/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:09:08 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/31 18:42:20 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	return *this;
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw FullSpanException();
	_numbers.push_back(number);
}

int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	int minNum = *std::min_element(_numbers.begin(), _numbers.end());
	int maxNum = *std::max_element(_numbers.begin(), _numbers.end());

	return maxNum - minNum;
}
