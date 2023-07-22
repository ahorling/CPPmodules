/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 16:05:53 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/22 16:35:27 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain	&Brain::operator=(Brain const &right)
{
	for (int i = 0; i < 100; i++)
		setIdea(i, right.getIdea(i));
	return(*this);
}

std::string Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}

void	Brain::setIdea(int i, std::string idea)
{
	this->ideas[i] = idea;
}


std::string	Brain::showIdeas(void) const
{
	std::string	idea;

	for (int i = 0; i < 100; i++)
	{
		if (this->ideas[i] != "")
		{
			idea += this->ideas[i];
			idea += "\n";
		}
	}
	return (idea);
}