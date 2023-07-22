/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 15:09:33 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/20 15:35:56 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
	*this = src;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &right)
{
	std::cout << "WrongAnimal = Operator called" << std::endl;
	type = right.getType();
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return(this->type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "insert generic WrongAnimal sound here." << std::endl;
}
