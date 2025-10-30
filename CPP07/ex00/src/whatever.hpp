/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:53:44 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/30 13:01:32 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iomanip>
#include<iostream>

template<typename T>
static T min(T n1, T n2)
{
	if ( n1 < n2)
		return n1;
	return n2;
}

template<typename T>
static T max(T n1, T n2)
{
	if ( n1 > n2)
		return n1;
	return n2;
}

template<typename T>
void swap(T &n1, T &n2)
{
	T aux = n1;
	n1 = n2;
	n2 = aux;
}