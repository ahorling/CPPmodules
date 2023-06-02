/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 19:53:20 by ahorling      #+#    #+#                 */
/*   Updated: 2023/05/31 20:37:36 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contacts.hpp"

class PhoneBook
{
private:
	Contacts contact[8];
	int	contact_num;
public:
	PhoneBook(int curent_contact);
	~PhoneBook();
	void	set_contact();
	void	search_contact();
};

#endif