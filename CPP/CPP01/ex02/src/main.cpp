/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:52:44 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 13:02:27 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		str;
	std::string		&strREF = str;
	std::string*	strPTR = &str;

	str = "HI THIS IS BRAIN";
	std::cout<<"FRASES"<<std::endl;
	std::cout<<"El valor original               ->"<<str<<std::endl;
	std::cout<<"El valor al que hace referencia ->"<<strREF<<std::endl;
	std::cout<<"El valor dentro del puntero     ->"<<*strPTR<<std::endl;

	std::cout<<"PUNTEROS"<<std::endl;
	std::cout<<"La direccion del valor original ->"<<&str<<std::endl;
	std::cout<<"La direccion a la referencia    ->"<<&strREF<<std::endl;
	std::cout<<"El valor del puntero            ->"<<strPTR<<std::endl;

	return(0);
}
