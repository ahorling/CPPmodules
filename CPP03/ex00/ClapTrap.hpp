/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 15:08:52 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/26 17:46:59 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
private:
	std::string	name;
	int	hp;
	int ep;
	int	ad;
public:
	ClapTrap();
	ClapTrap(std::string setname);
	ClapTrap(ClapTrap const &src);
	~ClapTrap();
	ClapTrap &operator = (ClapTrap const &right);
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif