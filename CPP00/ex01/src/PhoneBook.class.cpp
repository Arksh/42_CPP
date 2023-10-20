/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:00:57 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:18:47 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

/**
 * @brief Adds a new contact to the phone book at the specified position.
 *
 * This function prompts the user for input to create a new contact with the
 * following information: first name, last name, nickname, phone number, and
 * secret. The contact is then added to the phone book at the specified
 * position.
 *
 * @param pos The position at which to add the new contact in the phone book.
 */
void PhoneBook::addContact(int pos)
{
	std::string	input;

	std::cout<<"Insert first name : ";
	this->contacts[pos].set_First_name(get_input());
	std::cout<<"Insert last name : ";
	this->contacts[pos].set_Last_name(get_input());
	std::cout<<"Insert nickname : ";
	this->contacts[pos].set_Nickname(get_input());
	std::cout<<"Insert phone number : ";
	this->contacts[pos].set_Phone(get_input());
	std::cout<<"Insert his secret : ";
	this->contacts[pos].set_Darkest_secret(get_input());
	std::cout<<"Contact added to the phone book"<<std::endl<<std::endl;
}

/**
 * @brief Display contact data with proper formatting.
 *
 * This function takes a string and displays it with a width of 10 characters,
 * filling empty spaces with spaces or truncating if necessary.
 *
 * @param str The string to display.
 */
void	PhoneBook::show_data(std::string str)
{
	if (str.length() > 10)
		std::cout<< std::setw(9) <<str.substr(0, 9)<<".";
	else
		std::cout<< std::setfill (' ')<<std::setw(10)<<str.substr(0, 9);
}

/**
 * @brief Display contact information for a specific position.
 *
 * This function displays contact information for a specified position in the PhoneBook.
 * It includes the position number, first name, last name, nickname, and phone number.
 *
 * @param pos The position of the contact to display.
 */
void	PhoneBook::showContact(int pos)
{
	std::cout<<"|  ";
	std::cout<<pos + 1;
	std::cout<<"  |";
	this->show_data(this->contacts[pos].get_First_name());
	std::cout<<"|";
	this->show_data(this->contacts[pos].get_Last_name());
	std::cout<<"|";
	this->show_data(this->contacts[pos].get_Nickname());
	std::cout<<"|";
	this->show_data(this->contacts[pos].get_Phone());
	std::cout<<"|"<<std::endl;
}

/**
 * @brief Display detailed information for a specific contact.
 *
 * This function displays detailed information for a specific contact at the given position.
 * It includes first name, last name, nickname, phone number, and darkest secret.
 *
 * @param pos The position of the contact to display detailed information about.
 */
void	PhoneBook::showSpecificContact(int pos)
{
	std::cout<<"__________________________________________________"<<std::endl;
	std::cout<<"                 Data on index "<<pos + 1<<"                "<<std::endl;
	std::cout<<"__________________________________________________"<<std::endl;
	std::cout<<" First Name : ";
	std::cout << this->contacts[pos].get_First_name()<<std::endl;
	std::cout<<" Last Name : ";
	std::cout << this->contacts[pos].get_Last_name()<<std::endl;
	std::cout<<" Nickname : ";
	std::cout << this->contacts[pos].get_Nickname()<<std::endl;
	std::cout<<" Phone Number :";
	std::cout << this->contacts[pos].get_Phone()<<std::endl;
	std::cout<<" Darkest Secret :";
	std::cout << this->contacts[pos].get_Darkest_secret()<<std::endl;
	std::cout<<"__________________________________________________"<<std::endl<<std::endl;
}

/**
 * @brief Search and display contacts in the PhoneBook.
 *
 * This function displays a list of contacts with their index numbers, first names, last names,
 * nicknames, and phone numbers. It then allows the user to select a contact for detailed information.
 *
 * @param tam The number of contacts to search and display.
 */
void	PhoneBook::searchContact(int tam)
{
	int i;
	std::string input;

	i = 0;
	if (tam != 0)
	{
		std::cout<<"__________________________________________________"<<std::endl;
		std::cout<<"|Index|First Name|Last  Name|Nick  Name|   Phone  |"<<std::endl;
		while (i < tam)
		{
			std::cout<<"__________________________________________________"<<std::endl;
			this->showContact(i);
			i++;
		}
		std::cout<<"__________________________________________________"<<std::endl;
		std::cout<<std::endl<<"Select a number from 1 to "<<tam <<std::endl<<"Index : ";
		getline(std::cin, input);
		if (valid_number(tam, input))
			showSpecificContact(((int)input[0]) - 49);
		else
			std::cout<<"Invalid number input"<<std::endl;
	}
}
