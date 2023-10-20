/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:13:06 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:54:52 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <string>
#include <iostream>

class	Harl
{
	private:
		typedef void (Harl::*funptr) ( void );
		void debug		( void );
		void info		( void );
		void warning	( void );
		void error		( void );

	public:
		Harl 			( void );
		~Harl			( void );
		void complain	( std::string level );
};

#endif
