/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:52:44 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:47:27 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/**
 * @brief Main function for demonstrating pointers and references with a string variable.
 *
 * This program demonstrates the use of references and pointers in C++ using the following variables:
 *
 * str: A std::string variable used to store a text value.
 * strREF: A reference to str, serving as an alias to the original variable.
 * strPTR: A pointer to str, storing its memory address.
 *
 * @return 0 on successful execution.
 */

int	main(void)
{
	std::string		str;
	std::string		&strREF = str;
	std::string*	strPTR = &str;

	str = "HI THIS IS BRAIN";
	std::cout<<"FRASES"<<std::endl;
	std::cout<<"El valor original               ->"<<str<<std::endl;
	std::cout<<"El valor al que hace referencia ->"<<strREF<<std::endl;
	std::cout<<"El valor dentro del puntero     ->"<<*strPTR<<std::endl;

	std::cout<<"PUNTEROS"<<std::endl;
	std::cout<<"La direccion del valor original ->"<<&str<<std::endl;
	std::cout<<"La direccion a la referencia    ->"<<&strREF<<std::endl;
	std::cout<<"El valor del puntero            ->"<<strPTR<<std::endl;

	return(0);
}
