/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:15:41 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:31:52 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//clang++ main.cpp
#include "general.hpp"

/**
 * @brief The main entry point of the program.
 *
 * This function initializes a PhoneBook, allows the user to interact with it
 * by adding contacts and searching for contacts until the user enters "EXIT."
 * It provides a simple command-line interface for managing contacts.
 *
 * @return An integer representing the exit status of the program.
 */
int main (void)
{
	PhoneBook	libro;
	int			i;
	int			t_max;
	std::string		input;

	i = 0;
	t_max = 0;
	while (input != "EXIT")
	{
		std::cout<<"Options Available are"<<std::endl<<"ADD \\ SEARCH \\ EXIT"<<std::endl;
		input = get_input();
		if (input == "ADD")
		{
			if (i == 8)
				i = 0;
			if (t_max != 8)
				t_max++;
			libro.addContact(i++);
		}
		else if (input == "SEARCH")
			libro.searchContact(t_max);
		else if (input == "EXIT")
			std::cout<<"Clossing ..."<<std::endl;
		else
			std::cout<<"Options Available are"<<std::endl<<"ADD \\ SEARCH \\ EXIT"<<std::endl;
	}
	return (0);
}
