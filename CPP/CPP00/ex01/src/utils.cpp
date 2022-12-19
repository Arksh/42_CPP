/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:23:52 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/14 13:47:53 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

std::string get_input(void)
{
	std::string	input;
	getline(std::cin, input);
	if (input.empty())
		return ("");
	return (input);
}

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
