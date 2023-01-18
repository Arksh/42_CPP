/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:34:35 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:59:01 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog 			( void );
		~Dog			( void );
		Dog 			( const Dog & dog );

		Dog &operator=	( const Dog &dog );
		void makeSound	( void ) const;
};

#endif
