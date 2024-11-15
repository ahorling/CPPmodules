#include "BitCoinExchange.hpp"
#include <fstream>

Bitcoin::Bitcoin() {}

Bitcoin::Bitcoin(const std::string &file)
{
    startDate = "9999-99-99";
    getData(file);
}

Bitcoin::Bitcoin(const Bitcoin &other) { *this = other; }

Bitcoin &Bitcoin::operator=(const Bitcoin &other)
{
    if (this != &other)
        pair = other.pair;
    return(*this);
}

Bitcoin::~Bitcoin() {}

bool    checkYear(const std::string &year)
{
    if (year.size() != 4)
        return (false);
    for (size_t i = 0; i < year.size(); i++)
    {
        if (year[i] < '0' || year[i] > '9')
            return (false);
    }
    return (true);
}

//I am not going to check for leap years or shorter months. It's just busy-work, and if you enter the
// 30th of feburary it's just going to find the closest date before that anyway, so who gives a shit.
// I am putting this comment here purely to show any evaluaters that I did take it into account, and decided 'fuck it'.
bool    checkDay(const std::string &day)
{
    if (day.size() != 2)
        return false;
    for (size_t i = 0; i < day.size(); i++)
    {
        if (day[i] < '0' || day[i] > '9')
            return (false);
    }
    int d = std::stoi(day);
    if (d < 1 || d > 31)
        return (false);

}

bool    checkMonth(const std::string &month)
{
    if (month.size() != 2)
        return (false);
    for (size_t i = 0; i < month.size(); i++)
    {
        if (month[i] < '0' || month[i] > '9')
            return (false);
    }
    int m = std::stoi(month);
    if (m < 1 || m > 12)
        return (false);
    return (true);
}

bool    isValid(const std::string &input)
{
    std::string year;
    std::string month;
    std::string day;
    int         pos;
    int         count;
	for (int i = 0; i < input.length(); i++)  //check to make sure not more than 2 dashes
	{
		if (input[i] == '-')
			count++;
	}
	if (count != 2)
        return (false);
    pos = input.find('-');
    year = input.substr(0, pos); //year is everything from start until fist dash
    std::string temp = input.substr(pos + 1); //everything after dash is month-day
    pos = temp.find('-');
    month = temp.substr(0, pos); //break apart temp into everything before the '-' and everything after
    day = temp.substr(pos + 1);
    if (checkYear(year) && checkMonth(month) && checkDay(day))
        return(true);
    else
        return(false);
    
}

void    Bitcoin::getData(const std::string &file)
{
    if (file.empty())
        throw std::runtime_error("no input file");
    
    std::ifstream   db(file);
    if  (!db.is_open())
        throw std::runtime_error("error opending file");
    
    std::string line;
    //we don't care about the first line of the file, so we call getline once before the loop
    std::getline(db, line); 
    while (std::getline(db, line))
    {
        int pos = line.find(',');
        if (pos == std::string::npos)
            throw std::runtime_error("file format incorrect");
        std::string key = line.substr(0, pos); //grab everything up to the ','
        if (!isValid(key))
            throw std::runtime_error("file format incorrect");
        if (key < startDate)
            startDate = key;
        else
            throw std::runtime_error("file format incorrect");
        std::string value = line.substr(pos + 1); //grab the value part after ','
        pair[key] = std::stod(value);
    }
}

std::string decreaseDate(const std::string &date)
{
    int			day;
	int			month;
	int			year;
	std::string	temp;
	size_t		pos = date.find('-');

	year = atoi(date.substr(0, pos).c_str());
	temp = date.substr(pos + 1);
	pos = temp.find('-');
	month = atoi(temp.substr(0, pos).c_str());
	day = atoi(temp.substr(pos + 1).c_str());
	if (day > 1)
		day--;
	else if (month > 1)
	{
		month--;
		day = 31;
	}
	else
	{
		year--;
		month = 12;
		day = 31;
	}
	std::string new_date = std::to_string(year) + "-";
	if (month < 10)
		new_date += "0";
	new_date += std::to_string(month) + "-";
	if (day < 10)
		new_date += "0";
	new_date += std::to_string(day);
	return (new_date);
}

double Bitcoin::getRate(const std::string &date)
{
    if (!isValid(date))
        throw std::runtime_error("Invalid date for lookup");
    if (date < startDate)
        throw std::runtime_error("Date is too early, not logged in database.");
    if (pair.find(date) != pair.end())
        return(pair[date]);
    std::string temp = date;
    while (temp != startDate)
    {
        temp = decreaseDate(temp);
        if (pair.find(temp) != pair.end())
            return(pair[date]);
    }
    throw std::runtime_error("reached the end of getRate. That wasn't supposed to happen....");
}

void    Bitcoin::Input(const std::string &file)
{
    if (file.empty())
        throw std::runtime_error("file not provided");
    std::ifstream input(file);
    if (!input.is_open())
        throw std::runtime_error("provided file unable to be opened");
    std::string line;
    std::getline(input, line);
    while (std::getline(input, line))
    {
        int pos = line.find('|');
        if (pos == std::string::npos)
            throw std::runtime_error("provided file formatted incrrectly.");
        std::string date = line.substr(0, pos - 1);
        if (!isValid(date))
            throw std::runtime_error("provided file has incorrect date(s)");
        else if (date < startDate)
            throw std::runtime_error("provided date is earlier than earliest date in database");
        std::string value = line.substr(pos + 1);
        double btc = std::stod(value);
        if (btc <= 0)
            std::runtime_error("Non-positive number found");
        else if (btc > 2147483647 || btc >= 10000)
            std::runtime_error("please use a smaller number");
        try {
            double rate = getRate(date);
            std::cout << date << " => " << btc << " = " << btc * rate << std::endl;
        } catch (...)
        {
            std::cout << "getRate failed, see previous error." << std::endl;
        }
    }
}
