/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contacts.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 20:06:44 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/02 18:23:38 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "contacts.hpp"

Contacts::Contacts()
{
}

Contacts::~Contacts()
{
}

void	preview(std::string str)
{
	int i;

	i = 0;
	if (str.length() > 10)
	{
		while (i < 9)
		{
			std::cout << std::right << str[i];
			i++;
		}
		std::cout << std::right << ".";
		return;
	}
	else
	{
		std::cout << std::right << std::setw(10) << str;
	}
}

void	Contacts::print_list(void)
{
	preview(first);
	std::cout << " | ";
	preview(last);
	std::cout << " | ";
	preview(nick);
	std::cout << " | ";
	preview(number);
	std::cout << std::endl;
}

void	Contacts::print_contact(void)
{
	if (index == 9)
		return;
	if (!filled)
		std::cout << "SORRY, THAT CONTACT HAS NOT YET BEEN ADDED TO MY LOGS.\n" << std::endl;
	else
	{
		std::cout << "FIRST NAME: " << first << std::endl;
		std::cout << "LAST NAME: " << last << std::endl;
		std::cout << "NICKNAME: " << nick << std::endl;
		std::cout << "NUMBER NAME: " << number << std::endl;
		std::cout << "DARKEST SECRET: " << secret << std::endl;
	}
	return;
}

std::string	recieve_info(std::string type)
{
	std::string input;

	std::cout << type << std::endl;
	std::getline(std::cin, input);
	return(input);
}

void	Contacts::set_contact(int n)
{
	first = recieve_info("PLEASE INPUT THEIR FIRST NAME");
	last = recieve_info("PLEASE INPUT THEIR LAST NAME");
	nick = recieve_info("PLEASE INPUT THEIR NICKNAME");
	number = recieve_info("PLEASE INPUT THEIR NUMBER");
	secret = recieve_info("PLEASE INPUT YOUR BLACKMAIL MATERIAL");
	filled = true;
	index = n;
}