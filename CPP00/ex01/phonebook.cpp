/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 20:06:38 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/02 18:52:30 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "phonebook.hpp"
#include "contacts.hpp"

PhoneBook::PhoneBook()
{
	int	i = 0;
	contact_num = 0;
	while (i < 8)
	{
		contact[i].filled = false;
		i++;
	}
}

PhoneBook::~PhoneBook()
{
}

int	check_contacts(int contactnum)
{
	if (contactnum > 7)
		return(0);
	else
		return(contactnum);
}

void	PhoneBook::set_contact(void)
{
	contact_num = check_contacts(contact_num);
	contact[contact_num].set_contact(contact_num);
	contact_num++;
	std::cout << "CONTACT ADDED!\n" << std::endl;
}

void	PhoneBook::search_contact()
{
	int			i;
	size_t		recieved;
	std::string	num;

	i = 0;
	std::cout << "THE CURRENT AVAILABLE CONTACTS ARE:" << std::endl;
	while (contact[i].filled == true && contact[i].index <= 8)
	{
		contact[i].print_list();
		i++;
	}
	std::cout << std::endl << "WHICH CONTACT WOULD YOU LIKE TO DISPLAY?" << std::endl;
	std::getline(std::cin, num);
	try
	{
		recieved = std::stoll(num);
	}
	catch(...)
	{
		std::cerr << "EXCEPTION OCCURED. PLEASE USE A REASONABLE NUMBER (CHARACTERS ARE NOT REASONABLE!) >:(" << std::endl;
		exit(1);
	}
	if (recieved > 8 || recieved < 1)
	{
		std::cout << "I'M SORRY, BUT THAT NUMBER LIES OUTSIDE OF MY ALLOTED POSSIBLE MEMORY.\n" << std::endl;
		return;
	}
	contact[stoi(num) - 1].print_contact();
	return;
}