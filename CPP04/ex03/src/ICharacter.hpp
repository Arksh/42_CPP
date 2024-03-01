/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:39 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/20 13:20:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER
# define ICHARACTER

# include <iomanip>
# include "AMateria.hpp"

class	AMateria;

class	ICharacter
{
	public:
		virtual	~ICharacter					( void ){}
		virtual std::string const  &getName	( void ) const = 0;

		virtual	void use					( int id, ICharacter& target ) = 0;
		virtual	void equip					( AMateria* m ) = 0;
		virtual	void unequip				( int idx ) = 0;
};

#endif
