/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 02:25:28 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/05 03:29:17 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string		name;
	Weapon const	*weapontype;
public:
	HumanB(std::string setname);
	~HumanB();
	void	attack();
	void	setWeapon(const Weapon &weapon);
};

#endif