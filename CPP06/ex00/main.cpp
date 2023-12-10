#include <iostream>
#include <string.h>

enum type 
{
	c_type = 0,
	i_type,
	f_type,
	d_type,
};

bool check_float(std::string input)
{
	if (input == "+inff" || input == "inff")
		return (true);
	if (input == "-inff")
		return (true);
	if (input == "nanf")
		return (true);
	if (input.find("f") != std::string::npos)
		return (true);
	return (false);
}

bool check_double(std::string input)
{
	if (input == "+inf" || input == "inf")
		return (true);
	if (input == "-inf")
		return (true);
	if (input == "nan")
		return (true);
	if (input.find(".") != std::string::npos)
		return (true);
	return (false);
}

bool check_char(std::string input)
{
	if (input[1] != '\0')
		return (false);
	return (true);
}

int	check_data_type(std::string input)
{
	if (check_char(input) == true)
		return (c_type);
	if (check_double(input) == true)
		return (d_type);
	if (check_float(input) == true)
		return (f_type);
	return (i_type);
}

void	handle_ctype(std::string input)
{
	char character;

	character = input[0];
	if (character >= 32 && character <= 126)
		std::cout << "char: '" << character << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(character) << std::endl;
	std::cout << "float: " << static_cast<float>(character) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(character) <<".0" <<  std::endl;
}

void	handle_itype(std::string input)
{
	int a;
	try
	{
		a = stoi(input);
	}
	catch (...)
	{
		std::cout << "This is none of the options available!" << std::endl;
		return ;
	}
	if (a >= 32 && a <= 126)
		std::cout << "char: '" << static_cast<char>(a) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << a << std::endl;
	std::cout << "float: " << static_cast<float>(a) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) <<".0" <<  std::endl;
}

void	handle_dtype(std::string input)
{
	double d;
	try
	{
		d = stod(input);
	}
	catch(...)
	{
		std::cout << "Double Conversion Failed!" << std::endl;
		return ;
	}
	if (input == "+inf" || input == "-inf" || input == "nan" || input == "inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d <<  std::endl;
		return ;
	}
	if (d >= 32 && d <= 126)
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" <<  std::endl;	
}

void	handle_ftype(std::string input)
{
	float f;
	try
	{
		f = static_cast<float>(stod(input));
	}
	catch(...)
	{
		std::cout << "Float Conversion Failed!" << std::endl;
		return ;
	}
	if (input == "+inff" || input == "-inff" || input == "nanf" || input == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) <<  std::endl;
		return ;
	}
	if (f >= 32 && f <= 126)
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << ".0" <<  std::endl;	
}

void	handle_data_type(int type, std::string input)
{
	if (type == c_type)
		handle_ctype(input);
	if (type == i_type)
		handle_itype(input);
	if (type == d_type)
		handle_dtype(input);
	if (type == f_type)
		handle_ftype(input);
}

int main(int argc, char *argv[])
{
	std::string input;
	int a = -     1;
	if (argc != 2)
	{
		std::cout << "Only two arguements!" << std::endl;
		return (0);
	}
	handle_data_type(check_data_type(argv[1]), argv[1]);
	return (0);
}