/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:33:22 by cagonzal          #+#    #+#             */
/*   Updated: 2025/12/06 13:37:31 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>

//Check strings
std::string intToString(int value);
std::string	get_input(int argc, char **argv);
bool		isIntNumber(std::string str);

//Check data integrity
bool		check_duplicates(std::vector<int> &vec, std::deque<int> &deq);
bool		check_input(const std::string &input, char del);


//show list
template <typename T>
std::string	show_array(T list)
{
	std::string	aux;
	
	// aux += "[ ";
	for (int x = 0; x < (int)list.size();x++)
		aux += intToString(list[x]) + " ";
	// aux += "]";
	
	return (aux);
}

//Template to extract data
template <typename T>
T					extract_data(const std::string &input, char del)
{
	T aux;
	std::stringstream ss(input);
	std::string item;
	
	while (std::getline(ss, item, del))
		if (isIntNumber(item) && item != "")
			aux.push_back(atoi(item.c_str()));
	return aux;
}

//Template to sort
template <typename T>
T					merge_sort(T &list)
{
	T greater;
	T lesser;
	int	aux;
	bool hasAux = false;
	
	if (list.size() <= 1)
		return (list);
	
	// recorre de 2 en 2
	for (size_t i = 0; i < list.size(); i += 2)
	{
		if (i + 1 < list.size())
		{
			if (list[i] > list[i + 1])
			{
				greater.push_back(list[i]);
				lesser.push_back(list[i + 1]);
			}
			else
			{
				greater.push_back(list[i + 1]);
				lesser.push_back(list[i]);
			}
		}
		else
		{
			aux = list[i];
			hasAux = true;
		}
	}
	greater = merge_sort<T>(greater);
	lesser = merge_sort<T>(lesser);

	for (size_t i = 0; i < lesser.size(); ++i)
	{
		size_t pos = 0;
		while (pos < greater.size() && greater[pos] < lesser[i])
			++pos;
		greater.insert(greater.begin() + pos, lesser[i]);
	}
	
	if (hasAux)
	{
		size_t pos = 0;
		while (pos < greater.size() && greater[pos] < aux)
		++pos;
		greater.insert(greater.begin() + pos, aux);
	}
	
	// std::cout << "Greater: " << show_array(greater) << std::endl;
	// std::cout << "Lesser: " << show_array(lesser) << std::endl;
	// std::cout << "Aux: " << aux << std::endl;
	
	return (greater);	
}