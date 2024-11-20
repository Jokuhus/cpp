#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cfloat>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::SetData()
{
	std::ifstream	file("data.csv");
	std::string		line;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			insertData(line);
		}
		file.close();
	}
	else
	{
		throw	BitcoinExchange::CouldNotOpenFile();
	}
	if (_data.size() == 0)
		throw BitcoinExchange::WrongDataForm();
}

void	BitcoinExchange::Convert(std::string input) const
{
	std::string		line;
	std::string		date;
	std::ifstream	file(input);

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			try
			{
				printResult(line);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " <<e.what() << '\n';
			}
			
		}
		file.close();
	}
	else
		throw	BitcoinExchange::CouldNotOpenFile();
}

void	BitcoinExchange::insertData(std::string& line)
{
	if (line == "date,exchange_rate")
		return;

	std::stringstream	ssLine(line);
	std::string			sDate;
	std::string			sPrice;

	std::getline(ssLine, sDate, ',');
	std::getline(ssLine, sPrice);

	if (checkDate(sDate))
		throw	BitcoinExchange::WrongDataForm();
	float	fPrice = checkPrice(sPrice);

	_data.insert(make_pair(sDate, fPrice));
}

void	BitcoinExchange::printResult(const std::string& line) const
{
	if (line == "date | value")
		return;

	std::string	date;
	std::string	value;
	float		price;

	if (ifInvalidInput(line, date, value))
		return ;
	price = calculatePrice(date, value);
	std::cout << date << " => " << value << " = " << price << std::endl;
}

bool	BitcoinExchange::ifInvalidInput(const std::string& line, std::string& date, std::string& value) const
{
	std::stringstream	ss(line);

	if (std::getline(ss, date, '|'))
		std::getline(ss, value);

	date = trimString(date);
	value = trimString(value);

	if (date.size() == 0 || value.size() == 0)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	}
	if (checkDate(date))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return 1;
	}
	if (checkValue(value))
		return 1;

	return 0;
}

float	BitcoinExchange::calculatePrice(const std::string& date, const std::string& value) const
{
	float	fValue = strtof(value.c_str(), NULL);
	float	fPrice = (fValue * findPrice(date));

	return fPrice;
}

bool	BitcoinExchange::checkDate(const std::string& date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return 1;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return 1;
	}

	int	year = std::stoi(date.substr(0, 4));
	int	month = std::stoi(date.substr(5, 2));
	int	day = std::stoi(date.substr(8, 2));

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return 1;

	const int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int			maxDays = daysInMonth[month - 1];

	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400)))
	{
		maxDays = 29;
	}
	if (day > maxDays)
		return 1;
	return 0;
}

float	BitcoinExchange::checkPrice(const std::string& sPrice) const
{
	std::stringstream	ss(sPrice);
	float				fPrice = 0;
	char				c;

	ss >> fPrice;
	if (ss.fail() || ss >> c || fPrice < 0 || fPrice == FLT_MAX)
	{
		throw	BitcoinExchange::WrongDataForm();
	}
	return fPrice;
}

bool	BitcoinExchange::checkValue(const std::string& value) const
{
	std::stringstream	ss(value);
	float				fPrice = 0;
	char				c;

	ss >> fPrice;
	if (ss.fail() || ss >> c)
	{
		std::cerr << "Error: bad input => "  << value << std::endl;
		return 1;
	}
	else if (fPrice < 0)
	{
		throw	BitcoinExchange::NotPositiveNumber();
	}
	else if (fPrice == FLT_MAX || fPrice > 1000)
	{
		throw	BitcoinExchange::TooLargeNumber();
	}
	return 0;
}

std::string	BitcoinExchange::trimString(std::string& str) const
{
	const char	WHITESPACES[] = {" \n\t\r\v\f\b"};
	std::string::size_type	begin = str.find_first_not_of(WHITESPACES);
	std::string::size_type	end = str.find_last_not_of(WHITESPACES);

	if (begin != std::string::npos)
		str = str.substr(begin, end + 1 - begin);
	return str;
}

float	BitcoinExchange::findPrice(const std::string& date) const
{
	std::map<std::string, float>::const_iterator	it = _data.upper_bound(date);

	if (it == _data.end())
		return _data.rbegin()->second;
	else if (it == _data.begin())
		throw	BitcoinExchange::TooEarlyDate();
	--it;
	return it->second;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	*this = obj;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	if (this != &obj)
	{
		_data = obj._data;
	}
	return *this;
}

const char*	BitcoinExchange::WrongDataForm::what() const throw()
{
	return "wrong data format.";
}

const char*	BitcoinExchange::CouldNotOpenFile::what() const throw()
{
	return "could not open file.";
}

const char*	BitcoinExchange::NotPositiveNumber::what() const throw()
{
	return "not a positive number.";
}

const char*	BitcoinExchange::TooLargeNumber::what() const throw()
{
	return "too large a number.";
}

const char*	BitcoinExchange::TooEarlyDate::what() const throw()
{
	return "too early date.";
}
