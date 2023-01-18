/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:34:53 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:39:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iomanip>
# include <iostream>

class	WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal 				( void );
		virtual ~WrongAnimal		( void );
		WrongAnimal 				( const WrongAnimal & w_anim );
		WrongAnimal 				( std::string str );

		virtual void makeSound		( void ) const;
		std::string getType			( void ) const;

		WrongAnimal &operator=		( const WrongAnimal &w_anim );

};

#endif
