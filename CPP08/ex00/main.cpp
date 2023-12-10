#include <list>
#include <iostream>
#include "easyfind.hpp"
#include <array>

int main(void)
{
	std::list<int> myList;

	myList.push_back(1);
	myList.push_back(3);
	myList.push_back(15);
	myList.push_back(13);

	try
	{
		::easyfind(myList, 15);
	}
	catch (...)
	{
		std::cout << "Exception caught!" << std::endl;
	}
	try
	{
		::easyfind(myList, 12);
	}
	catch (...)
	{
		std::cout << "Exception caught!" << std::endl;
	}

	std::array<int, 5> myArray = {12, 14, 16, 18, 21};
	try
	{
		::easyfind(myArray, 16);
	}
	catch(...)
	{
		std::cout << "Exception caught!" << std::endl;
	}
	try
	{
		::easyfind(myArray, 22);
	}
	catch(...)
	{
		std::cout << "Exception caught!" << std::endl;
	}
	
}