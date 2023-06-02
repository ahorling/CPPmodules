/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 19:50:12 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/02 21:04:57 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

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