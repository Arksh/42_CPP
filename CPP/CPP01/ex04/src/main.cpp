/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:12:14 by cagonzal          #+#    #+#             */
/*   Updated: 2022/12/19 16:04:11 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

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

int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
		read_file(argv[1], argv[2], argv[3]);
	else
		std::cout << "Not correct arguments" << std::endl;
}
