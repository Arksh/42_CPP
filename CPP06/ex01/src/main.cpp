/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:33:31 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/30 11:33:43 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#include <iostream>
#include <sstream>

int main (void)
{
	//atexit(leaks);
	Data *origin = new Data("Jeff");
	Data *passby;
	uintptr_t dir_pointer;
    
	dir_pointer = serialize(origin);
	std::cout << "______________________________" << std::endl;
	std::cout << "Data Pointer Origin	: " << origin << std::endl;
	std::cout << "Data Serialized		: " << dir_pointer << std::endl;
	std::cout << "______________________________" << std::endl;
	passby = deserialize(dir_pointer);
	std::cout << "______________________________" << std::endl;
	std::cout << "Data Pointer Origin	: " << origin << std::endl;
	std::cout << "Data Pointer Passby	: " << passby << std::endl;
	std::cout << "______________________________" << std::endl;
	return (0);
}