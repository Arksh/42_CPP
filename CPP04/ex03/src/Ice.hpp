/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:27 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 15:32:31 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class	Ice : public AMateria
{
	public:
		Ice					( void );
		Ice					( Ice const & materia );
		~Ice				( void );
		Ice &operator=		( const Ice &amateria );
		AMateria* clone		( void ) const;
		// void use(ICharacter& target);

};

#endif
