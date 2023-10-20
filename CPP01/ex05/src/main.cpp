/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:28:45 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:58:41 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/**
 * @brief The main function for testing the Harl class.
 *
 * This is the entry point of the program that tests the logging capabilities of the Harl class.
 * It creates a Harl object, logs messages with different log levels (DEBUG, WARNING, INFO, ERROR),
 * and attempts to log with an unsupported log level ("STRANGE").
 *
 * @return 0 on successful execution.
 */
int	main (void)
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
