/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:14:56 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/30 12:36:53 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <exception>

class Base
{
	public:
		virtual ~Base();
		static Base *generate();
		static void identify(Base* p);
		static void identify(Base& p);

		class CastException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Failed to cast Base reference to derived class.";
				}
		};
};

#endif