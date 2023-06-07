/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 16:53:05 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/07 17:55:10 by ahorling      ########   odam.nl         */
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
	std::cout << "I enjoy breathing" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO:" << std::endl;
	std::cout << "I am currently breathing. It's pretty alright." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING:" << std::endl;
	std::cout << "Hey, is anyone else having trouble breathing?" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR:" << std::endl;
	std::cout << "Oh shit, I think Harl just went into anaphylactic shock guys." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	void		(Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			{
				(this->*funcs[i])();
				std::cout << std::endl;
				return;
			}
	}
	std::cout << "what are you asking me? I'm a machine, I don't need to breathe." << std::endl;
}