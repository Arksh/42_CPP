/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:04:58 by cagonzal          #+#    #+#             */
/*   Updated: 2025/11/16 13:08:31 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(MutantStack & mut)
{
	this = &mut;
	return;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &spn)
{
	if (this != &spn)
		this->c = spn.c;
	return *this;
}