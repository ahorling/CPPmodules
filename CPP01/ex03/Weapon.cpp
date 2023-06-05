/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 01:08:09 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/05 02:46:50 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string settype)
{
	type = settype;
	std::cout << "A " << type << " has been created" << std::endl;
}

Weapon::Weapon()
{
	std::cout << type << " Has been created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "The " << type << " has been destroyed" << std::endl;
}

const std::string& Weapon::getType() const
{
	return(type);
}

void Weapon::setType(std::string newtype)
{
	type = newtype;
}