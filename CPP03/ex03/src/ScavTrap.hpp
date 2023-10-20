/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:15:15 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 11:20:00 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{

	public:
		ScavTrap			( void );
		ScavTrap			( std::string name);
		ScavTrap			( const ScavTrap & scav );
		~ScavTrap			( void );
		ScavTrap& operator=	(ScavTrap const & clap );

		void guardGate		( void );
};

#endif
