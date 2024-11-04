#include <iostream>
#include <string>
#include <limits>
#include <exception>
#include <cmath>
#include <cstdint>
#include "ScalarConverter.hpp"

bool digits(std::string input)
{
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		if (std::isdigit(*it) == 0)
			return (false);
	}
	return (true);
}

bool checkInt(std::string input)
{
	if (input.empty() || ((input[0] == '-' && input.size() == 1) || (input[0] == '+' && input.size() == 1)))
		return (false);
	if (!((input.size() >= 2 && input[0] == '-' && digits(input.substr(1))) || digits(input)))
		return (false);

	try {
		std::stoi(input);
	} catch (const std::invalid_argument &e) {
		return (false);
	} catch (const std::out_of_range &e) {
		return (false);
	}
	return(true);
}

bool checkFloat(const std::string &input)
{
	if (input.empty())
		return (false);
	if (input == "inff" || input == "+inff" || input == "-inff" || input == "nanf")
		return (true);
	
	bool decimal = false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if ((i == 0 && (input[i] == '-' || input[i] == '+')) && input.length() > 1)
		{
			continue;
		}
		else if (input[i] == '.')
		{
			if (decimal == true)
				return(false);
			decimal = true;
		}
		else if (!std::isdigit(input[i]))
		{
			if (input[i] == 'f' && i == input.length() - 1)
				return (true);
			return (false);
		}
	}
	return (false);
}

bool	checkDouble(const std::string &input)
{
	if (input.empty())
		return (false);
	if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
		return (true);

	bool decimal = false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if ((i == 0 && (input[i] == '-' || input[i] == '+')) && input.length() > 1)
			continue;
		else if (input[i] == '.')
		{
			if (decimal == true)
				return(false);
			decimal = true;
		}
		else if (std::isdigit(input[i]) == 0)
			return(false);
	}
	return (true);
}

bool	checkChar(const std::string &input)
{
	if (input.empty())
		return (false);
	if (input.length() == 1)
	{
		int c = input.c_str()[0];
		if (c >= 32 && c <= 127)
			return (true);
	}
	return (false);
}

void	convertInt(const std::string &input)
{
	int Inted = std::stoi(input);
	try {
		char c = static_cast<char>(Inted);
		if (Inted > 127)
			std::cout << "char: number too high, causes overflow" << std::endl;
		else if (Inted < 0)
			std::cout << "char: number too low, causes underflow" << std::endl;
		else if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}

	std::cout << "int: " << Inted << std::endl;

	try {
		std::cout << "float: " << Inted << ".0f" << std::endl;
	} catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}

	try {
		std:: cout << "double: " << Inted << ".0" << std::endl;
	} catch (std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

void	convertChar(const std::string &input)
{
	char c = input[0];

	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	try {
		int Inted = static_cast<int>(c);
		std::cout << "int: " << Inted << std::endl;
	} catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}

	try {
		int Floated = static_cast<float>(c);
		std::cout << "float: " << Floated << ".0f" << std::endl;
	} catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}

	try {
		int Doubled = static_cast<double>(c);
		std::cout << "double: " << Doubled << ".0" << std::endl;
	} catch (std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

std::string cutEndingZeros(const std::string &input)
{
	size_t decimalPos = input.find_last_of('.');
	size_t endPos = input.find_last_not_of('0');

	if (endPos == std::string::npos || (decimalPos != std::string::npos && endPos < decimalPos))
		return (input);
	
	return (input.substr(0, ++endPos));
}

void	convertFloat(const std::string &input)
{
	try{
		double Floated = std::stof(input);
	try {
		char c = static_cast<char>(Floated);
		if (input == "nanf")
			std::cout << "char: impossible" << std::endl;
		else if (Floated > 127)
			std::cout << "char: number too high, causes overflow" << std::endl;
		else if (Floated < 0)
			std::cout << "char: number too low, causes underflow" << std::endl;
		else if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}

	try {
		int Inted = static_cast<int>(Floated);
		if (input == "nanf")
			std::cout << "int: impossible" << std::endl;
		else if (Floated > static_cast<float>(INT32_MAX) || (Inted < 0 && Floated > 0.0f))
			std::cout << "int: number too high, causes overflow" << std::endl;
		else if (Floated < static_cast<float>(INT32_MIN) || (Inted > 0 && Floated < 0.0f))
			std::cout << "int: number too low, underflow" << std::endl;
		else
			std::cout << "int: " << Inted << std::endl;
	} catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}

	std::string floatString = cutEndingZeros(std::to_string(Floated));
	if (floatString.back() == '.')
		std::cout << "float: " << floatString << "0f" << std::endl;
	else
		std::cout << "float: " << floatString <<  "f" << std::endl;
	
	try {
		double Doubled = static_cast<double>(Floated);
		std::string doubleString = cutEndingZeros(std::to_string(Doubled));
		if (doubleString.back() == '.')
			std::cout << "double: " << doubleString << "0" << std::endl;
		else
			std::cout << "double: " << doubleString << std::endl;
	} catch (std::exception &e) {
		std::cout << "double : " << e.what() << std::endl;
	}
	
	} catch (std::exception &e) {
		std::cout << "number not valid for any of the 4 options" << std::endl;
	}
}

void convertDouble(const std::string &input)
{
	try{
		double Doubled = std::stof(input);

	try {
		char c = static_cast<char>(Doubled);
		if (input == "nan")
			std::cout << "char: impossible" << std::endl;
		else if (Doubled > 127)
			std::cout << "char: number too high, causes overflow" << std::endl;
		else if (Doubled < 0)
			std::cout << "char: number too low, causes underflow" << std::endl;
		else if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}

	try {
		int Inted = static_cast<int>(Doubled);
		if (input == "nan")
			std::cout << "int: impossible" << std::endl;
		else if (Doubled > static_cast<double>(INT32_MAX) || (Inted < 0 && Doubled > 0.0))
			std::cout << "int: number too high, causes overflow" << std::endl;
		else if (Doubled < static_cast<double>(INT32_MIN) || (Inted > 0 && Doubled < 0.0))
			std::cout << "int: number too low, underflow" << std::endl;
		else
			std::cout << "int: " << Inted << std::endl;
	} catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}

	try {
		float Floated = static_cast<float>(Doubled);
		std::string floatString = cutEndingZeros(std::to_string(Floated));
		if (floatString.back() == '.')
			std::cout << "float: " << floatString << "0f" << std::endl;
		else
			std::cout << "float: " << floatString <<  "f" << std::endl;
	} catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}

	std::string doubleString = cutEndingZeros(std::to_string(Doubled));
	if (doubleString.back() == '.')
		std::cout << "double: " << doubleString << "0" << std::endl;
	else
		std::cout << "double: " << doubleString << std::endl;

	} catch (std::exception &e) {
		std::cout << "number not valid for any of the 4 options" << std::endl;
	}
}


static int findType(const std::string &input)
{
	if (checkInt(input) == true)
		return(INT);
	else if (checkFloat(input) == true)
		return(FLOAT);
	else if (checkDouble(input) == true)
		return(DOUBLE);
	else if (checkChar(input) == true)
		return (CHAR);
	else
		return(-1);
}

void Converter::convert(const std::string &input)
{
	int type = findType(input);
	switch (type)
	{
		case INT:
			convertInt(input);
			break;
		case FLOAT:
			convertFloat(input);
			break;
		case DOUBLE:
			convertDouble(input);
			break;
		case CHAR:
			convertChar(input);
			break;
		default:
			std::cout << "Error finding the type of input, please use actual numbers or single characters";
			break;
	}
}