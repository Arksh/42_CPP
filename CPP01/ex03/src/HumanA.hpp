/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:17:05 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 13:53:13 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon		&weapon;
		std::string	name;

	public:
		HumanA			(void);
		HumanA			(std::string str, Weapon &Weapon);
		~HumanA			(void);
		void attack		(void);
};

#endif
