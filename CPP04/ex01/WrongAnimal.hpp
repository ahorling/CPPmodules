/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 15:07:52 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/20 15:25:18 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &src);
	WrongAnimal &operator = (WrongAnimal const &right);
	~WrongAnimal();
	
	std::string	getType(void) const;
	
	void	makeSound() const;
};

#endif