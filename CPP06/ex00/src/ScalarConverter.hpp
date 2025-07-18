/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:00:39 by cagonzal          #+#    #+#             */
/*   Updated: 2025/07/18 15:01:44 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>

// Enum for type identification
enum LiteralType
{
	ERROR_TYPE = -1,
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	PSEUDO_TYPE
};

class ScalarConverter
{
	public:
	// Constructors
	ScalarConverter();
		
	void	toChar(const std::string &str, LiteralType type_input);
	void	toInteger(const std::string &str, LiteralType type_input);
	void	toFloat(const std::string &str, LiteralType type_input);
	void	toDouble(const std::string &str, LiteralType type_input);
	LiteralType	identify_type(const std::string &str);

	// Destructor
	~ScalarConverter();
	
};

#endif