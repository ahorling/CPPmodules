/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 01:25:48 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/05 02:18:04 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string 	name;
	const Weapon	&weapon;
public:
	HumanA(std::string setname, const Weapon &weapontype);
	~HumanA();
	void	attack();
};

#endif