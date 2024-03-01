/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:50 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 16:27:11 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE
#define MATERIA_SOURCE

#include "IMateriaSource.hpp"

class AMateria;

class	MateriaSource : public IMateriaSource
{
	private:
			int learn_tam;
			AMateria *learned[4];
	public:
			MateriaSource				( void );
			MateriaSource				(const MateriaSource &source);
			~MateriaSource				( void );
			MateriaSource operator=		(const MateriaSource &source);
			void learnMateria			(AMateria* m);
			AMateria* createMateria		(std::string const & type);

};
std::ostream &operator<<(std::ostream& os, const MateriaSource &tmp);

#endif
