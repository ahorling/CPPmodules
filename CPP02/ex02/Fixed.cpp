/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 15:53:08 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/16 20:25:04 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(Fixed const &other)
{
	*this = other;
}

Fixed::Fixed(int const numint)
{
	value = numint << bits;
}

Fixed::Fixed(float const numfloat)
{
	value = roundf(numfloat * (1 << bits));
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(Fixed const &other)
{
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

bool	Fixed::operator>(Fixed const &right) const
{
	return (value > right.getRawBits());
}

bool	Fixed::operator<(Fixed const &right) const
{
	return (value < right.getRawBits());
}

bool	Fixed::operator>=(Fixed const &right) const
{
	return (value >= right.getRawBits());
}

bool	Fixed::operator<=(Fixed const &right) const
{
	return (value <= right.getRawBits());
}

bool	Fixed::operator==(Fixed const &right) const
{
	return (value == right.getRawBits());
}

bool	Fixed::operator!=(Fixed const &right) const
{
	return (value != right.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &right) const
{
	return (Fixed(toFloat() + right.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &right) const
{
	return (Fixed(toFloat() - right.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &right) const
{
	return (Fixed(toFloat() * right.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &right) const
{
	if (right.toFloat() == 0)
		throw std::runtime_error("Please don't divide by zero. It hurts the computer.");
	return (Fixed(toFloat() / right.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	value++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	
	value++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	value--;
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}