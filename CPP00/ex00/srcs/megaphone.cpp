/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:09 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:10:48 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//clang++ megaphone.cpp

#include <iostream>

/**
 * @brief Speak function to capitalize and print words from command-line arguments.
 *
 *	This function takes an array of C-style strings (argv) and the number of words (word)
 *	as input. It capitalizes each character in each word and prints the resulting words
 *	to the standard output, separated by spaces. After processing all words, it adds a
 *	newline character.
 *
 * @param argv An array of C-style strings containing the words to be capitalized and printed.
 * @param word The number of words in the argv array.
 */
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
