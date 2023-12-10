#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <class t>
void	easyfind(t &myList, int to_search)
{
	if (std::find(myList.begin(), myList.end(), to_search) == myList.end())
		throw std::exception();
	std::cout << "Found it! " << to_search << std::endl;
}
#endif
