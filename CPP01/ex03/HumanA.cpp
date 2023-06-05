/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 01:15:31 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/05 02:31:24 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string setname, const Weapon &weapontype) :  name(setname), weapon(weapontype)
{
	std::cout << name << " has spawned!" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << name << " has been destroyed (RIP)" << std::endl;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}