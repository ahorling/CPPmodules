/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 21:25:06 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/02 21:30:39 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde;
	int	hordesize;

	hordesize = 5;
	horde = zombieHorde(hordesize, "James");
	for (int i = 0; i < hordesize; i++)
		horde[i].announce();
	delete[] horde;
	return(0);
}