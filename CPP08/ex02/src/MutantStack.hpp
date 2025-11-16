/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:51:28 by cagonzal          #+#    #+#             */
/*   Updated: 2025/11/16 13:17:12 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator r_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_riterator;
	
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
	~MutantStack() {}
	MutantStack &operator=(const MutantStack &other);

	iterator begin(void) { return this->c.begin(); }
	iterator end(void) { return this->c.end(); }

	const_iterator begin(void) const { return this->c.begin(); }
	const_iterator end(void) const { return this->c.end(); }

	r_iterator rbegin(void) { return this->c.rbegin(); }
	r_iterator rend(void) { return this->c.rend(); }

	const_riterator rbegin(void) const { return this->c.rbegin(); }
	const_riterator rend(void) const { return this->c.rend(); }
};

#include "MutantStack.ipp"

#endif