/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:20:46 by cagonzal          #+#    #+#             */
/*   Updated: 2025/11/28 19:57:58 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <iostream>
#include <list>
#include <cmath>
#include <exception>

typedef std::list<std::string>::iterator iterator;

class	RPN {

	private:
	std::list <std::string> list;
	public:
		class ErrorRPN : public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Error"; };
		};

		RPN 			( void ) {};
		RPN 			( std::string str ) { (void)str; };
		RPN 			( const RPN & var ) { *this = var;  };
		~RPN			( void ) {};
		RPN &operator=	( const RPN &tmp);

		std::list <std::string> getlist	(void) const {return(this->list);};

		void 	fillRPN		( std::string str , char c);
		bool 	isOperator	(std::string str);
		bool 	isIntNumber	(std::string str);
		bool 	check_input	();

		std::string	get_answer	(void);
};
std::ostream &operator<<(std::ostream& os, const RPN &tmp);

#endif