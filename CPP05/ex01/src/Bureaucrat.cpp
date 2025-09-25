/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:00:49 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:12:07 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Funciones canonicas
Bureaucrat::Bureaucrat(std::string str, int i) : name(str)
{
	if (i > 150)
		throw Bureaucrat::GradeTooLowException();
	if (i < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = i;
	std::cout << this->name << " was created with a grade of "<< i<<std::endl;
	return;
}

Bureaucrat::~Bureaucrat()
{
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat & bureu)
{
	*this = bureu;
}

Bureaucrat Bureaucrat::operator=(const Bureaucrat & bureu)
{
	this->grade = bureu.grade;
	return (*this);
}

//Funciones que lanzan las excepciones
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ( "Grade is to high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ( "Grade is to low");
}

//Getters
std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

//Funcion para incrementar el rango
void Bureaucrat::increaseGrade(void)
{
	if (getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decreaseGrade(void)
{
	if (getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

//Funcion para el output
std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureu)
{
	os << bureu.getName()<< " - who's grade is now "<< bureu.getGrade();
	return (os);
}

//Funcion para firmar un formulario
void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout<< this->getName() << " signs "<< form.getName()<<std::endl;
	}
	catch (std::exception & e)
	{
		std::cout<< this->getName() << " cannot sign "<< form.getName()<< " because "<< e.what()<<std::endl;
	}
}