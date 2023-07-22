/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 14:30:11 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/22 15:58:01 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include "Brain.hpp"


class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(Animal const &src);
	
	Animal &operator = (Animal const &right);

	virtual ~Animal();
	
	std::string	getType(void) const;
	
	virtual void	makeSound() const;
};

#endif