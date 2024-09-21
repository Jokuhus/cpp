#include <iostream>
#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc > 2)
	{
		std::cerr << "error: too many arguments" << std::endl;
		return (0);
	}
	Harl	Harl;

	if (argc == 1)
		Harl.complain("DEBUG");
	else
		Harl.complain(argv[1]);
}