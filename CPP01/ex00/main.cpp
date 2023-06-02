/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 19:52:42 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/02 21:06:12 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie("Greg");
	Zombie	*zoomber;

	zombie.announce();
	zoomber = newZombie("Bobby");
	zoomber->announce();
	randomChump("Gregoy");
	delete zoomber;
	return (0);
}