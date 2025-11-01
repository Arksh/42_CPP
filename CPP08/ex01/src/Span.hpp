/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:06:09 by cagonzal          #+#    #+#             */
/*   Updated: 2025/11/01 10:54:34 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>
# include <limits>
# include <iterator>

class Span 
{
	
	private:
		std::vector<int> _numbers;
		unsigned int _maxSize;
		Span();

		class FullSpanException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Span is already full.";
			}
		};

		class NotEnoughNumbersException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Not enough numbers to find a span.";
			}
		};

	public:
		Span(unsigned int n) : _maxSize(n) {}
		Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize) {}
		Span &operator=(const Span &other);
		~Span() {}

		void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			if (_numbers.size() + std::distance(begin, end) > _maxSize)
				throw FullSpanException();
			_numbers.insert(_numbers.end(), begin, end);
		}
		
};


#endif