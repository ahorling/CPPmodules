/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 17:56:08 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/26 18:21:12 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string toname);
	FragTrap(FragTrap const &src);
	~FragTrap();
	FragTrap	&operator=(FragTrap const &right);
	void	attack(std::string const &target);
	void	highFivesGuys();
};

#endif