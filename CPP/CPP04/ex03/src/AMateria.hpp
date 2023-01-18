/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:28:02 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 16:42:07 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iomanip>
# include "ICharacter.hpp"
# include <iomanip>
# include <iostream>

class ICharacter;

class	AMateria
{
	protected:
		std::string type;

	public:
		AMateria					( void );
		AMateria					( std::string const & str );
		virtual ~AMateria			( void );

		std::string const &getType	( void ) const;
		virtual AMateria* clone		( void ) const = 0;
		virtual void use			( ICharacter& target );

		AMateria &operator=			(const AMateria &amateria);
};

#endif
