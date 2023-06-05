/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 01:35:28 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/05 03:29:50 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

static void	BobOnly(void)
{
	std::cout << "BOB DEMONSTRATES HIS SKILLS:\n\n"; 

	Weapon club("spiky club");
	HumanA bob("Bob", club);

	bob.attack();
	club.setType("Mace");
	bob.attack();
}

static void	JimOnly(void)
{
	std::cout << "JIM DEMONSTRATES HIS SKILLS:\n\n";
	
	Weapon	club("spiky club");
	HumanB	jim("Jim");

	jim.setWeapon(club);
	jim.attack();
	club.setType("mace");
	jim.attack();
}

static void JimNoWeapon(void)
{
	std::cout << "JIM FUCKS IT ALL UP:\n\n";
	
	// Weapon	club = Weapon("spiky club");
	HumanB	jim("Jim");

	// jim.setWeapon(club);
	jim.attack();
}

int main()
{
	BobOnly();
	std::cout << std::endl;
	JimOnly();
	std::cout << std::endl;
	JimNoWeapon();
}