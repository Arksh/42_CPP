/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:00:49 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:12:07 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

/**
 * @brief Default constructor for the Contact class.
 *
 *	Initializes a Contact object with empty values for first name,
 *	last name, nickname, phone, and darkest secret.
 */
Contact::Contact(void)
{
	this->set_First_name("");
	this->set_Last_name("");
	this->set_Nickname("");
	this->set_Phone("");
	this->set_Darkest_secret("");
	return;
}

//Destructor
Contact::~Contact(void)
{
	std::cout<<"Destruimos el contacto"<<std::endl;
	return;
}

//Gets
std::string Contact::get_First_name(void)
{
	return (this->first_name);
}

std::string Contact::get_Last_name(void)
{
	return (this->last_name);
}

std::string Contact::get_Nickname(void)
{
	return (this->nickname);
}

std::string Contact::get_Phone(void)
{
	return (this->phone);
}

std::string Contact::get_Darkest_secret(void)
{
	return (this->darkest_secret);
}

//Sets
void Contact::set_First_name(std::string str)
{
	this->first_name = str;
}

void Contact::set_Last_name(std::string str)
{
	this->last_name = str;
}

void Contact::set_Nickname(std::string str)
{
	this->nickname = str;
}

void Contact::set_Phone(std::string str)
{
	this->phone = str;
}

void Contact::set_Darkest_secret(std::string str)
{
	this->darkest_secret = str;
}
