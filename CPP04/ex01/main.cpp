/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 15:14:42 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/22 16:44:58 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Lists.hpp"


void	leaks()
{
	system("leaks -q Brain");
}

int	main()
{
	atexit(leaks);

	std::cout << "\n########## PROVING MY ANIMALS' BRAINS DONT LEAK ##########\n" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
	
	std::cout << "\n########## CREATE HERD OF ANIMALS ##########\n" << std::endl;
	int	numAnimals = 4;
	Animal *animals[numAnimals];

	for (int i = 1; i <= numAnimals; i++)
	{
		if (numAnimals % i == 0)
			animals[i - 1] = new Dog();
		else
			animals[i - 1] = new Cat();
		std::cout << "Animal number " << i << " is a " << animals[i - 1]->getType() << " " << std::endl;
	}
	for (int i = 0; i <= numAnimals; i++)
		delete animals[i];

	std::cout << "\n########## NOW FILL THEIR HEADS WITH IDEAS ##########\n" << std::endl;
	Cat	*magicCat = new Cat();
	Cat *hungryCat = new Cat();
	for (int i = 0; i < 100; i++)
	{
		magicCat->getBrain()->setIdea(i, wildMagicList[i]);
	}
	for (int i = 0; i < 100; i++)
	{
		hungryCat->getBrain()->setIdea(i, foodList[i]);
	}

	std::cout << "\n########## WHAT ARE THEY THINKING ABOUT? ##########\n" << std::endl;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int randomIdea = std::rand() % 100;

	std::cout << magicCat->getBrain()->getIdea(randomIdea) << std::endl;
	std::cout << hungryCat->getBrain()->getIdea(randomIdea) << std::endl;


	std::cout << "\n########## NOW SEND BOTH CATS TO THE FARM ##########\n" << std::endl;
	delete magicCat;
	delete hungryCat;
	return(0);
}