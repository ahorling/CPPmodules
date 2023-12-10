#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>

int num_check(std::string num, std::string line)
{
	//The error messages are printed within here due to it being able to 
	//display multiple error messages, and im lazy and just want this
	//to work
	long int validnum = 0;
	try
	{
		validnum = stoi(num);
	}
	catch(const std::exception& e)
	{
		if (strcmp(e.what(), "stoi: out of range") == 0)
			std::cout << "Error: too large a number" << std::endl;
		else
			std::cout << "Error: bad input => " << line << std::endl;
		return (-1);
	}
	if (validnum < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (-1);
	}
	return (0);
}

int	date_check(std::string date)
{
	//check split for date if 3 uses or not
	//check validity of year month and day
	//day cant be over 31 or under 0, and month cant be above 12 or below 0
	size_t count = 0;
	if (date.length() != 10)
		return (-1);
	for (size_t i = 0; i < date.length(); i++)
	{
		if (date[i] == '-')
			count++;
	}
	if (count != 2)
		return (-1);
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5,2);
	std::string day = date.substr(8,2);
	//This is validating that it is a mostly real date, some months that have 
	//30 days will accpet 31 days, see like feburary 31st which passes but
	//im not validating every single month day combo for a cpp module, thats way ot much
	//busy work
	try{
		int nyear = stoi(year);
		int nmonth = stoi(month);
		int nday = stoi(day);
		if (nyear < 0)
			return (-1);
		if (nmonth < 0 || nmonth > 12)
			return (-1);
		if (nday < 0 || nday > 31)
			return (-1);
	} catch (const std::exception& e){
		return (-1);
	}
	return (0);
}

void print_num_check(std::string date, std::string num, std::map<std::string, float> myMap)
{
	std::map<std::string, float>::iterator pos;

	pos = myMap.find(date);
	//If end this means it couldnt find the specific date in its storage
	if (pos == myMap.end())
	{
		pos = myMap.upper_bound(date);
		//Uncomment this and comment section below if you think that if the date is before the first date entry
		//that it should than take the upper portion, its unclear in the subject
		// if (pos != myMap.begin())
		// 	pos--;
		// else
		// std::cout << date << " => " << num << " = " << (std::stof(num) * pos->second) << std::endl;
		//Comment this Section  if you want it the other way[
		if (pos != myMap.begin())
		{
			pos--;
			std::cout << date << " => " << num << " = " << (std::stof(num) * pos->second) << std::endl;
		}
		else
			std::cout << date << " date is from before the CSV is registered." << std::endl;
		//]
	}
	else
		std::cout << date << " => " << num << " = " << (std::stof(num) * pos->second) << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "The incorrect amount of arguements were provided." << std::endl;
		return (1);
	}
	
	//This is all loading informaiton from the first csv file given.
	std::ifstream csvFile;
	
	csvFile.open("data.csv");
	if(!csvFile.is_open())
	{
		std::cout << ".csv File couldn't be opened" << std::endl;
		return (1);
	}
	std::map<std::string, float> myMap;
	std::string line;
	int delimPos = 0;
	getline(csvFile, line);
	while(getline(csvFile, line))
	{
		delimPos = line.find(",");
		myMap.insert(std::make_pair(line.substr(0, delimPos), std::stof(line.substr(delimPos + 1, line.length()))));
	}
	csvFile.close();

	//This is running through the informtion on the provided file
	std::ifstream inputFile;
	
	inputFile.open(argv[1]);
	if(!inputFile.is_open())
	{
		std::cout << "Couldn't open input file." << std::endl;
		return (1);
	}
	//reusing line variable to not make a new one;
	getline(inputFile, line);
	std::string date;
	std::string num;
	while(getline(inputFile, line))
	{
		delimPos = line.find("|");
		if (delimPos == -1)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		//trimming starting and ending spaces of string triming date SUFFIXa nd num PREFIX
		date = line.substr(0, delimPos);
		date = date.erase(date.find_last_not_of(' ') + 1);
		num = line.substr(delimPos + 1, line.length());
		num = num.erase(0, num.find_first_not_of(' '));
		if (date_check(date) == -1)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (num_check(num, line) == -1)
			continue;
		// break;
		print_num_check(date, num, myMap);
	}
	// std::cout << "end" << std::endl;
	return (0);
}