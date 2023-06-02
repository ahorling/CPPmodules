/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 21:10:51 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/02 21:23:34 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string zombiename)
{
	name = zombiename;
}

Zombie::~Zombie()
{
	std::cout << name << " was destroyed (RIP)" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setname(std::string zomname)
{
	name = zomname;
}