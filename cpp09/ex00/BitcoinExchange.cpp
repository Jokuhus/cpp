#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>
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
	float			value;
	float			price;
	std::ifstream	file(input);

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (line == "date | value")
				continue;
			try
			{
				printResult(line);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << '\n';
			}
		}
		file.close();
	}
}

void	BitcoinExchange::insertData(std::string& line)
{
	if (line == "date,exchange_rate")
		return;

	std::stringstream	s_line(line);
	std::string			date;
	std::string			price;

	std::getline(s_line, date, ',');
	std::getline(s_line, price, '')

	std::string::size_type	pos = line.find(',');
	if (pos == std::string::npos)
		throw	BitcoinExchange::WrongDataForm();

	std::string	date = line.substr(0, pos + 1);
	checkDate(date);

	std::string	price = line.substr(pos + 1);
	float	f_price = checkPrice(price);

	_data.insert(make_pair(date, f_price));
}

void	BitcoinExchange::printResult(const std::string& line) const
{
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

	std::getline(ss, date, '|');
	std::getline(ss, value);

	date = trimString(date);
	value = trimString(value);

	if (date.size() == 0 || value.size() == 0)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return 1;
	}

	if (checkDate(date))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return 1;
	}
	if (checkValue(value))
		return 1;

	return 0;
}

float	BitcoinExchange::calculatePrice(const std::string& date, const std::string& value) const
{
	float	f_value = strtof(value.c_str(), NULL);
	float	price = (f_value * findPrice(date));

	return price;
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

bool	BitcoinExchange::checkValue(const std::string& value) const
{
	std::stringstream	ss(value);
	float				f_value;

	if (!(ss >> f_value))
	{
		std::cout << "Error: bad input => " << value << std::endl;
		return 1;
	}

	char	leftover;
	if (ss >> leftover)
	{
		std::cout << "Error: bad input => " << value << std::endl;
		return 1;
	}

	if (f_value < 0)
		throw NotPositiveNumber();
	else if (f_value > 1000)
		throw TooLargeNumber();

	return 0;
}

std::string	BitcoinExchange::trimString(std::string& str) const
{
	const char	WHITESPACES[] = {" \n\t\r\v\f\b"};
	std::string::size_type	begin = str.find_first_not_of(WHITESPACES);
	std::string::size_type	end = str.find_last_not_of(WHITESPACES);

	str = str.substr(begin, end);
	return str;
}

float	BitcoinExchange::findPrice(const std::string& date) const
{
	std::map<std::string, float>::const_iterator	it = _data.upper_bound(date);

	if (it == _data.end())
		return _data.rbegin()->second;
	--it;
	return it->second;
}

std::string	BitcoinExchange::trimDateData(std::string& line) const
{
	std::string::size_type	end = line.find(',');
	if (end == std::string::npos)
		throw WrongDataForm();

	std::string	date = line.substr(0, )
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
