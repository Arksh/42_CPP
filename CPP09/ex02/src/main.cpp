/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:33:37 by cagonzal          #+#    #+#             */
/*   Updated: 2025/12/06 13:29:47 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"



int main (int argc, char **argv)
{
	std::string			origin;
	std::vector<int>	_test1;
	std::deque<int>		_test2;
	// clock_t t1;
	// clock_t t2;

	origin = get_input(argc, argv);
	if (argc >= 2)
	{
		if (check_input(origin, ' '))
		{
			std::cout << "Input: \t" << origin << std::endl;
			_test1 = extract_data<std::vector<int> >(origin, ' ');
			_test2 = extract_data<std::deque<int> >(origin, ' ');
			if (check_duplicates(_test1,_test2))
			{
				std::cout << "Error duplicates numbers found" << std::endl;
				return (0);
			}

			// t1 = clock();
			// t2 = clock();
			std::cout << "Vector before: \t" << show_array(_test1) << std::endl;
			_test1 = merge_sort<std::vector<int> >(_test1);
			std::cout << "Vector after: \t" << show_array(_test1) << std::endl;
			// std::cout << "Time to process a range of "<< _test1.size() <<" elements with std::vector :  " << (static_cast<double>(t2 - t1)) << " µs - "<< (static_cast<double>(t2 - t1)/CLOCKS_PER_SEC)<< " s" << std::endl;
			// t1 = clock();
			// std::cout << "Deque before: \t" << show_array(_test2) << std::endl;
			// _test2 = merge_sort<std::deque<int> >(_test2);
			// std::cout << "Deque after: \t" << show_array(_test2) << std::endl;
			// t2 = clock();
			// std::cout << "Time to process a range of "<< _test2.size() <<" elements with std::deque :  " << (static_cast<double>(t2 - t1)) << " µs - "<< (static_cast<double>(t2 - t1)/CLOCKS_PER_SEC)<< " s" << std::endl;
			
			
		}
		else 
		{
			std::cout << "Error found on input" << std::endl;
			return (0);
		}
	}
    return 0;
}