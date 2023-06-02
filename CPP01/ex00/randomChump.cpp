/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 20:06:47 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/02 20:11:43 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zombie(name);

	zombie.announce();
}