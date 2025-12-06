/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:18:05 by cagonzal          #+#    #+#             */
/*   Updated: 2025/12/03 11:35:57 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <limits>
#include <cstdlib>
#include <string>

std::string intToString(int value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

RPN& RPN::operator=	( const RPN &tmp)
{ 
	if (this != &tmp)
		this->list = tmp.list;
	return (*this); 
}

std::ostream &operator<<(std::ostream& os, const RPN &tmp) 
{
    std::list <std::string> l = tmp.getlist();
    os << std::endl << "RPN list" << std::endl;
    for (iterator it = l.begin(); it != l.end(); ++it)
        os << *it << " ";
    return (os);
}

void RPN::fillRPN	( std::string str , char c)
{
    std::stringstream 			test(str);
    std::string 				segment;

    while (std::getline(test,segment,c))
        this->list.push_back(segment);
}

bool RPN::isOperator(std::string str)
{
    char aux[4] = {'+','-','*','/'};
    if (str.length() > 1)
        return false;
    for (int x = 0; x < 4 ; x++)
    {
        if (str[0] == aux[x])
            return true;
    }
    return false;
}

bool RPN::isIntNumber(std::string str)
{
    char 		*e;
    double		x;
    
    x = std::strtod(str.c_str(),&e);
    if (*e != '\0')
        return false;
    if (x < std::numeric_limits<int>::min() || x > std::numeric_limits<int>::max())
        return false;
    if (std::fmod(x, 1.0) != 0) // is not an integer
        return false;
    if (x > 10) // || x < 0)
        return false;
    return true;
}

bool RPN::check_input (void)
{
    for (iterator it = this->list.begin(); it != this->list.end(); ++it)
    {
        if (!(isIntNumber(*it) || isOperator(*it)))
            return false;
    }
    return true;
}

void show_operation(std::list <std::string> aux)
{
    for (iterator it = aux.begin(); it != aux.end(); ++it)
        std::cout << *it << " " ;
}

int getIntNumber(std::string str)
{
    return (std::atoi(str.c_str()));
}

int getOperator(std::string str)
{
    char aux[4] = {'+','-','*','/'};
    for (int x = 0; x < 4 ; x++)
        if (str[0] == aux[x])
            return x;
    return -1;
}

std::string		RPN::get_answer		(void)
{
    int x;
    int y;
    std::list <std::string> aux;
    iterator it_aux;

    if (!this->check_input())
        throw RPN::ErrorRPN();
    
    for (iterator it = this->list.begin(); it != this->list.end(); ++it)
    {
        if (isIntNumber(*it))
            aux.push_back(*it);
        else
        {
            if (aux.size() <= 1)
                throw RPN::ErrorRPN();
            
            it_aux = aux.end();
            it_aux--;
            y = getIntNumber(*it_aux);
            aux.pop_back();
            it_aux = aux.end();
            it_aux--;
            x = getIntNumber(*it_aux);
            aux.pop_back();
            
            switch (getOperator(*it))
            {
                case 0:
                    aux.push_back(intToString(x + y));  // Replace std::to_string with custom function
                    break;
                case 1:
                    aux.push_back(intToString(x - y));  // Replace std::to_string with custom function
                    break;
                case 2:
                    aux.push_back(intToString(x * y));  // Replace std::to_string with custom function
                    break;
                case 3:
                    if (y == 0)
                        throw RPN::ErrorRPN();
                    aux.push_back(intToString(x / y));  // Replace std::to_string with custom function
                    break;
                default:
                    throw RPN::ErrorRPN();
                break;
            }
        }
    }
    
    if (aux.size() > 1)
        throw RPN::ErrorRPN();
    
    return aux.front();
}