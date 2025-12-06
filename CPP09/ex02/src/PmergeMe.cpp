/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:33:27 by cagonzal          #+#    #+#             */
/*   Updated: 2025/12/06 13:09:28 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>

std::string intToString(int value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

std::string get_input(int argc, char **argv)
{
	std::string aux;

	for (int i = 1; i < argc; i++)
	{
		aux += argv[i];
		if (i < argc - 1)
			aux += ' ';
	}
	
	return aux;
}

bool isIntNumber(std::string str)
{
	char		*e;
	double		x;
	
	x = strtod(str.c_str(),&e);
	if (*e != '\0')
		return false;
	if ( x < std::numeric_limits<int>::min() || \
	x > std::numeric_limits<int>::max())
  		return false;
	if (fmod(x, 1.0) != 0)
        return false;
	return true;
}

bool check_duplicates(std::vector<int> &vec, std::deque<int> &deq)
{
	for (size_t i = 0; i < vec.size(); i++)
		for (size_t j = i + 1; j < vec.size(); j++)
			if (vec[i] == vec[j])
				return true;
	
	for (size_t i = 0; i < deq.size(); i++)
		for (size_t j = i + 1; j < deq.size(); j++)
			if (deq[i] == deq[j])
				return true;
	
	return false;
}

bool check_input(const std::string &input, char del)
{
	std::string seg;
	for (size_t i; i < input.size(); i++)
	{
		seg += input[i];
		if (input[i] == del)
		{
			if (isIntNumber(seg))
				return false;
			seg.clear();
		}
	}
	return true;
}
