/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contacts.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 19:57:31 by ahorling      #+#    #+#                 */
/*   Updated: 2023/05/31 21:53:14 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <string>

class Contacts
{
private:
	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	number;
	std::string	secret;
public:
	Contacts();
	~Contacts();
	int		index;
	bool	filled;
	void	set_contact(int n);
	void	print_contact();
	void	print_list();
};

#endif