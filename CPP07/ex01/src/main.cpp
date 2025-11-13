/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:57:53 by cagonzal          #+#    #+#             */
/*   Updated: 2025/11/13 12:30:59 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iomanip>
#include <iostream>


int main( void ) 
{
	
	//Version Tester
	int tab[] = { 0, 1, 2, 3, 4 };
	Tester tab2[5];
	iter(tab, 5, print<const int>);
	iter(tab2, 5, print<Tester>);	

	
	// // Own version
	int integer[5] = {1,2,3,4,5};
	// const int c_integer[5] = {1,2,3,4,5};
	float floats[5] = {10.1f,20.1f,30.1f,40.1f,50.1f};
	double doubles[5] = {0.01,1.01,2.01,3.01,4.01};
	std::string strings[5] = {"Hola","que","tal","estas","?"};
	
	
	try
	{
		std::cout << "Integer" << std::endl;
		iter( integer, 5, print<int>);
		std::cout << "- - - add 1 - - - - -" << std::endl;
		iter( integer, 5, increment<int>);
		iter( integer, 5, print<int>);
		std::cout << "- - - rest 1 - - - - -" << std::endl;
		iter( integer, 5, decrement<int>);
		iter( integer, 5, print<int>);
		std::cout << "___________________________" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Something happened"<< std::endl;
	}

	try
	{
		std::cout << "Const Integer" << std::endl;
		iter(integer, 5, print<const int>);
		std::cout << "___________________________" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Something happened"<< std::endl;
	}
	
	try
	{
		std::cout << "Float" << std::endl;
		iter( floats, 5, print<float>);
		std::cout << "- - - add 1 - - - - -" << std::endl;
		iter( floats, 5, increment<float>);
		iter( floats, 5, print<float>);
		std::cout << "- - - rest 1 - - - - -" << std::endl;
		iter( floats, 5, decrement<float>);
		iter( floats, 5, print<float>);
		std::cout << "___________________________" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Something happened"<< std::endl;
	}

	try
	{
		std::cout << "Doubles" << std::endl;
		iter( doubles, 5, print<double>);
		std::cout << "- - - add 1 - - - - -" << std::endl;
		iter( doubles, 5, increment<double>);
		iter( doubles, 5, print<double>);
		std::cout << "- - - rest 1 - - - - -" << std::endl;
		iter( doubles, 5, decrement<double>);
		iter( doubles, 5, print<double>);
		std::cout << "___________________________" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Something happened"<< std::endl;
	}

	
	try
	{
		std::cout << "strings" << std::endl;
		iter( strings, 5, print<std::string>);
		std::cout << "- - - add a - - - - -" << std::endl;
		iter( strings, 5, append_a_char<std::string>);
		iter( strings, 5, print<std::string>);
		std::cout << "___________________________" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Something happened"<< std::endl;
	}

	return 0; 

}