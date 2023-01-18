/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:50:09 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:53:37 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iomanip>
# include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain ( void );
		virtual ~Brain ( void );
		Brain ( const Brain &brain );

		virtual std::string getIdea ( int index );
		Brain& operator= ( Brain const & brain );
};

#endif
