/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:02:05 by cagonzal          #+#    #+#             */
/*   Updated: 2025/01/10 15:45:42 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//Canonic Functions

Intern::Intern()
{
    return;
}

Intern::Intern(const Intern & inter)
{
    *this = inter;
}

Intern::~Intern()
{
    return;
}

Intern & Intern::operator=(const Intern & inter)
{
    if (this == &inter)
        return *this;
    return *this;
}

//Funciones que lanzan las excepciones
const char* Intern::NoFormFound::what() const throw()
{
	return ("No Form Found");
}

//Funciones
AForm* Intern::makeForm(std::string type ,std::string target)
{
    AForm *creation = NULL;
    std::string array[3] = {"PresidentialPardonForm","RobotomyRequestForm","ShrubberyCreationForm" };
    AForm *function[3] = {new PresidentialPardonForm(target) , new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};

    for (int i = 0; i < 3; i++)
    {
        if (array[i] == type)
        {
            creation = function[i];
            break;
        }
    }
    for ( int i = 0; i < 3; i++)
    {
        if (creation != function[i])
            delete function[i];
    }
    if (creation == NULL)
        throw Intern::NoFormFound();
    return creation;
}