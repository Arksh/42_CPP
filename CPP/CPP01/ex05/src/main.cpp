/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:28:45 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 16:36:29 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
	Harl Harl;

	std::cout << "-------- DEBUG Level --------\n -" << std::flush;
	Harl.complain("DEBUG");
	std::cout << "-------- WARNING Level -------- \n -" << std::flush;
	Harl.complain("WARNING");
	std::cout << "-------- INFO Level --------\n -" << std::flush;
	Harl.complain("INFO");
	std::cout << "-------- ERROR Level --------\n -" << std::flush;
	Harl.complain("ERROR");
	std::cout << "-------- ????? Level --------\n -" << std::flush;
	Harl.complain("STRANGE");
}
