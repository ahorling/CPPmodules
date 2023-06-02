/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 20:06:48 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/02 18:27:38 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phonebook.hpp"


void	print_intro(void)
{
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << ":::::::::::::::::WELCOME TO YOUR PHONEBOOK::::::::::::::::::" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "WHAT WOULD YOU LIKE TO DO?" << std::endl << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "SEARCH" << std::endl;
	std::cout << "EXIT" << std::endl << std::endl;
}

int	main(void)
{
	PhoneBook	book;
	std::string input;

	while (true)
	{
		print_intro();
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			book.set_contact();
		}
		else if (input == "SEARCH")
		{
			book.search_contact();
			continue;
		}
		else if (input == "EXIT")
		{
			std::cout << "PURGING DATABASE. GOODBYE!" << std::endl;
			break;
		}
		else
		{
			std::cout << std::endl << "Invalid command, please use either ADD, SEARCH or EXIT\n" << std::endl;
		}
		if (std::cin.eof())
			break;
	}
	return (0);
}