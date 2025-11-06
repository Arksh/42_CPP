/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:17:12 by cagonzal          #+#    #+#             */
/*   Updated: 2025/11/06 10:56:33 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base* Base::generate()
{
    int randNum = rand() % 3;
    switch (randNum)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default: return 0;
    }
}


/**
 * @brief Identify and print the concrete derived type of the object pointed to by p.
 *
 * Attempts to determine whether the object pointed to by p is an instance of A, B, or C
 * by performing pointer dynamic_casts in that order. On the first successful cast, the
 * function writes the corresponding type name ("A", "B" or "C") followed by a newline to
 * std::cout.
 *
 * @param p Pointer to a Base object to identify. May be a pointer to A, B, C, or another type.
 *
 * @throws Base::CastException if p is nullptr or does not refer to an instance of A, B or C.
 *
 * @note This function has the side effect of writing to std::cout.
 * @note Requires RTTI (dynamic_cast) to be enabled.
 */
void Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        throw Base::CastException();
}

/**
 * Identify the dynamic type of the object referred to by p and print a one-letter
 * representation to standard output.
 *
 * This function attempts to determine whether the actual (dynamic) type of p is
 * A, B, or C by performing dynamic_casts on the address of the reference. On the
 * first successful cast it prints the corresponding letter ("A", "B" or "C")
 * followed by a newline to std::cout.
 *
 * @param p Reference to a Base object whose dynamic type should be identified.
 *
 * @throws Base::CastException if the object's dynamic type is none of A, B or C.
 *
 * @note This implementation requires RTTI to be enabled. It has no return value
 * and has the side effect of writing to std::cout; callers that require
 * thread-safety or different output handling should adapt accordingly.
 */
void Base::identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        throw Base::CastException();
}


Base::~Base()
{
    return;
}