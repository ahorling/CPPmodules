/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 03:37:00 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/05 03:48:50 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>

int	main(int argc, char **argv)
{
	std::string replaced;
	
	if (argc != 4)
		std::cout << "Invalid inputs, please enter only a file name and 2 strings." << std::endl;
	std::vector<std::string> all_args;
	
	if (argc > 1)
		all_args.assign(argv + 1, argv + argc);
}