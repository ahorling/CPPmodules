/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 16:00:13 by ahorling      #+#    #+#                 */
/*   Updated: 2023/07/22 16:30:10 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(Brain const &src);

	~Brain();
	
	Brain &operator = (Brain const &right);
	
	std::string	getIdea(int i) const;
	void	setIdea(int i, std::string Idea);

	std::string showIdeas() const;
};

#endif