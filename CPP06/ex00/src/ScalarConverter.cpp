/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:12:56 by cagonzal          #+#    #+#             */
/*   Updated: 2025/07/18 15:19:07 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}

LiteralType ScalarConverter::identify_type(const std::string &str)
{
	double d_value;
	float f_value;

	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return CHAR_TYPE;

	if (!str.compare("nan") || !str.compare("inf") || !str.compare("+inf") || !str.compare("-inf"))
		return PSEUDO_TYPE;
	else if (!str.compare("nanf") || !str.compare("inff") || !str.compare("+inff") || !str.compare("-inff"))
		return PSEUDO_TYPE;
	
	if(str[str.length()- 1] == 'f' && str.length() > 1)
	{
		try
		{
			f_value = strtod(str.substr(0, str.length() - 1).c_str(), NULL);
			(void)f_value;
			return FLOAT_TYPE;
		}
		catch (const std::exception &)
		{
			return ERROR_TYPE;
		}
	}

	// 4. DOUBLE_TYPE OR INT_TYPE
	try
	{
		d_value = strtof(str.c_str(), NULL);
		(void)d_value;
		if (str.find('.') != std::string::npos || str.find('f') != std::string::npos)
			return DOUBLE_TYPE;
		else
			return INT_TYPE;
	}
	catch (const std::exception &)
	{
		return ERROR_TYPE;
	}
}

void ScalarConverter::toChar(const std::string &str, LiteralType type_input)
{
	if (type_input != CHAR_TYPE && type_input != INT_TYPE)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	int i = atoi(str.c_str());
	if (i < 0 || i > 127)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(i);
	if (c >= 32 && c <= 126)
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::toInteger(const std::string &str, LiteralType type_input)
{
	if (type_input != CHAR_TYPE && type_input != INT_TYPE)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	
	try
	{
		long n = strtol(str.c_str(), NULL, 10);
		if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		{
			std::cout << "impossible" << std::endl;
			return;
		}
		std::cout << static_cast<int>(n) << std::endl;
	}
	catch (const std::exception &)
	{
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::toFloat(const std::string &str, LiteralType type_input)
{
	if (type_input == ERROR_TYPE)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	try
	{
		float f = static_cast<float>(strtod(str.c_str(), NULL));
		if ((f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::min()) && type_input != PSEUDO_TYPE)
		{
			std::cout << "impossible" << std::endl;
			return;
		}
		std::cout << f;
		if (type_input == INT_TYPE || type_input == CHAR_TYPE)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	catch (const std::exception &)
	{
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::toDouble(const std::string &str, LiteralType type_input)
{
	if (type_input == ERROR_TYPE)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	try
	{
		double d = static_cast<double>(strtod(str.c_str(), NULL));
		if ((d > std::numeric_limits<double>::max() || d < std::numeric_limits<double>::min()) && type_input != PSEUDO_TYPE)
		{
			std::cout << "impossible" << std::endl;
			return;
		}
		std::cout << d;
		if (type_input == INT_TYPE || type_input == CHAR_TYPE)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch (const std::exception &)
	{
		std::cout << "impossible" << std::endl;
	}
}