/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:06:23 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/30 11:26:49 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iomanip>
# include <iostream>
# include <stdint.h>

class Data
{
	public:
		Data(std::string name);
		~Data();

	private:
		std::string _name;
};

	uintptr_t serialize(Data *ptr);
	Data *deserialize(uintptr_t raw);

#endif