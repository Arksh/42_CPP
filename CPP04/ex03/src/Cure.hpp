/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:27 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 15:32:31 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
# define Cure_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure					( void );
		Cure					( Cure const & materia );
		~Cure				( void );
		Cure &operator=		( const Cure &amateria );
		AMateria* clone		( void ) const;
		// void use(ICharacter& target);

};

#endif
