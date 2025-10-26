/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:12:56 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/26 10:50:23 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}

/**
 * Identify the literal type represented by the given string.
 *
 * The function examines the input string and classifies it into one of the
 * LiteralType categories (CHAR_TYPE, PSEUDO_TYPE, FLOAT_TYPE, DOUBLE_TYPE,
 * INT_TYPE, or ERROR_TYPE) using the following rules:
 *
 * 1. Single printable non-digit character:
 *    - If the string length is 1, the single character is printable
 *      (std::isprint) and not a digit, the function returns CHAR_TYPE.
 *
 * 2. Pseudo-literals (special floating-point values):
 *    - If the string exactly matches one of:
 *        "nan", "inf", "+inf", "-inf", "nanf", "inff", "+inff", "-inff"
 *      the function returns PSEUDO_TYPE.
 *
 * 3. Float literal with 'f' suffix:
 *    - If the string ends with 'f' and has length > 1, the substring
 *      excluding the trailing 'f' is attempted to be parsed as a floating
 *      value. If parsing succeeds the function returns FLOAT_TYPE; on parse
 *      failure it returns ERROR_TYPE.
 *
 * 4. Double or integer literal:
 *    - Otherwise the full string is attempted to be parsed as a floating
 *      value. If parsing succeeds and the original string contains a '.'
 *      or an 'f' the function returns DOUBLE_TYPE. If it does not contain
 *      those characters it is classified as INT_TYPE. On parse failure the
 *      function returns ERROR_TYPE.
 *
 * Notes:
 * - Parsing is performed via C library conversions on the candidate substrings.
 * - The function does not modify the input string and has no side effects.
 * - Time complexity is O(n) where n is the length of the input string.
 *
 * Parameters:
 *  - str: the input string to classify.
 *
 * Returns:
 *  - A LiteralType enum value representing the detected literal type
 *    (CHAR_TYPE, PSEUDO_TYPE, FLOAT_TYPE, DOUBLE_TYPE, INT_TYPE, or ERROR_TYPE).
 */
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

/**
 * Convert the given literal string to a char and print the result to std::cout.
 *
 * This function only handles inputs whose LiteralType is CHAR_TYPE or INT_TYPE.
 * The string is interpreted as an integer using std::atoi and then checked and
 * converted to a char for output.
 *
 * @param str        The input string representing the literal value (expected numeric form).
 * @param type_input The detected literal type; only CHAR_TYPE and INT_TYPE are accepted.
 *
 * Behavior:
 * - If type_input is not CHAR_TYPE or INT_TYPE, prints "impossible" and returns.
 * - Parses str with std::atoi to produce an int value.
 * - If the parsed int is outside the valid ASCII range [0, 127], prints "impossible" and returns.
 * - Casts the int to char. If the resulting char is a printable ASCII character (32..126),
 *   prints it enclosed in single quotes (e.g. 'A'). Otherwise prints "Non displayable".
 *
 * Side effects:
 * - Writes output to std::cout.
 * - Returns no value (void).
 *
 * Notes:
 * - std::atoi parsing rules apply (e.g. non-numeric input yields 0).
 * - The printable range is limited to standard printable ASCII characters.
 */
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

/**
 * Attempt to convert the given string to an int and print the result or "impossible".
 *
 * The function accepts only CHAR_TYPE or INT_TYPE as valid type_input values. If the type is
 * not one of these, the function prints "impossible" and returns.
 *
 * Conversion procedure:
 * - Parses the input string as a base-10 integer using strtol(str.c_str(), NULL, 10).
 * - If the parsed long value is outside the range representable by int
 *   (std::numeric_limits<int>::min() .. std::numeric_limits<int>::max()), prints "impossible".
 * - On successful conversion within range, prints the integer value to std::cout followed by a newline.
 * - Any std::exception thrown during processing is caught and results in printing "impossible".
 *
 * Notes:
 * - strtol accepts leading whitespace and an optional '+' or '-' sign.
 * - The end pointer from strtol is ignored; partial conversions or trailing non-numeric characters
 *   will follow strtol's behavior and may lead to "impossible" if the numeric result is invalid
 *   for an int.
 * - Output is side-effecting (written to std::cout); the function returns void.
 *
 * Parameters:
 * @param str        The input string to convert.
 * @param type_input The detected literal type; conversion proceeds only for CHAR_TYPE or INT_TYPE.
 */
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

/**
 * Convert the given input string to a float value and write a formatted
 * representation to standard output.
 *
 * This routine interprets the input according to the provided LiteralType
 * and prints either a float literal or the word "impossible" if conversion
 * or range rules disallow producing a valid float representation.
 *
 * Behavior:
 *  - If type_input == ERROR_TYPE, prints "impossible" and returns.
 *  - Attempts to parse the input string as a double via strtod() and then
 *    narrows the result to float (static_cast<float>).
 *  - If the resulting float is outside the representable float range
 *    (f > numeric_limits<float>::max() or f < numeric_limits<float>::min())
 *    and the input is not a pseudo-literal (type_input != PSEUDO_TYPE),
 *    prints "impossible" and returns.
 *  - On success prints the float value, appends ".0" when the original
 *    literal type was an integer or a char (INT_TYPE or CHAR_TYPE) to
 *    indicate a decimal point, then appends the 'f' suffix and a newline.
 *  - Pseudo-literals (PSEUDO_TYPE) such as "nan", "+inf", "-inf" are allowed
 *    through the range check and are printed as produced by the float value.
 *
 * Notes and limitations:
 *  - Parsing is done with strtod(), and narrowing from double to float is
 *    performed with static_cast<float>. This may introduce rounding.
 *  - The range check uses numeric_limits<float>::min(), which is the smallest
 *    positive normalized value; negative values and subnormal numbers may be
 *    affected by this check in a way that differs from a strict overflow test.
 *  - Any std::exception thrown during processing is caught and handled by
 *    printing "impossible".
 *
 * Parameters:
 *  - str: the input string containing the literal to convert.
 *  - type_input: a LiteralType enum value describing the detected kind of
 *                literal (e.g. CHAR_TYPE, INT_TYPE, FLOAT_TYPE, DOUBLE_TYPE,
 *                PSEUDO_TYPE, ERROR_TYPE).
 *
 * Side effects:
 *  - Writes output to std::cout. No value is returned.
 */
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