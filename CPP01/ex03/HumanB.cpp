/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 02:25:26 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/05 03:14:28 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string setname) : name(setname)
{
	std::cout << name << " has spawned!" << std::endl;
	weapontype = NULL;
}

HumanB::~HumanB()
{
	std::cout << name << " has been destroyed (RIP)" << std::endl;
}

void	HumanB::attack()
{
	if (weapontype)
		std::cout << name << " attacks with their " << weapontype->getType() << std::endl;
	else
		std::cout << name << " has no weapon!" << std::endl;
}

void	HumanB::setWeapon(const Weapon &weapon)
{
	weapontype = &weapon;
}