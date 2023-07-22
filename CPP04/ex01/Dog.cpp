/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 14:52:15 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/22 16:10:00 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Constructor Called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal()
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	*this = src;
}

Dog	&Dog::operator=(const Dog &right)
{
	std::cout << "Dog = Operator Called" << std::endl;
	this->type = right.getType();
	this->brain = new Brain(*right.getBrain());
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof." << std::endl;
}

Brain	*Dog::getBrain() const
{
	return(this->brain);
}