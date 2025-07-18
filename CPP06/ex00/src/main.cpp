/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:04:56 by cagonzal          #+#    #+#             */
/*   Updated: 2025/07/18 14:31:36 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include<iostream>
#include <sstream>

/*
void leaks(void)
{
	system("leaks -q test");
}
*/


int main (int argc, char **argv)
{
    LiteralType type;
    ScalarConverter converter = ScalarConverter();
    
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    try
    {
        type = converter.identify_type(argv[1]);
        std::cout << "char: ";
        converter.toChar(argv[1], type);
        std::cout << "int: ";
        converter.toInteger(argv[1], type);
        std::cout << "float: ";
        converter.toFloat(argv[1], type);
        std::cout << "double: ";
        converter.toDouble(argv[1], type);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    converter.~ScalarConverter();
    return 0;
}