/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:39 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 16:42:23 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_IMATERIASOURCE_HPP
# define I_IMATERIASOURCE_HPP

# include "AMateria.hpp"

class	AMateria;

class	IMateriaSource
{
	public:

		virtual	~IMateriaSource			( void );
		virtual	void	learnMateria	( AMateria* ) = 0;
		virtual AMateria* createMateria ( std::string const &type) = 0;
};

#endif
