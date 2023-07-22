/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 14:49:48 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/22 16:34:14 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain	*brain;

public:
	Dog();
	Dog(Dog const &src);
	
	~Dog();
	
	Dog &operator = (Dog const &right);
	
	void	makeSound() const;
	Brain	*getBrain() const;
};

#endif