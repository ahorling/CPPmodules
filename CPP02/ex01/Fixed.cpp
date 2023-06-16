/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 15:53:08 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/16 19:08:58 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = other;
}

Fixed::Fixed(int const numint)
{
	std::cout << "Int constructor called" << std::endl;
	value = numint << bits;
}

Fixed::Fixed(float const numfloat)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(numfloat * (1 << bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = other.getRawBits();
	return(*this);
}

int Fixed::getRawBits(void) const
{
	return(value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

int	Fixed::toInt(void) const
{
	return (value >> bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)value / (float)(1 << bits));
}

std::ostream	&operator<<(std::ostream &o, Fixed const &right)
{
	o << right.toFloat();
	return (o);
}