/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:28:45 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 16:50:18 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv)
{
	int i = 1;
	Harl Harl;
	std::string str;

	while (i < argc)
	{
		str = argv[i++];
		Harl.complain(str);
	}
}
