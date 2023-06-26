/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 15:42:53 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/26 18:06:12 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap Fred("Fred");
	ScavTrap Bob("Bob");

	Fred.attack("Bob");
	Bob.takeDamage(0);
	std::cout << std::endl << "--------Bob energy test-------" << std::endl;
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
	std::cout << std::endl << "--------Fred health Test-------" << std::endl;
	Fred.takeDamage(100);
	Fred.attack("Bob");
	std::cout << std::endl << "--------Bob guard Test-------" << std::endl;
	Bob.guardGate();
	std::cout << std::endl << "--------Bob health Test-------" << std::endl;
	Bob.attack("Bob");
	Bob.takeDamage(20);
	Bob.takeDamage(100);
	Bob.attack("Fred");
	std::cout << std::endl << "--------Destruction time-------" << std::endl;
	return (0);
}