/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 17:26:50 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/26 17:47:56 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string toname);
	ScavTrap(ScavTrap const &src);
	~ScavTrap();
	ScavTrap	&operator=(ScavTrap const &right);
	void	attack(std::string const &target);
	void	guardGate();
};

#endif