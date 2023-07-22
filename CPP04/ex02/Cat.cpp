/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 15:02:19 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/22 16:42:18 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor Called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal()
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	*this = src;
}

Cat	&Cat::operator=(const Cat &right)
{
	std::cout << "Cat = Operator Called" << std::endl;
	this->type = right.getType();
	this->brain = new Brain(*right.getBrain());
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow." << std::endl;
}

Brain *Cat::getBrain() const
{
	return(this->brain);
}