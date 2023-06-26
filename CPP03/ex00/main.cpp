/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 15:42:53 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/26 17:52:05 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Fred("Fred");
	ClapTrap Bob;

	Fred.attack("Bob");
	Bob.takeDamage(0);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Fred.takeDamage(100);
	Fred.attack("Bob");
	return (0);
}