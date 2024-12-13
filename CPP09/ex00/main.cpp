#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string.h>
#include "BitCoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "improper input" << std::endl;
		return (-1);
	}
	try {
		Bitcoin btc("data.csv");
		btc.Input(argv[1]);
	} catch (const std::runtime_error &error) {
		std::cout << "Error: " << error.what() << std::endl;
		return (-1);
	}
	return (0);
}