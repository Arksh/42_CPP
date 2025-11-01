/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:16:55 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/31 18:03:30 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND
# define EASYFIND

# include <iomanip>
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

struct ElementNotFoundException : public std::exception
{
	const char* what() const throw ()
	{
		return "Element not found";
	}
};

template <typename T>
int easyfind(T &container, int toFind)
{
	typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw ElementNotFoundException();
	return *it;
}

#endif