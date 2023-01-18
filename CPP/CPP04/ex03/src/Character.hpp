/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:40:04 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 16:48:02 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		int inv_tam;
		AMateria *inventory[4];

	public:
		Character	( void );
		~Character	( void );
		Character	( std::string str );
		Character	( const Character & cha );

		Character &operator=		( const Character &cha );
		std::string const & getName	( void ) const;

		void use		( int idx, ICharacter& target );
		void equip		( AMateria* m );
		void unequip	( int idx );

};

#endif
