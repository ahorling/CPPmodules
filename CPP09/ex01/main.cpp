#include <stack>
#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "You probably forgot to put quotation marks around the input." << std::endl;
		return (-1);
	}
	try {
		RPN solve;
		solve.calc(argv[1]);
	} catch (...) {
		return (-1);
	}
	return(0);
}