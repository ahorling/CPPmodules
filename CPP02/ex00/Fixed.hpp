/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 15:43:19 by ahorling      #+#    #+#                 */
/*   Updated: 2023/06/16 18:48:29 by ahorling      ########   odam.nl         */
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
	Fixed(Fixed const &t);
	Fixed &operator=(Fixed const &other);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif