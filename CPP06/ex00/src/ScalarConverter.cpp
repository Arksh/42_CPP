/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:12:56 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/26 11:48:46 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}

LiteralType ScalarConverter::identify_type(const std::string &str)
{
	double d_value;
	float f_value;

	if (str.length() == 1 && !!isascii(str[0]) && !!std::isdigit(str[0]))
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
		long n = atoi(str.c_str());
		std::cout << n << std::endl;
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
		if ((f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max()) && type_input != PSEUDO_TYPE)
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

/**
 * Convert the textual representation in `str` to a double and print the result to std::cout.
 *
 * Behavior:
 * - If `type_input` is ERROR_TYPE, the function prints "impossible" and returns immediately.
 * - The function attempts to parse `str` using strtod and casts the result to double.
 * - If parsing succeeds, the function checks whether the parsed value is representable
 *   as a double. If the value is outside the range representable by std::numeric_limits<double>
 *   and `type_input` is not PSEUDO_TYPE, the function prints "impossible" and returns.
 * - On successful conversion and range check, the function writes the numeric value to std::cout.
 *   If `type_input` indicates the original literal was an integer or a character (INT_TYPE or CHAR_TYPE),
 *   the function appends ".0" to force a visible decimal point for whole numbers.
 * - If an exception of type std::exception (or a subclass) is thrown during conversion handling,
 *   the function catches it and prints "impossible".
 *
 * Side effects:
 * - Writes output to std::cout (either the converted double or the string "impossible").
 *
 * Parameters:
 * - str: the input string containing the literal to convert to double.
 * - type_input: the detected literal type (e.g., ERROR_TYPE, PSEUDO_TYPE, INT_TYPE, CHAR_TYPE, etc.).
 *
 * Notes:
 * - Pseudo-literals (e.g., "nan", "+inf", "-inf") are treated as PSEUDO_TYPE; for these values
 *   the range check against numeric_limits<double> is skipped.
 * - The function does not return a value; results are communicated only via std::cout.
 * - Parsing uses the C library strtod; behavior is subject to the current C locale and strtod semantics.
 */
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
		if ((d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max()) && type_input != PSEUDO_TYPE)
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