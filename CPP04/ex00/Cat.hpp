/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 15:02:56 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/20 15:14:15 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(Cat const &src);
	Cat &operator = (Cat const &right);
	~Cat();
	
	void	makeSound() const;
};

#endif