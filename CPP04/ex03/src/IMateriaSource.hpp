/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:39 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/20 13:25:29 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE
# define IMATERIASOURCE

# include "AMateria.hpp"

class	AMateria;

class	IMateriaSource
{
	public:

		virtual	~IMateriaSource			( void ) {}
		virtual	void	learnMateria	( AMateria* ) = 0;
		virtual AMateria* createMateria ( std::string const &type) = 0;
};

#endif
