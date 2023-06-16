/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 15:43:19 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/16 19:08:56 by ahorling      ########   odam.nl         */
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
	Fixed &operator=(Fixed const &other);
	~Fixed();
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};

std::ostream	&operator<<(std::ostream &o, Fixed const &right);

#endif