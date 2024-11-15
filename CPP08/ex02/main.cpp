#include <iostream>
#include "MutantStack.hpp"
#include <stack>
#include <list>

int main()
{
	std::cout << "MUTANTSTACK TESTS:" << std::endl;

	MutantStack<int> mutant;
	mutant.push(4);
	std::cout << mutant.top() << std::endl;
	mutant.push(2);
	std::cout << mutant.top() << std::endl;
	std::cout << mutant.size() << std::endl;
	mutant.push(12);
	mutant.push(42);
	mutant.push(101);
	MutantStack<int>::iterator itbegin = mutant.begin();
	MutantStack<int>::iterator itend = mstack.end();
	while (itbegin != itend)
	{
		std::cout << "itbegin: " << *itbegin << ", itend: " << *itend << std::endl;
		itbegin++;
		itend++;
	}
	std::stack<int> normalstack(mutant);

	std::cout << "STD::LIST TESTS:" << std::endl;

	std::list<int> list;
	list.push_back(4);
	std::cout << list.back() << std::endl;
	list.push_back(2);
	std::cout << list.back() << std::endl;
	std::cout << list.size() << std::endl;
	list.push_back(12);
	list.push_back(42);
	list.push_back(101);
	std::list<int>::iterator itlistbegin = list.begin();
	std::list<int>::iterator itlistend = list.end();
	while (itlistbegin != itlistend)
	{
		std::cout << "itlistbegin: " << *itlistbegin << ", itlistend: " << *itlistend << std::endl;
		itlistbegin++;
		itlistend++;
	}
	return(0);
}