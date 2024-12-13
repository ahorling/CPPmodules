#include <iostream>
#include "set"
#include "vector"
#include "deque"
#include <chrono>
#include <algorithm>

//Why do i need a PmergeMe.cpp?
//Wouldn't a {container1.cpp} and {container2.cpp} make more sense?
//I dont even need a .hpp, might as well just do this class-less
//Seriously, I get the concept behind this module but damn the setup is weird.

/* ------------------------------------------------------------------------------*/


//print functions for debugging stuff
void printPairs(const std::vector<std::vector<int>>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "(" << vec[i][0] << ", " << vec[i][1] << ")";
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void printVector(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------/

//function to generate a specific jacobsthal number to be used with the binary search section.
size_t jacobsthal(size_t n)
{
	size_t ret;

	if ( n <= 1)
		return (n);
	ret = jacobsthal(n - 1) + (2 * jacobsthal(n - 2));
	return (ret);
}

bool	comp(int &a, int &b)
{
	if (a > b)
		return (true);
	else
		return (false);
}

//splits the given vector and retuns the front half
std::vector<int> vecSplitFront(std::vector<int> &array)
{
	std::vector<int> ret;

	for (int i = 0; i < array.size() / 2; i++)
		ret.push_back(array[i]);
	
	return (ret);
}

//splits the given vector and returns back half
std::vector<int> vecSplitBack(std::vector<int> &array)
{
	std::vector<int> ret;

	for (int i = array.size() / 2; i < array.size(); i++)
		ret.push_back(array[i]);

	return (ret);
}

//recursively figures out where a value is supposed to be and inserts it there
void vecInsert(std::vector<std::vector<int>> &pair, std::vector<int> toInsert, int left, int right)
{
	if (left >= right)
	{
		pair.insert(pair.begin() + left, toInsert);
		return;
	}
	int middle = (right - left)/2 + left;
	if (toInsert[0] > pair[middle][0])
		vecInsert(pair, toInsert, middle + 1, right);
	else
		vecInsert(pair, toInsert, left, middle);
}

//using hte jacobsthal number generated in jacobsthal_insert, does the actual insertion part of the algorithm
void	insertInOrder(std::vector<std::vector<int>> &src, std::vector<std::vector<int>> &dst, size_t index, size_t jacob, std::vector<int> &straggler)
{
	for (int i = 0; jacob > index + i; i++)
	{
		if (index + i < src.size())
			dst.push_back(vecSplitFront(src[index + i]));
	}

	int insertPos = dst.size() - 1;

	for (int i = 1; jacob - i >= index; i++)
	{
		if (jacob > src.size() && !straggler.empty())
		{
			vecInsert(dst, straggler, 0, dst.size());
			straggler.clear();
			insertPos++;
		}
		if (jacob - i < src.size())
			vecInsert(dst, vecSplitBack(src[jacob - i]), 0 , insertPos);
	}
}

//insert the numbers buy calling the insertInOrder function for every jacobsthal number smaller than the number of pairs.
void	jacobsthal_insert(std::vector<std::vector<int>> &src, std::vector<std::vector<int>> &dst, std::vector<int> straggler = {})
{
	size_t currentJacob;
	size_t prevJacob = 1; 
	size_t i = 3; //jacobsthal really starts from 3rd instance, so setting previous to 1 and the position in sequence to 3

	//so long as there are pairs in the source, or the stragger is still around (because it is always done last), insert the number in order
	while(prevJacob < src.size() || !straggler.empty())
	{
		currentJacob = jacobsthal(i);
		insertInOrder(src, dst, prevJacob, currentJacob, straggler);
		i++;
		prevJacob = currentJacob;
	}
}

std::vector<int> vecMerge(std::vector<int> a, const std::vector<int> b)
{
	for (int i : b)
		a.push_back(i);
	return (a);
}

//Pairs up the given pair of vectors into further pairs, unil no more can be made, then start the bullshit.
std::vector<std::vector<int>> vecMergeInsert(std::vector<std::vector<int>> input)
{
	std::vector<std::vector<int>> pairedVec;

	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (comp(input[i][0], input[i + 1][0]))
			pairedVec.push_back(vecMerge(input[i], input[i + 1]));
		else
			pairedVec.push_back(vecMerge(input[i + 1], input[i]));
	}

	if (pairedVec.size() > 1)
		pairedVec = vecMergeInsert(pairedVec);

	std::vector<std::vector<int>> ret;

	ret.push_back(vecSplitFront(pairedVec[0]));
	ret.push_back(vecSplitBack(pairedVec[0]));

	if (input.size() % 2 != 0)
		jacobsthal_insert(pairedVec, ret, input.back());
	else
		jacobsthal_insert(pairedVec, ret);
	
	return(ret);
}

//change the input array into a vector of vectors, setting up the pairing section of Merge-Insert, and converts the pairs into a single vector again.
std::vector<int> vecSort(std::vector<int> input)
{
	std::vector<std::vector<int>> preppedVec;
	std::vector<int> ret;

	for (size_t i = 0; i < input.size(); i++)
		preppedVec.push_back(std::vector<int>{input[i]});
	preppedVec = vecMergeInsert(preppedVec);
	for (std::vector<int> pair : preppedVec)
	{
		for (int n : pair)
			ret.push_back(n);
	}
	return (ret);
} 

//----------------------------- Vector break point-----------------------------

int		main(int argc, char *argv[])
{
	std::vector<int>	vec;
	std::deque<int>	deq;
	std::set<int>	dupecheck;

	if (argc < 2)
	{
		std::cout << "Please provide atleast 2 arguments" << std::endl;
		return (1);
	}
	else if (argc < 3)
	{
		std::cout << "This is a sorting algorithm. Why are we sorting less than 1 item?" << std::endl;
		return (1);
	}

	//check for dupes and add numbers to the containers one by one.
	for (int i = 1; i < argc; i++)
	{
		int n = atoi(argv[i]);
		if (dupecheck.find(n) != dupecheck.end())
		{
			std::cout << "We do not like duplicates, please make sure all inputs are unique integers." << std::endl;
			return (-1);
		}
		dupecheck.insert(n);
		vec.push_back(n);
		deq.push_back(n);
	}

	//print out the first few numbers
	std::cout << "Before: ";
	for (int i = 0; i < vec.size(); i++)
	{
		if (i > 4)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	//do the sort for the vector and time it
	auto start = std::chrono::high_resolution_clock::now();
	vec = vecSort(vec);
	printVector(vec);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> vecTime = end - start;
	return(0);
}