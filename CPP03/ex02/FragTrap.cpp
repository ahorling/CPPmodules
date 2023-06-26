/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 17:59:01 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/26 18:22:19 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	name = "Default";
	hp = 100;
	ep = 100;
	ad = 30;
}

FragTrap::FragTrap(std::string setname) : ClapTrap(setname)
{
	std::cout << "Named FragTrap Constructor called" << std::endl;
	hp = 100;
	ep = 100;
	ad = 30;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap object destroyed" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &right)
{
	std::cout << "FragTrap = Operator called" << std::endl;
	name = right.name;
	hp = right.hp;
	ep = right.ep;
	ad = right.ad;
	return (*this);
}

void	FragTrap::attack(std::string const &target)
{
	if (hp <= 0 || ep <= 0)
	{
		std::cout << "FragTrap " << name << " is either dead (hp 0 or less), or has run out of energy (ep 0 or less)!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " attacks "  << target << " for " << ad << " damage!" << std::endl;
	this->ep--;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " attempts to give everyone a high five, but is left hanging." << std::endl;
}