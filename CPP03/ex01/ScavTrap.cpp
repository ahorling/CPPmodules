/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 17:32:31 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/26 17:51:09 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	name = "Default";
	hp = 100;
	ep = 50;
	ad = 20;
}

ScavTrap::ScavTrap(std::string setname) : ClapTrap(setname)
{
	std::cout << "Named ScavTrap Constructor called" << std::endl;
	hp = 100;
	ep = 50;
	ad = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap object destroyed" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &right)
{
	std::cout << "ScavTrap = Operator called" << std::endl;
	name = right.name;
	hp = right.hp;
	ep = right.ep;
	ad = right.ad;
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	if (hp <= 0 || ep <= 0)
	{
		std::cout << "ScavTrap " << name << " is either dead (hp 0 or less), or has run out of energy (ep 0 or less)!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks "  << target << " for " << ad << " damage!" << std::endl;
	this->ep--;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now guarding a gate. What gate? Who knows!" << std::endl;
}