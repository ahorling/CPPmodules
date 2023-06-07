/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 03:37:00 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/07 16:48:21 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <map>
void	replace_string(const std::string file, const std::string tofind, const std::string toreplace)
{
	std::ifstream	in(file);
	std::ofstream	out(file + ".replace");
	std::string		line;
	size_t			i;
	size_t			len;
	size_t			pos;
	std::string		outline;

	i = 0;
	if (!in)
	{
		std::cout << "Error opening provided file" << std::endl;
		exit(1);
	}
	if (!out)
	{
		std::cout << "Error creating .replace file" << std::endl;
		exit(1);
	}
	while (std::getline(in, line))
	{
		len = line.length();
		while (i < len)
		{
			pos = line.find(tofind, i);
			if (pos == std::string::npos)
			{
				outline += line.substr(i);
				break;
			}
			outline += line.substr(i, pos - i);
			outline += toreplace;
			i = pos + tofind.length();
		}
		out << outline << std::endl;
		i = 0;
		outline.clear();
	}
	in.close();
	out.close();
}

int	main(int argc, char **argv)
{
	std::string replaced;
	
	if (argc != 4)
		std::cout << "Invalid inputs, please enter only a file name and 2 strings." << std::endl;
	std::string file = argv[1];
	std::string find = argv[2];
	std::string replace = argv[3];
	replace_string(file, find, replace);
}