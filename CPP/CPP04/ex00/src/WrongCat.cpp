/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:35:02 by cagonzal          #+#    #+#             */
/*   Updated: 2023/01/18 14:42:16 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	return;
}

WrongCat::WrongCat(const WrongCat & w_cat )
{
	*this = w_cat;
	return;
}

WrongCat::~WrongCat()
{
	return;
}

WrongCat& WrongCat::operator=(WrongCat const & w_cat )
{
	if (&w_cat == this)
		return *this;
	this->type = w_cat.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow meowed the wrongcat"<< std::endl;
}
