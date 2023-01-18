/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:33:30 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:36:03 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iomanip>
# include <iostream>

class	Animal
{
	protected:
		std::string type;

	public:
		Animal 					( void );
		virtual ~Animal			( void );
		Animal 					( const Animal & anim );
		Animal 					( std::string str );

		virtual void makeSound	( void ) const;
		std::string getType		( void ) const;

		Animal &operator=		(const Animal &anim);

};

#endif
