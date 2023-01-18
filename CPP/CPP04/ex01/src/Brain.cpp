/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/02 16:41:42 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"Brain created"<<std::endl;
	for (int i = 0;i < 100 ; i++)
		this->ideas[i] = "";
	return;
}

Brain::~Brain()
{
	std::cout<<"Brain destroyed"<<std::endl;
	return;
}

Brain::Brain(const Brain &brain)
{
	*this = brain;
}

Brain& Brain::operator=(Brain const & brain)
{
	std::cout<<"Brain copied"<<std::endl;
	if (&brain == this)
		return *this;
	int i;

	i = 0;
	while (i < 100)
	{
		this->ideas[i] = brain.ideas[i];
		i++;
	}
	return (*this);
}

std::string Brain::getIdea(int index)
{
	return(this->ideas[index]);
}
