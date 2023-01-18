/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:14:14 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 11:14:17 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:

		FragTrap 			( void );
		FragTrap 			( std::string str );
		FragTrap 			( const FragTrap & frag );
		~FragTrap			( void );
		FragTrap &operator=	( const FragTrap &frag );

		void highFivesGuys	( void );
};

#endif
