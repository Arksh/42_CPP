/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:15:02 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 11:15:03 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string		_name;

	public:
		DiamondTrap 			( void );
		DiamondTrap 			( std::string str );
		DiamondTrap 			( const DiamondTrap & diam );
		~DiamondTrap			( void );
		DiamondTrap &operator=	( DiamondTrap const &clap );

		using ScavTrap::attack;
		void whoAmI(void);
};

#endif
