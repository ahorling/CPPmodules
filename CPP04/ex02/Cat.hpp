/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 15:02:56 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/22 16:34:07 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain	*brain;
	
public:
	Cat();
	Cat(Cat const &src);
	
	~Cat();

	Cat &operator = (Cat const &right);
	
	void	makeSound() const;
	Brain	*getBrain() const;
};

#endif