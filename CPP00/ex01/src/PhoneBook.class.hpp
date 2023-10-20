/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:00:03 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:35:50 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "general.hpp"
#include "Contact.class.hpp"

class PhoneBook
{
	public:
		Contact	contacts[8];

	//Constructor
	PhoneBook (void);

	//Destructor
	~PhoneBook (void);

	//Functions
	void	addContact(int pos);
	void	searchContact(int tam);
	void	showContact(int pos);
	void	showSpecificContact(int pos);
	void	show_data(std::string str);
};
#endif

