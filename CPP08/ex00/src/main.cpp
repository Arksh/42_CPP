/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:04:56 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/31 17:58:55 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main (void)
{
	// ---- Testing with vectors ----
	{
		std::cout << "----- TEST WITH VECTOR -----" << std::endl;
		
		std::vector<int> test;
	
		for (int i=0;i<20;i++)
			test.push_back(i);
		
		for (int i=-5;i<25;i++)
		{
			try
			{
				std::cout << "search -> " << ::easyfind(test , i)<< std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Exception found -> " << e.what() << '\n';
			}
		}

		std::cout << std::endl << "---- TEST WITH DUPLICATES ----" << std::endl;

		std::vector<int> duplicates;
	
		for (int i=0;i<20;i++)
		{
			duplicates.push_back(i);
			if (i % 2 == 0)
				duplicates.push_back(i);
		}
		
		try
		{
			std::cout << "search -> " << ::easyfind(duplicates, 2) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception found -> " << e.what() << '\n';
		}

		std::cout << std::endl << "---- TEST WITH EMPTY VECTOR ----" << std::endl;

		std::vector<int> empty;
		
		try
		{
			std::cout << "search -> " << ::easyfind(empty, 10) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception found -> " << e.what() << '\n';
		}

		std::cout << std::endl << "---- END TEST WITH VECTORS ----" << std::endl;
	}

	// ---- Testing with lists ----
	{
		std::cout << std::endl << "----- TEST WITH LIST -----" <<  std::endl;
		
		std::list<int> lst;

		for (int i=0;i<=60;i+=10)
			lst.push_back(i);

		for (int i = -15; i <= 60; i += 15)
		{
			try
			{
				std::cout << "search -> " << ::easyfind(lst, i) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Exception found -> " << e.what() << '\n';
			}
		}

		std::cout << "---- TEST WITH DUPLICATES ----" << std::endl;

		std::list<int> dupLst;

		for (int i=10;i<50;i+=10)
		{
			dupLst.push_back(i);
			if (i % 20 == 0)
				dupLst.push_back(30);
		}

		try
		{
			std::cout << "search -> " << ::easyfind(dupLst, 30) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception found -> " << e.what() << '\n';
		}

		std::cout << "---- TEST WITH EMPTY LIST ----" << std::endl;
		
		std::list<int> emptyLst;

		try
		{
			std::cout << "search -> " << ::easyfind(emptyLst, 20) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception found -> " << e.what() << '\n';
		}

		std::cout << "---- END TEST WITH LIST ----" << std::endl;
	}


	// ---- Testing with deques ----
	{
		std::cout << std::endl << "---- TEST WITH DEQUES ----" << std::endl;

		std::deque<int> deq;

		for (int i=1;i<=30;i++)
			deq.push_back(i * 10);

		for (int i=5;i<=60;i+=15)
		{
			try
			{
				std::cout << "search -> " << ::easyfind(deq, i) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Exception found -> " << e.what() << '\n';
			}
		}

		std::cout << std::endl << "---- TEST WITH DUPLICATES ----" << std::endl;

		std::deque<int> dupDeq;

		for (int i=1;i<=30;i++)
		{
			dupDeq.push_back(i * 10);
			if (i % 3 == 0)
				dupDeq.push_back(i);
		}

		try
		{
			std::cout << "search -> " << ::easyfind(dupDeq, 30) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception found -> " << e.what() << '\n';
		}


		std::cout << std::endl << "---- TEST WITH EMPTY DEQUE ----" << std::endl;
		
		std::deque<int> emptyDeq;

		try
		{
			std::cout << "search -> " << ::easyfind(emptyDeq, 30) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception found -> " << e.what() << '\n';
		}

		std::cout << std::endl << "---- END TEST WITH DEQUES ----" << std::endl;
	}


	return 0;
}