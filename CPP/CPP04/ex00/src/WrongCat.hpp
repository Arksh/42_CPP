/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:34:09 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:41:51 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat 			( void );
		~WrongCat			( void );
		WrongCat 			( const WrongCat & w_cat );

		WrongCat &operator=	(const WrongCat &w_cat);
		void makeSound	( void ) const;
};

#endif
