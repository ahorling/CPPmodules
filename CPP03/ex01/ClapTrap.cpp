/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 15:06:47 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/26 15:50:29 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Claptrap Default Constructor called" << std::endl;
	name = "Default";
	hp = 10;
	ep = 10;
	ad = 0;
}

ClapTrap::ClapTrap(std::string setname)
{
	std::cout << "Claptrap Named Constructor called" << std::endl;
	name = setname;
	hp = 10;
	ep = 10;
	ad = 0;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap object destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &right)
{
	std::cout << "ClapTrap = Operator called" << std::endl;
	name = right.name;
	hp = right.hp;
	ep = right.ep;
	ad = right.ad;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	if (hp <= 0 || ep <= 0)
	{
		std::cout << "ClapTrap " << name << " is either dead (hp 0 or less), or has run out of energy (ep 0 or less)!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks "  << target << " for " << ad << " damage!" << std::endl;
	this->ep--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " has been hit for " << amount << " damage. oof" << std::endl;
	this->hp = this->hp - amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hp <= 0 || ep <= 0)
	{
		std::cout << "ClapTrap " << name << " is either dead (hp 0 or less), or has run out of energy (ep 0 or less)!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " repairs itself to heal " << amount << " hp!" << std::endl;
	this->hp = this->hp + amount;
	this->ep--;
}