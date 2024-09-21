#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	// ScalarConverter	scaler;
	if (argc != 2)
		std::cerr << "error: convert: wrong argument number" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return (0);
}
