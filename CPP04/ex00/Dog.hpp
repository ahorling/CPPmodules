/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 14:49:48 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/20 15:14:23 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(Dog const &src);
	Dog &operator = (Dog const &right);
	~Dog();
	
	void	makeSound() const;
};

#endif