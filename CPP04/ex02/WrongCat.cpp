/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 15:10:36 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/20 15:12:49 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Constructor Called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
	*this = src;
}

WrongCat	&WrongCat::operator=(const WrongCat &right)
{
	std::cout << "WrongCat = Operator Called" << std::endl;
	this->type = right.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow." << std::endl;
}