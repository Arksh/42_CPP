/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:16:42 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 13:23:03 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include <iostream>

class	Weapon
{
	private:
		std::string	type;

	public:
		Weapon		( void );
		Weapon		( std::string str );
		~Weapon		( void );
		const std::string getType(void);
		void setType(std::string str);

};

#endif
