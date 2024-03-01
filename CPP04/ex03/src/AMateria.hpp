/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:28:02 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/20 13:23:13 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <iomanip>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class	AMateria
{
	protected:
		std::string type;

	public:
		AMateria					( void );
		AMateria					( std::string const & str );
		virtual ~AMateria			( void );

		AMateria &operator=			(const AMateria &amateria);

		std::string const &getType	( void ) const;
		virtual AMateria* clone		( void ) const = 0;
		virtual void use			( ICharacter& target );
};

#endif
