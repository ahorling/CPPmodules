/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 15:43:19 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/16 19:37:59 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>

class	Fixed
{
private:
	int					value;
	static const int	bits = 8;
public:
	Fixed();
	Fixed(int const numint);
	Fixed(float const numfloat);
	Fixed(Fixed const &other);
	~Fixed();
	bool	operator>(Fixed const &right) const;
	bool	operator<(Fixed const &right) const;
	bool	operator>=(Fixed const &right) const;
	bool	operator<=(Fixed const &right) const;
	bool	operator==(Fixed const &right) const;
	bool	operator!=(Fixed const &right) const;
	Fixed	operator+(Fixed const &right) const;
	Fixed	operator-(Fixed const &right) const;
	Fixed	operator*(Fixed const &right) const;
	Fixed	operator/(Fixed const &right) const;
	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed	&operator=(Fixed const &right);
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(Fixed const &a, Fixed const &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(Fixed const &a, Fixed const &b);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};

std::ostream	&operator<<(std::ostream &o, Fixed const &right);

#endif