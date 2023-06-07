/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:16:02 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/07 18:11:11 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main()
{
	Harl harl;

	std::cout << "----------TEST 1 (DEBUG)----------" << std::endl;
	harl.complain("debug");

	std::cout << "----------TEST 2 (INFO)----------" << std::endl;
	harl.complain("info");

	std::cout << "----------TEST 3 (WARNING)----------" << std::endl;
	harl.complain("warning");

	std::cout << "----------TEST 4 (ERROR)----------" << std::endl;
	harl.complain ("error");

	std::cout << "----------TEST 5 (DEBUG + ERROR)----------" << std::endl;
	harl.complain ("debug");
	harl.complain ("error");

	std::cout << "----------TEST 6 (ALL)----------" << std::endl;
	harl.complain ("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain ("error");
	
	return(0);
}