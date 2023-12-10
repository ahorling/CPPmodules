#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class M>
void display(M info)
{
	std::cout << info << std::endl;
}

template <class A, class S>
void iter(A *array, S arrayLen, void function(const A))
{
	for (int i = 0; i < arrayLen; i++)
		function(array[i]);
	
}

#endif
