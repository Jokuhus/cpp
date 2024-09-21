#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>
#include <climits>
#include <cmath>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	if (this != &obj)
		return ;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	if (this != &obj)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert(const std::string& input)
{
	double	value;
	char	*ptr;

	ptr = 0;
	value = strtod(input.c_str(), &ptr);
	if ((value == 0.0 && \
		(input[0] != '-' && input[0] != '+' && !std::isdigit(input[0]))) || \
		(*ptr && strcmp(ptr, "f")))
	{
		std::cerr << "error: convert: incorrect argument form" << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible\n";
	else if (std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'\n";
	else
		std::cout << "Non displayable\n";

	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << "\n";

	std::cout << "float: ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "float: " << std::showpos << static_cast<float>(value) << "f\n";
	else if (static_cast<float>(value) == static_cast<int64_t>(static_cast<float>(value)))
		std::cout << static_cast<float>(value) << ".0f\n";
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10)\
				  << static_cast<float>(value) << "f\n";

	std::cout << "double: ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "double: " << static_cast<double>(value) << "\n";
	else if (static_cast<double>(value) == static_cast<int64_t>(static_cast<double>(value)))
		std::cout << static_cast<double>(value) << ".0\n";
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10)\
				  << static_cast<double>(value) << "\n";
}
