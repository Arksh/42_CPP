/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:20:43 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/30 12:36:12 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0)); // Seed for random number generation

    for (int i = 0; i < 10; ++i)
    {
        Base* obj = Base::generate();
        std::cout << "Identifying using pointer: ";
        Base::identify(obj);
        std::cout << "Identifying using reference: ";
        Base::identify(*obj);
        delete obj;
    }

    return 0;
}