/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 15:42:53 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/26 18:23:09 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	std::cout << std::endl << "--------Constructing-------" << std::endl;
	ClapTrap Fred("Fred");
	ScavTrap Bob("Bob");
	FragTrap Greg("Greg");

	std::cout << std::endl << "--------Fred attack-------" << std::endl;
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
	std::cout << std::endl << "--------Greg Tests-------" << std::endl;
	Greg.highFivesGuys();
	Greg.attack("Bob");
	Greg.beRepaired(10);
	std::cout << std::endl << "--------Destruction time-------" << std::endl;
	return (0);
}