/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:12:11 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/31 18:41:37 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	{
		std::cout << "----- BASIC ADD TEST -----" << std::endl;
		
		Span sp(5);  // máximo 5 elementos
		
		try
		{
			sp.addNumber(10);
			sp.addNumber(3);
			sp.addNumber(7);
			sp.addNumber(1);
			sp.addNumber(5);
			std::cout << "All numbers added successfully." << std::endl;
			
			// Intento de agregar uno más → debe lanzar excepción
			sp.addNumber(100);
		}
		catch (const std::exception& e)
		{
			std::cout << "Expected exception caught: " << e.what() << std::endl;
		}
	}

	{
		std::cout << "----- SPAN WITH FEW ELEMENTS -----" << std::endl;
		
		Span sp_empty(5);
		Span sp_one(5);
		sp_one.addNumber(42);
		
		Span sp_two(5);
		sp_two.addNumber(10);
		sp_two.addNumber(20);

		try
		{
			sp_empty.shortestSpan(); // excepción: no hay elementos
		}
		catch (const std::exception& e)
		{
			std::cout << "Expected exception for empty Span: " << e.what() << std::endl;
		}

		try
		{
			sp_one.longestSpan(); // excepción: solo un elemento
		}
		catch (const std::exception& e)
		{
			std::cout << "Expected exception for single-element Span: " << e.what() << std::endl;
		}

		try 
		{
			std::cout << "Shortest span (2 elements): " << sp_two.shortestSpan() << std::endl;
			std::cout << "Longest span (2 elements): " << sp_two.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception not expected here: " << e.what() << std::endl;
		}
	}
	
	{
		std::cout << "----- SPAN WITH MULTIPLE ELEMENTS -----" << std::endl;
		
		Span sp(10);
		sp.addNumber(10);
		sp.addNumber(3);
		sp.addNumber(20);
		sp.addNumber(7);
		sp.addNumber(3);  // duplicado
		
		try
		{
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Unexpected exception: " << e.what() << std::endl;
		}
	}
	
	{
		std::cout << "----- LARGE SPAN TEST -----" << std::endl;

		std::srand(std::time(NULL)); 

		const int N = 10000;
		Span sp(N);
		std::vector<int> values;
		values.reserve(N);

		for (unsigned int i = 0; i < N; ++i)
			values.push_back(std::rand() % 100000);
		
		sp.addNumbers(values.begin(), values.end());		

		try
		{
			std::cout << "Shortest span (large): " << sp.shortestSpan() << std::endl; // debe ser 1
			std::cout << "Longest span (large): " << sp.longestSpan() << std::endl;   // debe ser N-1
		}
		catch (const std::exception& e)
		{
			std::cout << "Unexpected exception in large test: " << e.what() << std::endl;
		}
	}
}