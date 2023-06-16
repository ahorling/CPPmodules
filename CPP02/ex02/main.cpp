/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 16:07:29 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/16 20:26:10 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "--------------SUBJECT (Increments/decrements) EXAMPLE--------------\n\n";
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	a = 1.1f;
	Fixed c;
	c = 1.1f;
	std::cout << "\n\n--------------ADDITION EXAMPLE--------------\n\n";
	std::cout << "value of a before: " << a << "\nvalue of a after: " << a + 10 << std::endl;

	std::cout << "\n\n--------------SUBTRACTION EXAMPLE--------------\n\n";
	std::cout << "value of a before: " << a << "\nvalue of a after: " << a - 10 << std::endl;

	std::cout << "\n\n--------------MULTIPLICATION EXAMPLE--------------\n\n";
	std::cout << "value of a before: " << a << "\nvalue of a after: " << a * 10 << std::endl;

	std::cout << "\n\n--------------DIVISION EXAMPLE--------------\n\n";
	std::cout << "value of a before: " << a << "\nvalue of a after: " << a / 2 << std::endl;

	std::cout << "\n\n--------------MIN EXAMPLE--------------\n\n";
	std::cout << "a is : " << a << ", b is " << b << ", therefore the smaller number is: " << Fixed::min(a, b) << std::endl;

	std::cout << "\n\n--------------MAX EXAMPLE--------------\n\n";
	std::cout << "a is : " << a << ", b is " << b << ", therefore the bigger number is: " << Fixed::min(a, b) << std::endl;

	std::cout << "\n\n--------------COMPARISON EXAMPLES (O is false, 1 is true)--------------\n\n";
	std::cout << "is " << a << " greater than " << b << "? " << (a > b) << std::endl;
	std::cout << "is " << a << " less than " << b << "? " << (a < b) << std::endl;
	std::cout << "is " << a << " greater than " << c << "? " << (a > c) << std::endl;
	std::cout << "is " << a << " greater than or equal to " << b << "? " << (a >= b) << std::endl;
	std::cout << "is " << a << " greater than or eqaul to " << c << "? " << (a >= c) << std::endl;
	std::cout << "is " << a << " less than or equal to " << b << "? " << (a <= b) << std::endl;
	std::cout << "is " << a << " less than or eqaul to " << c << "? " << (a <= c) << std::endl;
	std::cout << "is " << a << " equal to " << b << "? " << (a = b) << std::endl;
	std::cout << "is " << a << " equal to " << c << "? " << (a = c) << std::endl;
	std::cout << "is " << a << " not equal to " << b << "? " << (a != b) << std::endl;
	std::cout << "is " << a << " not equal to " << c << "? " << (a != c) << std::endl;

}