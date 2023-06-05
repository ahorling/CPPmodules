/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 00:25:00 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/05 00:58:06 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR;
	std::string &stringREF = string;
	stringPTR = &string;

	std::cout << std::endl;
	std::cout << "ADRESSES:" << std::endl;
	std::cout << "string: " << &string << std::endl;
	std::cout << "pointer: " << stringPTR << std::endl;
	std::cout << "reference: " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "CONTENTS:" << std::endl;
	std::cout << "string: " << string << std::endl;
	std::cout << "pointer: " << *stringPTR << std::endl;
	std::cout << "reference: " << stringREF << std::endl;
}