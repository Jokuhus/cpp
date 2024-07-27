#include <iostream>
#include "Harl.hpp"

int	main(void)
{
	Harl	Harl;

	std::cout << "[DEBUG]" << std::endl;
	Harl.complain("DEBUG");
	std::cout << "[INFO]" << std::endl;
	Harl.complain("INFO");
	std::cout << "[WARNING]" << std::endl;
	Harl.complain("WARNING");
	std::cout << "[ERROR]" << std::endl;
	Harl.complain("ERROR");
	return (0);
}