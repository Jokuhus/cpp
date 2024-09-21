#include <fstream>
#include <iostream>
#include <string>
#include "replaceString.hpp"

int	check_input(int argc, char *argv[])
{
	std::string	s;

	if (argc != 4)
	{
		std::cerr << "error: wrong number of argument" << std::endl;
		return (1);
	}
	s = argv[1];
	if (!s.size())
	{
		std::cerr << "error: filename required" << std::endl;
		return (1);
	}
	s = argv[2];
	if (!s.size())
	{
		std::cerr << "error: string to be replaced required" << std::endl;
		return (1);
	}
	else if (s.find_first_of('\n', 0) != s.npos)
	{
		std::cerr << "error: new line cannot be replaced" << std::endl;
		return (1);
	}
	s = argv[3];
	if (!s.size())
	{
		std::cerr << "error: string replace to required" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (check_input(argc, argv))
		return (1);
	replaceString	rs(argv[2], argv[3]);
	std::ifstream	in(argv[1]);
	if (!in.is_open())
	{
		std::cerr << "error: " << argv[1] << ": cannot open file" << std::endl;
		return (1);
	}
	std::ofstream	out((std::string)argv[1] + ".replace");
	if (!out.is_open())
	{
		std::cerr << "error: " << argv[1] << ".replace: cannot open file" << std::endl;
		return (1);
	}
	rs.replaceFile(in, out);
	return (0);
}

