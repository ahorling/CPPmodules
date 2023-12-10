#include <iostream>
#include "PmergeMe.hpp"
#include "set"
#include "vector"
#include <ctime>

//Why can't i hand in more .c files, why do i need a PmergeMe.cpp
//Why cant have a {container1.cpp} and {container2.cpp}
//I dont even need a .hpp according to these rules, whats a class gonna do
int		exit_non_valid_number(char *number)
{
	std::string strnum(number);
	int num = 0;
	try{
		num = stoi(strnum);
	}
	catch (...){
		std::cout << "Invalid number conversation: " << strnum << std::endl;
		exit(1);
	}
	if (num < 0)
	{
		std::cout << "Negative number submitted: " << strnum << std::endl;
		exit(1);
	}
	return (num);
}

std::set<int>	zip_sets(std::set<int> leftSet, std::set<int> rightSet)
{
	std::set<int>			rvalue;
	std::set<int>::iterator leftIt = leftSet.begin();
	std::set<int>::iterator rightIt = rightSet.begin();

	while(leftIt != leftSet.end() && rightIt != rightSet.end())
	{
		if (*leftIt < *rightIt)
		{
			rvalue.insert(*leftIt);
			leftIt++;
		}
		else
		{
			rvalue.insert(*rightIt);
			rightIt++;
		}
	}
	while (leftIt != leftSet.end())
	{
		rvalue.insert(*leftIt);
		leftIt++;
	}
	while (rightIt != rightSet.end())
	{
		rvalue.insert(*rightIt);
		rightIt++;
	}
	return (rvalue);
}

void print_before(char *argv[])
{
	std::cout << "Before:	";
	for (int i = 1; argv[i]; i++)
		std::cout << " " << argv[i];
	std::cout << std::endl;
}

std::set<int>	sort_mySet(std::set<int> mySet)
{
	int size = mySet.size();
	if (size == 1)
		return (mySet);
	std::set<int> leftSet;
	std::set<int> rightSet;
	std::set<int>::iterator it = mySet.begin();
	for(int i = 0; i < (size/2); i++)
	{
		leftSet.insert(*it);
		it++;
	}
	for (int i = (size/2); i < size; i++)
	{
		rightSet.insert(*it);
		it++;
	}
	leftSet = sort_mySet(leftSet);
	rightSet = sort_mySet(rightSet);
	return (zip_sets(leftSet, rightSet));
}

void	print_set(std::set<int> mySet)
{
	std::set<int>::iterator it = mySet.begin();
	std::cout << "After:	";
	while (it != mySet.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	set_sort(int argc, char *argv[])
{
	clock_t start = clock();
	std::set<int> mySet;
	for (int i = 1; i < argc; i++)
	{
		int input =exit_non_valid_number(argv[i]);
		//The management of errors related to duplicates is left to your
		//discretion. : I am choosing to exit upon duplicates.
		if (mySet.count(input) != 0)
		{
			std::cout << "Duplicate input detected :" << input << std::endl;
			exit(1); 
		}
		mySet.insert(input);
	}
	clock_t input_end = clock() - start;
	mySet = sort_mySet(mySet);
	clock_t sort_end = clock() - start;
	print_before(argv);
	print_set(mySet);
	printf("mySet:Input time: %fs || Sort Time: %fs\n", (float(input_end)/CLOCKS_PER_SEC), (float(sort_end)/CLOCKS_PER_SEC));
}

//I have to use two different containers, not two different merge sort implentetations, its a pretty copy carbon paste.""
std::vector<int> zip_vectors(std::vector<int> leftVector, std::vector<int> rightVector)
{
	std::vector<int>			rvalue;
	std::vector<int>::iterator leftIt = leftVector.begin();
	std::vector<int>::iterator rightIt = rightVector.begin();

	while(leftIt != leftVector.end() && rightIt != rightVector.end())
	{
		if (*leftIt < *rightIt)
		{
			rvalue.push_back(*leftIt);
			leftIt++;
		}
		else
		{
			rvalue.push_back(*rightIt);
			rightIt++;
		}
	}
	while (leftIt != leftVector.end())
	{
		rvalue.push_back(*leftIt);
		leftIt++;
	}
	while (rightIt != rightVector.end())
	{
		rvalue.push_back(*rightIt);
		rightIt++;
	}
	return (rvalue);
}

std::vector<int> sort_myVector(std::vector<int> myVector)
{
	int size = myVector.size();
	if (size == 1)
		return (myVector);
	std::vector<int> leftVector;
	std::vector<int> rightVector;
	for (int i = 0; i < (size/2); i++)
		leftVector.push_back(myVector[i]);
	for (int i = (size/2); i < size; i++)
		rightVector.push_back(myVector[i]);
	leftVector = sort_myVector(leftVector);
	rightVector = sort_myVector(rightVector);
	return (zip_vectors(leftVector, rightVector));
}

// void	print_vector(std::vector<int> myVector)
// {
// 	for (size_t i = 0; i < myVector.size(); i++)
// 		std::cout << myVector[i] << " ";
// 	std::cout << std::endl;
// }
void	vector_sort(int argc, char *argv[])
{
	clock_t start = clock();
	std::vector<int> myVector;
	for (int i = 1; i < argc; i++)
	{
		int input = exit_non_valid_number(argv[i]);
		//Number duplicate check isn't needed here as mySet checks for duplicates before hand.
		//Can also check duplicates before both if really wanted too, mostly a time save since i hate working on cpp modules
		myVector.push_back(input);
	}
	// print_vector(myVector);
	clock_t input_end = clock() - start;
	myVector = sort_myVector(myVector);
	clock_t sort_end = clock() - start;
	printf("myVector:Input time: %f || Sort Time: %f\n", (float(input_end)/CLOCKS_PER_SEC), (float(sort_end)/CLOCKS_PER_SEC));
	// print_vector(myVector);
}

int		main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Please provide atleast 2 arguments" << std::endl;
		return (1);
	}
	else if (argc < 3)
	{
		std::cout << "This is a sorting algorithm... why are we sorting less than 1 item" << std::endl;
		return (1);
	}
	set_sort(argc, argv);
	vector_sort(argc, argv);
	// (void)argv;
	// clock_t start = clock();
	// clock_t end = clock() - start;
	// printf("It took [%fs]\n", (float(end)/CLOCKS_PER_SEC));
	// std::cout << "It took: " << (float(end))/CLOCKS_PER_SEC << std::endl;
	// std::cout << start << std::endl;
}