/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:09 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/14 12:26:10 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//clang++ megaphone.cpp

#include <iostream>

void	speak(char **argv, int word)
{
	int i;
	int j;

	i = 1;
	while (i < word)
	{
		j = 0;
		while (argv[i][j] != '\0')
			std::cout<<char(toupper(argv[i][j++]));
		if (i < word)
			std::cout<<" ";
		i++;
	}
	std::cout<<std::endl;
}

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
		speak(argv, argc);
	return 0;
}
