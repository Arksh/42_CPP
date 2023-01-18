/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:34:26 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:34:29 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat 			( void );
		~Cat			( void );
		Cat 			( const Cat & cat );

		Cat &operator=	(const Cat &cat);
		void makeSound	( void ) const;
};

#endif
