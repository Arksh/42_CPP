/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:01:19 by cagonzal          #+#    #+#             */
/*   Updated: 2025/01/10 13:02:19 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
    private:
        class NoFormFound : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
    public:
        Intern();
        ~Intern();
        Intern(const Intern & intern);
        Intern & operator=(const Intern & inter);
        AForm* makeForm(std::string type ,std::string target);
};



#endif