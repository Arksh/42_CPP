/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:14:55 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/11 11:18:44 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPts;
		int			_energyPts;
		int			_attackDmg;

	public:
		ClapTrap			( void );
		ClapTrap			( std::string name );
		ClapTrap			( const ClapTrap & clap );
		virtual ~ClapTrap			( void );
		ClapTrap &operator=	( const ClapTrap &tmp );

		void set_hp			( int amount );
		void set_energy		( int amount );
		void set_attack		( int amount );

		int get_hp			( void );
		int get_energy		( void );
		int get_attack		( void );

		virtual void attack	( std::string const &target );
		void takeDamage		( unsigned int amount );
		void beRepaired		( unsigned int amount );

};

#endif
