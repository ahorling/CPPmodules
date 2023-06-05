/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 01:01:26 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/05 02:23:25 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(std::string settype);
	Weapon();
	~Weapon();
	const std::string&	getType() const;
	void				setType(std::string newtype);
};

#endif