#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return 1;
	}

	BitcoinExchange	bit;

	try
	{
		bit.SetData();
		bit.Convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return 0;
}
