/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:41:08 by cagonzal          #+#    #+#             */
/*   Updated: 2025/11/28 19:42:14 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv)
{
	RPN *rpn = new RPN();
	
	if (argc == 2)
	{
		rpn->fillRPN(argv[1], ' ');
		try
		{
			std::cout << rpn->get_answer() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	else
		std::cout<< "Error" << std::endl;
	return 0;
}