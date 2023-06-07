/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 16:53:05 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/07 18:16:36 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "DEBUG:" << std::endl;
	std::cout << "I enjoy breathing\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO:" << std::endl;
	std::cout << "I am currently breathing. It's pretty alright.\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING:" << std::endl;
	std::cout << "Hey, is anyone else having trouble breathing?\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR:" << std::endl;
	std::cout << "Oh shit, I think Harl just went into anaphylactic shock guys.\n" << std::endl;
}

int		getlevel(std::string level)
{
	std::string	levels[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
				return(i);
	}
	return(4);
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	void		(Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	switch (getlevel(level))
	{
	case (0):
		for (int i = 0; i < 4; i++)
			(this->*funcs[i])();
		break;
	case (1):
		for (int i = 1; i < 4; i++)
			(this->*funcs[i])();
		break;
	case (2):
		for (int i = 2; i < 4; i++)
			(this->*funcs[i])();
		break;
	case (3):
		for (int i = 3; i < 4; i++)
			(this->*funcs[i])();
		break;
	default:
		std::cout << "Programs don't need to breathe right? so we can probably just ignore whatever it is saying" << std::endl;
		break;
	}
}