/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:23:52 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:24:15 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

/**
 * @brief Get a line of input from the standard input (stdin).
 *
 * This function reads a line of text from the standard input (stdin) and returns it as a string.
 *
 * @return A string containing the input text.
 */
std::string get_input(void)
{
	std::string	input;
	getline(std::cin, input);
	if (input.empty())
		return ("");
	return (input);
}

/**
 * @brief Validate if a string represents a valid number within a specified range.
 *
 * This function checks if a given string represents a valid number within the range [1, current_tam].
 * It verifies that the string contains only one digit and that the digit is within the valid range.
 *
 * @param current_tam The upper limit for the valid range.
 * @param str The string to validate as a number.
 * @return 1 if the string is a valid number within the specified range, 0 otherwise.
 */
int	valid_number(int current_tam, std::string str)
{
	int i;

	if (str.length() > 2 || str.length() == 0)
		return (0);
	if (!isdigit(str[0]))
		return (0);
	i = ((int)str[0]) - 48;
	if (i >= 0 && i <= current_tam)
		return (1);
	return (0);
}
