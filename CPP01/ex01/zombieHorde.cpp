/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 21:11:39 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/02 21:25:00 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	std::string	zomname;
	Zombie *horde;

	horde = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		zomname = name + std::to_string(i);
		horde[i].setname(zomname);
	}
	return (horde);
}