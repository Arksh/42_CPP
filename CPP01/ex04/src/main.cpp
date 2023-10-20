/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:12:14 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:50:39 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Replace occurrences of a substring in a string with another substring.
 *
 * This function replaces all occurrences of the substring `s1` in the string `line`
 * with the substring `s2` and returns the resulting string.
 *
 * @param line The input string to search and replace in.
 * @param s1 The substring to find and replace.
 * @param s2 The substring to replace `s1` with.
 * @return The modified string after replacement.
 */
std::string	replacestr(std::string line, std::string s1, std::string s2)
{
	std::size_t	found;
	std::string	finalstr;

	found = line.find(s1);
	finalstr = "";
	while (found != std::string::npos)
	{
		finalstr.insert(finalstr.length(), line.substr(0, found) + s2);
		line.erase(0, found + s1.length());
		found = line.find(s1);
	}
	return (finalstr + line);
}

/**
 * @brief Read a file, replace substrings, and write the modified content to a new file.
 *
 * This function reads a file specified by `dir`, replaces all occurrences of the substring `s1`
 * with the substring `s2`, and writes the modified content to a new file with a ".replace" extension.
 *
 * @param dir The path to the input file.
 * @param s1 The substring to find and replace.
 * @param s2 The substring to replace `s1` with.
 */
void	read_file(std::string dir, std::string s1, std::string s2)
{
	std::string	line;
	std::string	final_str = "";
	std::ifstream oldfile(dir);

	if(oldfile.is_open())
	{
		std::ofstream newfile(dir + ".replace");

		while ( getline (oldfile,line) )
			final_str += replacestr(line, s1, s2) +"\n";
		final_str.pop_back();
		newfile << final_str;
		newfile.close();
		oldfile.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
}

/**
 * @brief Check the command-line arguments for correctness.
 *
 * This function checks whether the command-line arguments are valid for the program's execution.
 * It verifies that there are exactly four arguments, and that the second and third arguments are not empty
 * and not equal to each other.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return 0 if the arguments are valid, 1 if they are not.
 */
int	check_args(int argc, char **argv)
{
	int i = 0;
	std::string s1, s2;

	if (argc != 4)
		return(1);
	while (i < argc)
		if (argv[i++][0] == '\0')
			return (1);
	s1 = argv[2];
	s2 = argv[3];
	if (s1 == s2)
		return (1);
	return(0);
}

/**
 * @brief The main function for the string replacement program.
 *
 * This is the entry point of the program that reads a file, performs string replacement, and writes
 * the modified content to a new file. It checks command-line arguments for correctness before execution.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return 0 on successful execution, 1 if the arguments are incorrect.
 */
int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
		read_file(argv[1], argv[2], argv[3]);
	else
		std::cout << "Not correct arguments" << std::endl;
}
