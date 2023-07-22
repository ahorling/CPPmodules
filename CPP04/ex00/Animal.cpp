/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 14:31:48 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/20 15:36:42 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal Copy Constructor Called" << std::endl;
	*this = src;
}

Animal	&Animal::operator=(Animal const &right)
{
	std::cout << "Animal = Operator called" << std::endl;
	type = right.getType();
	return (*this);
}

std::string	Animal::getType(void) const
{
	return(this->type);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "insert generic animal sound here." << std::endl;
}
