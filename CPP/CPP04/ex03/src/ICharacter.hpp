/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:39 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 16:42:56 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_ICHARACTER_HPP
# define I_ICHARACTER_HPP

# include <iomanip>
# include "AMateria.hpp"

class	AMateria;

class	ICharacter
{
	public:
		virtual	~ICharacter					( void );
		virtual std::string const  &getName	( void ) const = 0;
		virtual	void use					( int id, ICharacter& target ) = 0;
		virtual	void equip					( AMateria* m ) = 0;
		virtual	void unequip				( int idx ) = 0;
};

#endif
