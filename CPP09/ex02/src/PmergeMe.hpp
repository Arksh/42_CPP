/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:33:22 by cagonzal          #+#    #+#             */
/*   Updated: 2025/12/05 15:48:19 by cagonzal         ###   ########.fr       */
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
std::string	get_input(int argc, char **argv);
bool		isIntNumber(std::string str);

//Check data integrity
bool		input_on_list(const std::vector<int> &vec, const std::deque<int> &deq);
bool		check_input(const std::string &input, char del);


//show list
template <typename T>
std::string	show_array(T list)
{
	std::string	aux = "";
	std::stringstream ss;

	for (int x = 0; x < (int)list.size();x++)
		ss << list[x] << " ";
	ss >> aux;
	return (aux);
}

//Template to extract data
template <typename T>
T					extract_data(const std::string &input, char del)
{
	T aux;
	std::stringstream ss(input);
	std::string item;
	
	// Phase 1: split the input string by the delimiter
	while (std::getline(ss, item, del))
	// Phase 2: convert each substring to an integer and insert each integer into the container T	
		if (isIntNumber(item) && item != "")
			aux.push_back(atoi(item.c_str()));

	std::cout << show_array(aux) << std::endl;
	return aux;
}

//Template to sort
template <typename T>
/**
 * @brief Sorts a list using bubble sort algorithm.
 * 
 * @details Performs a simple bubble sort on the provided list by repeatedly
 *          comparing adjacent elements and swapping them if they are in the
 *          wrong order. The algorithm continues until the entire list is sorted.
 * 
 * @tparam T The type of the list container (must support operator[], size(), and comparison operators).
 * 
 * @param list Reference to the list to be sorted. The list is modified in-place.
 * 
 * @return T The sorted list (same reference as input parameter).
 * 
 * @note This implementation has O(n²) time complexity in the average and worst cases.
 *       It is not recommended for large datasets due to poor performance.
 * 
 * @warning The function assumes the list contains comparable elements that support
 *          the greater-than operator (>).
 */
T					sort(T &list)
{
	int		aux;
	
	for (int x = 0;x < (int)list.size() - 1; x++)
	{
		if (list[x] > list[x + 1])
		{
			aux = list[x];
			list[x] = list[x + 1];
			list[x + 1] = aux;
			x = -1;
		}
	}
	return (list);	
}