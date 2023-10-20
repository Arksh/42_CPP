/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:59:54 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:35:45 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include "general.hpp"

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone;
		std::string	darkest_secret;

	public:
	//Constructor
	Contact (void);

	//Destructor
	~Contact (void);

	//Gets
	std::string get_First_name(void);
	std::string get_Last_name(void);
	std::string get_Nickname(void);
	std::string get_Phone(void);
	std::string get_Darkest_secret(void);

	//Sets
	void set_First_name(std::string str);
	void set_Last_name(std::string str);
	void set_Nickname(std::string str);
	void set_Phone(std::string str);
	void set_Darkest_secret(std::string str);
};
#endif
