/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 15:14:42 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/20 15:51:21 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "\n########## CONSTRUTOR MESSAGES ##########\n" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "\n########## TYPE CONFIRMATION ##########\n" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\n########## MAKE SOME NOISE ##########\n" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n########## NOW FUCK IT UP ##########" << std::endl;
	std::cout << wrong->getType() << " will speak" << std::endl;
	wrong->makeSound();
	std::cout << wrongCat->getType() << " will speak" << std::endl;
	wrongCat->makeSound();

	std::cout << "\n########## NOW SEND THE ANIMALS TO THE GLUE FACTORY ##########\n" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongCat;
}